# EToolkit Project Status

**Assessment date:** 2026-10-01  
**Current phase:** Continuous integration
**Assessment scope:** Repository structure, documentation, build configuration, tests, automation, and Git branches.

## Executive summary

EToolkit has completed the container interface feature, which was merged into `master` through Pull Request #7. The current task is to adopt the reusable `ProjectStandards` documentation and collaboration conventions without modifying the completed container branch.

## Git status at assessment time

- Current branch: `ci/etoolkit-automation-standards`.
- Base branch: `master`, synchronized with `origin/master` after Pull Request #7.
- Completed container branch: `feature/add-container-interfaces`; no further changes are planned there.
- The CI branch adds the reusable Windows validation workflow and updates the project automation documentation.

This section is a snapshot and must be updated if the repository changes.

## Current maturity assessment

| Area | Status | Notes |
|---|---|---|
| Source organization | Partial | Modules are separated under `source/` and public forwarding headers exist under `include/`. |
| Feature implementation | Complete | Container interfaces and array tests were merged into `master` through Pull Request #7. |
| Requirements and scope | Missing | No formal requirements or acceptance criteria were found. |
| Tests | In progress | Tests are separated into `StaticArrayTest` and `DynamicArrayTest` and use a local assertion runner without GoogleTest or another external test framework; CTest executes and reports the suite plus a public API compatibility target covering representative graphics color types. Broader public-interface coverage remains pending. Copy and move behavior are covered. |
| Reproducible build | In progress | Root CMake builds shared and static `EToolkit` library variants, the C++11 test target, and API applications below one repository-level `build/` tree. Configuration succeeds; local compilation is currently blocked by Windows error 4551 when launching MinGW `c++.exe`. |
| CI | Implemented | `.github/workflows/ci.yml` validates Pull Requests targeting `master`, pushes to `master`, and manual runs on Windows with MSYS2, CMake, Ninja, build, and CTest. |
| API documentation | Implemented | Doxygen targets the public headers and source API; GitHub Actions publishes HTML to GitHub Pages and exposes PR builds as review artifacts. |
| User documentation | Partial | README contains overview and basic build information, but not a complete development or installation guide. |
| Versioning | Implemented | Version source is currently `0.0.0`; the first eligible push to `master` automatically creates the non-release baseline tag `v0.0.0`, and subsequent reviewed Conventional Commits merged into `master` can create approved tags. |
| Release packaging | Implemented | `release.yml` validates SemVer tags, rebuilds/tests the tagged revision, packages Windows artifacts, calculates SHA-256 checksums, and publishes a GitHub Release. |
| License | Incomplete | README states BSL 1.0, but a versioned `LICENSE` file should be verified and added if absent. |
| Contribution process | In progress | ProjectStandards documentation and Issue/PR templates are being adopted; local VS Code F7/F5 workflows are configured but ignored by Git. |

## Recommended order of work

### Phase 0 — Preserve the current work

1. Review the local diff in `EToolkitTypes.hpp`.
2. Review `IStaticContainer.hpp` for API, ownership, const-correctness, and naming consistency.
3. Decide whether these changes belong to the current feature.
4. Commit related work only after it is buildable, or move unrelated work to a separate branch.
5. Do not rewrite history or merge while the ownership of the local changes is unclear.

### Phase 1 — Finish `feature/add-container-interfaces`

Acceptance criteria:

- [x] `IContainer` API is reviewed and documented.
- [x] `IIterable` API is reviewed and documented.
- [x] `IStaticContainer` is complete or intentionally removed.
- [x] Existing containers are reviewed for compatibility and member-ordering consistency.
- [x] Existing containers inherit from and implement the applicable interfaces.
- [x] `EToolkitTypes.hpp` changes are intentional and documented.
- [x] Copy, move, comparison, size, data, clear, swap, empty, and iteration behavior is defined.
- [x] Const-correctness and virtual destructor behavior are verified.
- [x] Edge cases, including zero-size containers, are defined.
- [x] Permanent automated tests cover the public interface.
- [x] A reproducible local build succeeds.
- [x] Doxygen comments cover the new public API.
- [x] README or API documentation explains the new interfaces.
- [ ] Commits are separated into logical Conventional Commits and approved before creation.
- [ ] Pull Request description contains evidence of build and tests.

Suggested commit sequence:

```text
feat: add container base interface
feat: add iterable interface
feat: add static container interface
refactor: update toolkit type definitions
test: cover container interfaces
docs: document container interfaces
```

### Phase 2 — Integrate the feature

