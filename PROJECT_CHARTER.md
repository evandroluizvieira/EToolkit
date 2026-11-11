# Project Charter

## Project identity

- Project name: `EToolkit`
- Repository: https://github.com/evandroluizvieira/EToolkit
- Status: active
- Initial development version: `0.0.0`

## Vision

Provide a maintainable C++11 Win32 toolkit with reusable APIs, reproducible builds, automated tests,
and traceable documentation and releases.

## Scope

### In scope

- C++11 Win32 library abstractions;
- shared and static library builds;
- API-consuming examples;
- automated tests and Doxygen documentation;
- tagged Windows release artifacts.

### Out of scope

- GitHub Packages until a package format and consumer contract are approved;
- non-Windows runtime support unless explicitly added to the roadmap.

## Governance

Changes are reviewed through Pull Requests. CI is required before merge. Versioning and releases use
Conventional Commits, SemVer, immutable tags, and the workflows documented in `RELEASE.md`.
