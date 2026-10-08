# Architecture

## Purpose

EToolkit is a C++11 Win32 library that provides reusable containers, geometry, controls, windows,
application, graphics, and utility abstractions. The repository also builds small API-consuming
applications and a dependency-free test executable.

## Components

| Component | Responsibility | Dependencies |
|---|---|---|
| `source/` | Library implementation | C++11 and Win32 libraries |
| `include/` | Public forwarding headers and API | Public library contracts |
| `applications/` | Manual integration examples | EToolkit library |
| `test/` | Automated unit tests | Local assertions and CTest |
| `.github/workflows/` | CI, documentation, versioning, and release automation | GitHub Actions |

## Build and delivery flow

CMake configures shared and static library targets, applications, tests, and a generated Doxygen
configuration. CI validates Pull Requests and `master`. Versioning reads `VERSION`; approved tags
trigger reproducible release packaging.

## Public interfaces

Public API is exposed through `include/`. API and ABI compatibility, supported Windows toolchains,
and C++11 requirements must be reviewed for public changes.

## Geometry hierarchy

Positions, sizes, and bounds use typed views over shared fixed-size storage. `Bounds1`, `Bounds2`,
and `Bounds3` preserve one shared `StaticArray` subobject and expose documented index mappings.

## Security and compatibility

Workflows use least-privilege permissions. Release artifacts are generated from immutable tags and
verified with SHA-256 checksums. Do not place secrets or generated output in source control.

## Decisions

Record architecture changes in `docs/adr/`.
