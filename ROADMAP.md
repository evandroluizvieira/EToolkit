# Roadmap

## Planning rules

The roadmap communicates direction and is not a release promise unless marked committed.

## Current priorities

| Priority | Initiative | Outcome | Status |
|---|---|---|---|
| P0 | Public API development | Build reusable, documented components with automated tests | active |
| P1 | Automation standards | CI, versioning, Doxygen, and tagged releases | active |
| P1 | API coverage | Broader public-interface tests and compatibility checks | active |
| P1 | Distribution | Evaluate a package-manager format | planned |
| P2 | Platform support | Assess non-Windows toolchains | planned |

## Milestones

### Automation baseline

- Goal: merge the automation standards branch and create the `v0.0.0` baseline automatically.
- Exit criteria: CI, documentation, versioning, and release workflows pass in GitHub Actions.

### Container base interface

- Goal: publish the first container contract (`IContainer`) with forwarding header and regression tests.
- Exit criteria: local build and CTest pass with `etoolkit_tests` in this branch scope.

## Completed

- Main branch baseline publication and default-branch transition to `main`.

### Public API consumer validation

- Goal: verify that an external consumer can include and link the public API through the supported
	CMake build.
- Exit criteria: the consumer validation target builds and passes through CTest in CI.
