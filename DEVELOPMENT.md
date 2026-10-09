# Local development

## Naming and identifiers

Use the complete project name in source identifiers, build targets, package names, workflow names,
branch names, paths, and documentation. Do not invent abbreviations or acronyms for internal use;
for example, use `EToolkit` rather than `ETK`. An abbreviation is acceptable only when required by
an established external standard or tool, and the project must document the exception.

## Prerequisites

- Operating system: Windows
- Language/runtime: C++11
- Compiler or tool: MSYS2 MinGW-w64 at `C:/msys64/mingw64`, CMake 3.16 or newer, and Ninja
- Dependencies: Windows SDK and the Win32 libraries used by the project

## Setup

```text
cmake -S . -B build -G Ninja
```

## Build

Use one repository-level, out-of-source build directory. Do not create separate build folders
inside `test/`, and do not create a second directory such as `build-tests/` for the same build
configuration. Test binaries and test metadata belong below the shared build directory, usually
under `build/test/`.

```text
cmake --build build
```

The repository produces both shared and static variants of the `EToolkit` library from `source/`.
On Windows, the shared variant is a DLL with its import library. Small API-consuming examples live
under `applications/` and are built as separate executables. With a multi-configuration generator,
Debug and Release outputs belong under `build/Debug/` and `build/Release/`; never create parallel
root-level build directories.

In VS Code, press `F7` or run `EToolkit: Build all`. The workspace build task first configures the
root `build/` directory with tests, applications, and both library variants enabled, then builds
the CMake `all` target. This generates the shared library and its import library, the static
library, the test executable, and the applications under `applications/`. The library itself does
not generate an executable because it has no `main()` function. The build does not run anything.

To execute something with `F5`, select a configuration from the Run and Debug selector:

- `EToolkit: Run tests` executes the container test executable.
- `EToolkit: Run simple_window` executes the basic window application.

The `F5` configurations only execute the selected binary; they do not build or configure the
project. Run `F7` first whenever the source or build configuration has changed. Additional
applications should add another configuration to `.vscode/launch.json`.

## Tests

Keep test source files under `test/` or the equivalent project test directory. Keep generated
test binaries, CTest metadata, coverage files, and temporary test output under the shared build
directory; never commit them.

When practical, organize tests by production class or component. A dependency-free local test
runner may be used when an external framework is not justified. It should provide at least:

- independent test classes or suites;
- explicit test method declarations;
- assertion failures with file and line information;
- non-zero process status on failure;
- integration with the project's test discovery tool;
- separate coverage for normal, error, boundary, const-correctness, and iteration behavior.

CTest and GoogleTest are different tools. CTest is a test discovery and execution tool distributed
with CMake; it does not provide assertions or a test framework. GoogleTest is an assertion and
test framework library. A project using a local runner can register its executable with CTest
without depending on GoogleTest. State this distinction in the project documentation.

The `etoolkit_public_api_compatibility` target uses `EColorTest.cpp` to provide a consumer-level compatibility check. It must
include public forwarding headers, link through the supported `EToolkit` target, exercise a small
representative API surface, and be registered with CTest. This check is intentionally separate
from component-level tests so that public include and link regressions are detected explicitly.

For C++ tests, document test classes, test methods, assertion utilities, and entry points with
multiline Doxygen blocks immediately above declarations or signatures. Do not place test
documentation comments inside test method bodies. Avoid unexplained abbreviations in public test
names, helper names, diagnostics, and documentation.

```text
ctest --test-dir build --output-on-failure
```

## Quality

```text
clang-format --dry-run --Werror <changed C++ files>
clang-tidy -p build <changed C++ files>
```

## Automation and generated output

The CI workflow is defined in `.github/workflows/ci.yml` and validates the Windows-supported
toolchain. It runs for Pull Requests from every approved branch type targeting `master`, pushes to
`master`, and manual `workflow_dispatch` requests. Release, deployment, and documentation
publishing workflows remain separate from this validation workflow.

The CI job installs the MSYS2 MinGW-w64 toolchain, configures the project with CMake and Ninja,
builds shared and static libraries, applications, and `etoolkit_tests`, and runs CTest with
failure output enabled. The workflow grants only `contents: read`, uses concurrency cancellation
for superseded runs, and does not upload build output by default.

