# Implementation plan

## Change

- Title: Automation standards and release pipeline
- Related files: `.github/workflows/`, `VERSION`, `CMakeLists.txt`, `Doxyfile.in`
- Target: `0.0.0` baseline

## Desired state

Pull Requests are validated, documentation is previewed or published, the first baseline tag is
created automatically, and later approved SemVer tags produce tested Windows release artifacts.

## Work breakdown

| ID | Task | Evidence | Status |
|---|---|---|---|
| T-001 | Centralize version in `VERSION` | Clean CMake configure | done |
| T-002 | Add CI and Doxygen workflows | Actions runs | done |
| T-003 | Add baseline and SemVer automation | Tags and workflow logs | done |
| T-004 | Add tagged release packaging | GitHub Release and checksum | done |
| T-005 | Verify first GitHub Actions execution | Successful run | pending |

## Validation

Run CMake build and CTest locally, then validate all workflows on GitHub Actions before publishing a
non-baseline release.
