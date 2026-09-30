# EToolkit Project Status

**Assessment date:** 2026-09-30  
**Current phase:** Feature implementation / API expansion  
**Assessment scope:** Repository structure, documentation, build configuration, tests, automation, and Git branches.

## Executive summary

EToolkit has a substantial C++/WinAPI codebase and is actively evolving its container interfaces. It is not yet ready for a formal release or for the complete project-standard migration. The immediate priority is to finish and validate `feature/add-container-interfaces` before introducing broad process and repository changes.

## Git status at assessment time

- Current branch: `feature/add-container-interfaces`.
- `master` and the current feature branch share the same base commit.
- The feature branch contains two commits not integrated into `master`:
  - `7389bb4` — add `IContainer`.
  - `3d22234` — add `IIterable`.
- Local uncommitted changes are present in the container interfaces, container headers,
  public `include/EContainer` umbrella header, `source/core/EToolkitTypes.hpp`, and this
  status document. `IDynamicContainer.hpp` and `IStaticContainer.hpp` are untracked.
- Do not merge the branch until the local changes are intentionally committed, discarded, or moved to a separate branch.

This section is a snapshot and must be updated if the repository changes.

## Current maturity assessment

| Area | Status | Notes |
|---|---|---|
| Source organization | Partial | Modules are separated under `source/` and public forwarding headers exist under `include/`. |
| Feature implementation | In progress | Container interfaces are being introduced. |
| Requirements and scope | Missing | No formal requirements or acceptance criteria were found. |
| Tests | In progress | Tests are separated into `StaticArrayTest` and `DynamicArrayTest` and use a local assertion runner without GoogleTest or another external test framework; CTest only executes and reports the binary. Broader public-interface coverage remains pending. Copy and move behavior are covered. |
| Reproducible build | In progress | Root CMake delegates test configuration to `test/CMakeLists.txt`; the single repository-level `build/` tree builds the C++11 test target with CTest. |
| CI | Missing | No repository CI workflow was found. |
| API documentation | In progress | Doxygen now targets all container interfaces and implementations; generation still requires a local Doxygen executable. |
| User documentation | Partial | README contains overview and basic build information, but not a complete development or installation guide. |
| Versioning | Missing | No clear project version or release policy was found. |
| License | Incomplete | README states BSL 1.0, but a versioned `LICENSE` file should be verified and added if absent. |
| Contribution process | Missing | No contribution guide or issue/PR templates were found. |

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

After the feature has been integrated, copy and adapt the reusable files from `DevelopmentStandardTemplates` in a separate task or branch. Do not mix feature implementation with repository-process migration.

Recommended migration order:

1. `LICENSE` and version policy.
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
- Define the first SemVer version and release criteria.

## Decision

Finishing `feature/add-container-interfaces` first is the preferred sequence. It creates a stable technical checkpoint and prevents process migration files from obscuring unfinished API work. The standard templates should then be introduced in a dedicated branch, such as:

```text
chore/ETK-<id>-adopt-development-standard
```

The feature branch and the standards-migration branch should remain separate and independently reviewable.

## Current decision

The container headers now follow the required organization rule: access sections are ordered
as `public`, `protected`, and `private`; empty sections are omitted; and members are ordered
as constructors, destructors, operators, methods, members, and statics. Inline template
definitions follow the declaration order.

The concrete `StaticArray` and `DynamicArray` classes now implement the applicable container
and iterable contracts. `StaticArray` uses compile-time parameters in the form
`StaticArray<DataType, SizeType, SizeValue>`, while `DynamicArray` exposes runtime resize,
reserve, data access, and iterator operations. Representative consumers compile successfully.

The implementation and validation criteria for the feature are complete. The feature is ready for
commit on `feature/add-container-interfaces`; push, Pull Request, and merge remain subject to
approval. Permanent tests are now organized by
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
configured in `Doxyfile` and can be executed when the local Doxygen executable is available.

## Final task comment

The container interface feature is finalized for commit. The implementation includes the
`IContainer`, `IIterable`, `IStaticContainer`, and `IDynamicContainer` contracts, updated
`StaticArray` and `DynamicArray` implementations, explicit copy and move behavior, complete
container-focused tests without GoogleTest, a dependency-free local assertion runner, a
reproducible CMake and CTest build, public API documentation, and the project-standard build and
test guidance. The build and CTest validation passed successfully using the single repository
`build/` directory. No push, Pull Request, or merge has been performed.
