# Release process

## Pre-release

- [ ] All tasks for the version are complete.
- [ ] Changelog updated.
- [ ] Version updated in a single source of truth.
- [ ] Production build completed.
- [ ] Tests and static analysis passed.
- [ ] Documentation generated.
- [ ] Installation/artifacts validated.

## Identification

Use an immutable tag in the format `v<MAJOR>.<MINOR>.<PATCH>`. The initial development version is
`0.0.0`; the version workflow creates `v0.0.0` automatically on the first eligible push to
`master` after the automation branch is merged. This baseline is not published as a GitHub Release.
The first publishable release is created from a later approved version tag. The baseline is created
on the first push to `master` regardless of whether the push contains a release-worthy commit or
only documentation/configuration changes.

The repository's single version source is [VERSION](VERSION). CMake reads it directly, and Doxygen
receives the same value through [Doxyfile.in](Doxyfile.in). Do not edit a version literal in a
workflow, badge, build file, or documentation file.

The version workflow uses the protected `RELEASE_TOKEN` secret rather than the default
`GITHUB_TOKEN`, because GitHub does not trigger another workflow from events created by the default
token. This allows a newly created SemVer tag to start the release workflow. The token must have
only the minimum contents permission required to push the version commit and tag.

The first eligible push may create the non-publishing `v0.0.0` baseline with the default token. A
later release-worthy push requires `RELEASE_TOKEN`; without it, the workflow stops before creating
a version commit or tag. After a publishable tag such as `v0.0.1` or `v0.1.0` exists, `release.yml`
builds and tests the Windows package, generates a SHA-256 checksum, and publishes the ZIP and
checksum as a GitHub Release.

## Automation triggers

Release generation must not run for every Pull Request or arbitrary branch push. Prefer a reviewed
version tag such as `v1.2.3` and, when appropriate, an explicit `workflow_dispatch` trigger with
inputs for the version or target. Keep validation on Pull Requests and default-branch pushes
separate from packaging, publishing, documentation deployment, and release artifact generation.

Document the exact trigger, branch or tag restriction, required permissions, approval rules,
artifact retention, and rerun behavior for every release workflow. A workflow that generates
documentation, packages, installers, or release notes must state whether it uploads artifacts,
publishes a release, or only validates the generated output.

Generated output must be reproducible from the tagged source revision. Do not commit generated
build directories, test binaries, documentation output, caches, or temporary files unless the
project explicitly treats one of them as a versioned source artifact.

## EToolkit GitHub automation

The implemented workflow sequence is:

```text
Pull Request to master       -> CI: configure, build, and test
Push to master               -> CI: configure, build, and test
Successful version decision  -> `auto-version.yml` creates vX.Y.Z
Push of vX.Y.Z tag           -> `release.yml` packages and publishes assets
```

Validation remains separate from versioning and release workflows. After a push to `master`,
`auto-version.yml` uses Conventional Commits since the last tag to determine the next SemVer
increment: `fix:` produces a patch release, `feat:` produces a minor release, and `BREAKING CHANGE`
or `!` produces a major release; documentation, test, refactor, and chore commits do not publish a
release by themselves. A `feature/` branch or Pull Request never creates a version before merge.

The release workflow runs only for an approved SemVer tag or an explicitly approved manual
dispatch. It rebuilds from the tagged revision, runs CTest, calculates SHA-256 checksums, and
publishes a versioned Windows archive for the runtime DLL, development headers and libraries,
`etoolkit_tests.exe`, and example applications.

GitHub Releases and GitHub Packages are different delivery mechanisms. Releases are the initial
distribution channel for versioned ZIP archives and checksums. A GitHub Package should be added
only after a consumer format and registry are selected, such as NuGet or an OCI image.

Generated Doxygen HTML is published separately through GitHub Pages from the `master` branch. It
is documentation hosting, not a binary release asset or a GitHub Package, and is rebuilt by its own
workflow after source or documentation changes.

## Artifacts

Each artifact must identify the project, version, platform, architecture, compiler/runtime, and configuration.

## Publishing

Publish release notes, artifacts, and checksums. Use `contents: write` only in the release job; do
not give Pull Request workflows permission to publish releases or credentials.

## Post-release

- [ ] Install and test the published artifacts.
- [ ] Verify the published documentation.
- [ ] Record known issues.
- [ ] Create the next `Unreleased` entry.
- [ ] Define a rollback plan.