After the acceptance criteria pass:

1. Push the completed branch.
2. Open a Pull Request against `master`.
3. Review API, ABI, ownership, and compatibility impact.
4. Record build and test evidence.
5. Merge only after approval.
6. Confirm `master` builds after merge.
7. Delete the feature branch only after verification.

### Phase 3 — Adopt the project standard

After the feature was integrated, copy and adapt the reusable files from `ProjectStandards` in the dedicated branch `chore/etoolkit-adopt-project-standards`. Do not modify the completed container branch.

Recommended migration order:

1. ProjectStandards review and version policy.
2. `DEVELOPMENT.md` and reproducible build instructions.
3. `CONTRIBUTING.md`, issue templates, and Pull Request template.
4. `.editorconfig`, `.clang-format`, and `.clang-tidy`.
5. Test plan and automated tests.
6. CMake or another reproducible build entry point.
7. CI workflow.
8. Expanded Doxygen configuration.
9. `CHANGELOG.md`, release process, and packaging.

## Recommended follow-up tasks

- Create a formal project charter and requirements document.
- Define public API and compatibility policy.
- Add automated tests for containers and core utilities.
- Add a reproducible Windows build for supported compilers.
- Add installation and consumer-project validation.
- Expand Doxygen to all public headers.
- Add a real license file.
- Verify the first automated SemVer baseline and release criteria after merging the automation branch.

## Decision

Finishing `feature/add-container-interfaces` first created a stable technical checkpoint. The project standards are now being introduced in a dedicated branch:

```text
chore/etoolkit-adopt-project-standards
```

The completed feature branch and the standards-adoption branch remain separate and independently reviewable.

## Current decision

The container headers now follow the required organization rule: access sections are ordered
as `public`, `protected`, and `private`; empty sections are omitted; and members are ordered
as constructors, destructors, operators, methods, members, and statics. Inline template
definitions follow the declaration order.

The concrete `StaticArray` and `DynamicArray` classes now implement the applicable container
and iterable contracts. `StaticArray` uses compile-time parameters in the form
`StaticArray<DataType, SizeType, SizeValue>`, while `DynamicArray` exposes runtime resize,
reserve, data access, and iterator operations. Representative consumers compile successfully.

The implementation and validation criteria for the container feature are complete and the feature
was merged into `master` through Pull Request #7. Permanent tests are now organized by
production class in `test/StaticArrayTest.cpp` and `test/DynamicArrayTest.cpp`, using a small
local assertion runner without GoogleTest or other external test-framework dependencies. CTest is
used only as the runner and reporting tool supplied by CMake. The test declarations,
support utilities, and test entry point now use Doxygen without comments inside test bodies. The
test target has its own configuration in `test/CMakeLists.txt`. The target compiled and passed
CTest using only the repository-level `build/` directory; previous duplicate `build-tests/` and
`test/build/` directories were removed. A capacity edge case in `DynamicArray` was corrected so
shrinking never produces zero capacity. Copy and move construction and assignment are explicit
in both array implementations and are covered by the permanent tests. The Doxygen configuration
now covers all container interfaces and implementations, and the README explains the public
container API. Final diff cleanup remains outstanding; IntelliSense still requires configuration
of the local standard-library include paths. The apparent `git diff --check` whitespace reports
in the interface headers are caused by CRLF line endings; direct inspection found no trailing
spaces, and the check passes when `cr-at-eol` is enabled. `.gitattributes` now declares LF for
source, build, Markdown, and CMake files to prevent future ambiguity. Doxygen generation is
configured through `Doxyfile.in` and can be executed after CMake generates `build/Doxyfile` when the
local Doxygen executable is available.

## Standards adoption comment

The container interface feature is complete and merged. The standards-adoption branch now includes
the reusable development, contribution, code-style, definition-of-done, test-plan, release,
security, code-of-conduct, Pull Request, and Issue templates from `ProjectStandards`. The root CMake
project now builds the library, tests, and API applications from one `build/` tree. The VS Code
workflow uses `F7` for the complete build and `F5` only for the selected existing binary.
Remaining adoption work includes license verification, release-package installation validation,
GitHub Pages configuration verification, and additional platform validation.

## CI status

The automation workflows are implemented on the `ci/etoolkit-automation-standards` branch. It
uses `windows-latest` with MSYS2 MinGW-w64, configures CMake with Ninja, builds shared and static
libraries, applications, and the `etoolkit_tests` executable, then runs CTest. Pull Requests to
`master`, pushes to `master`, and manual `workflow_dispatch` runs use the same validation path.
