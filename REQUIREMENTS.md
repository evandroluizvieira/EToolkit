# Requirements

## Status

- Version: `0.0.0`
- Status: active
- Owner: EToolkit maintainers
- Last updated: 2026-11-11

## Functional requirements

| Requirement | Priority | Acceptance |
|---|---|---|
| Build shared and static EToolkit libraries with C++11. | Must | CI builds both targets. |
| Provide public headers under `include/`. | Must | Consumer examples compile. |
| Execute automated tests through CTest. | Must | CI reports passing tests. |
| Generate API documentation from public headers and source API. | Should | Separate Doxygen validation and Pages publication workflows generate and publish HTML. |
| Publish reproducible artifacts from approved SemVer tags. | Should | Release workflow builds, tests, packages, and checksums artifacts. |

## Non-functional requirements

| Area | Requirement | Measure |
|---|---|---|
| Compatibility | Preserve C++11 support. | CMake standard is required and extensions are disabled. |
| Reproducibility | Build from a clean tagged revision. | Release workflow checks out the tag. |
| Security | Do not grant write permissions to Pull Request validation. | CI uses read-only contents permission. |

## Traceability

Requirements map to CMake targets, tests, Doxygen output, and GitHub Actions evidence. Tasks are
derived from `main` and tracked in branch-specific implementation and test updates.
