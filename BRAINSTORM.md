# Brainstorm and discovery

## Current automation initiative

The initiative evaluates community-standard GitHub Actions, SemVer, Conventional Commits, Doxygen,
GitHub Pages, and GitHub Releases for EToolkit.

## Constraints

- Preserve C++11 and Windows/MSYS2 support.
- Keep CI, documentation, versioning, and release permissions separate.
- Do not enable GitHub Packages without a consumer contract.

## Selected direction

Use `VERSION` as the single source, automate the non-release `v0.0.0` baseline, and create later
releases only from reviewed SemVer tags.