Release automation is defined in `.github/workflows/release.yml` and is intentionally separate from
CI. It accepts only approved tags matching `v<MAJOR>.<MINOR>.<PATCH>` (with `v*.*.*` as the Actions
glob filter), rebuilds and tests the tagged revision, verifies that `VERSION` matches the tag,
packages the DLL, libraries, headers, tests, and applications, calculates SHA-256 checksums, and
attaches the archive to a GitHub Release. It
does not publish artifacts for ordinary commits or Pull Requests.

Version automation is defined in `.github/workflows/auto-version.yml`. The current development
version is `0.0.0`; it is a baseline, not a published release. On the first eligible push to
`master` after this automation branch is merged, the workflow automatically creates the immutable
`v0.0.0` baseline tag without running the release workflow. Only subsequent pushes to `master` are
eligible for version calculation. The workflow then
examines Conventional Commits since the last release tag. `feat:` suggests a minor increment,
`fix:` suggests a patch increment, and `BREAKING CHANGE` or `!` suggests a major increment. The
workflow updates the central `VERSION` file, commits the result, and creates the tag. CMake reads
that file and configures Doxygen from `Doxyfile.in`; the README version badge reads published tags.
A `feature/` branch, Pull Request, or individual `feat:` commit does not create a version before
review and merge. If no SemVer baseline tag exists, the workflow creates `v0.0.0` once and does not
publish a release.

The repository must define a `RELEASE_TOKEN` secret with permission to push commits and tags. A
dedicated token is required because GitHub does not start downstream workflows for events generated
with the default `GITHUB_TOKEN`. The token must be protected and used only by the trusted default-
branch version workflow.

API documentation is validated by `.github/workflows/doxygen.yml` and published by
`.github/workflows/pages.yml`. The `VERSION` file is the authoritative version source; CMake
configures `Doxyfile.in` into `build/Doxyfile`, so Doxygen and the build use the same version. Pull
Requests from all approved branch types generate one Doxygen site as a downloadable Actions
artifact for review. Pushes to `master` and manual runs use the separate Pages workflow to publish
the generated HTML through GitHub Pages. The generated `docs/` directory remains ignored and is
never committed to the source repository.

GitHub Releases are downloadable versioned assets; GitHub Packages are registry entries consumed
through a package format such as NuGet or OCI. The project should automate Releases first and add
GitHub Packages only after defining a supported format, package coordinates, retention, and
installation instructions.

Document every additional workflow trigger in the project repository. Review `paths` and
`paths-ignore` filters whenever build, test, documentation, deployment, or workflow files change.

Keep generated output out of source control. Build directories, test binaries, generated Doxygen
files, coverage reports, caches, and temporary files belong in ignored paths or workflow artifacts.
Upload artifacts only when they are intentional review or release evidence, with explicit names,
retention, and `if-no-files-found` behavior. Do not use generated artifacts as source inputs unless
the workflow documents and verifies their provenance.

Review GitHub Actions permissions and third-party actions as executable code. Use the minimum
required token permissions, pin or otherwise govern external actions according to project policy,
and avoid privileged execution for untrusted Pull Request code.

Apply the structural rules in [CODE_STYLE.md](CODE_STYLE.md). In particular, keep access sections in `public`, `protected`, `private` order and keep declarations and definitions ordered by `Constructors`, `Destructors`, `Operators`, `Methods`, `Data members`, and `Static members`. This applies to inline implementations and implementations in separate source files.

## Running

```text
build/applications/simple_window/EToolkitSimpleWindow.exe
```

The exact executable location can vary by generator and configuration. The example creates an
empty window and serves as a minimal manual integration check for the application and window API.

## Debug

Describe how to start debugging and which variables, services, or data are required.

## Artifacts

The shared `build/` directory contains generated binaries, CTest metadata, and temporary build
files. These outputs are local validation artifacts and must not be committed. Release artifacts
must document their format, platform, architecture, configuration, provenance, and retention.

## Checklist local

- [ ] MinGW-w64, CMake, and Ninja available.
- [ ] One shared out-of-source build directory is used.
- [ ] Build completed.
- [ ] Tests executed.
- [ ] Test sources are separate from generated test artifacts.
- [ ] Test classes or suites cover the applicable production components.
- [ ] Test declarations and signatures have the required documentation.
- [ ] Formatter and linter executed.
- [ ] Class and interface member ordering reviewed against [CODE_STYLE.md](CODE_STYLE.md).
- [ ] Documentation updated.
- [ ] No secrets or generated files committed.
