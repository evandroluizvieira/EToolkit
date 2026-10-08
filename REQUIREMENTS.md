# Requirements

## Status

- Version: `0.0.0`
- Status: active
- Owner: EToolkit maintainers
- Last updated: 2026-10-08

## Functional requirements

| ID | Requirement | Priority | Acceptance |
|---|---|---|---|
| FR-001 | Build shared and static EToolkit libraries with C++11. | Must | CI builds both targets. |
| FR-002 | Provide public headers under `include/`. | Must | Consumer examples compile. |
| FR-003 | Execute automated tests through CTest. | Must | CI reports passing tests. |
| FR-004 | Generate API documentation from public headers and source API. | Should | Doxygen workflow publishes HTML. |
| FR-005 | Publish reproducible artifacts from approved SemVer tags. | Should | Release workflow builds, tests, packages, and checksums artifacts. |

## Non-functional requirements

| ID | Area | Requirement | Measure |
|---|---|---|---|
| NFR-001 | Compatibility | Preserve C++11 support. | CMake standard is required and extensions are disabled. |
| NFR-002 | Reproducibility | Build from a clean tagged revision. | Release workflow checks out the tag. |
| NFR-003 | Security | Do not grant write permissions to Pull Request validation. | CI uses read-only contents permission. |

## Traceability

Requirements map to CMake targets, tests, Doxygen output, and GitHub Actions evidence.
