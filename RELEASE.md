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

Use an immutable tag in the format `v<MAJOR>.<MINOR>.<PATCH>`.

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

## Artifacts

Each artifact must identify the project, version, platform, architecture, compiler/runtime, and configuration.

## Publishing

Publish release notes, artifacts, and checksums. Do not publish credentials in the repository or logs.

## Post-release

- [ ] Install and test the published artifacts.
- [ ] Verify the published documentation.
- [ ] Record known issues.
- [ ] Create the next `Unreleased` entry.
- [ ] Define a rollback plan.
