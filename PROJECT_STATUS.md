# EToolkit Project Status

**Assessment date:** 2026-11-11  
**Current phase:** Main branch initial setup
**Assessment scope:** Baseline source, build, test, automation, and governance files before first remote `main` push.

## Executive summary

EToolkit is being initialized on `main` as the primary development branch. The immediate goal is to
publish a complete baseline commit to remote `main`, switch the default branch on GitHub, and then
start regular development flow with feature branches targeting `main`.

## Git status at assessment time

- Current local baseline branch: `main` (before first remote publish).
- Primary branch marker file: `BRANCH` set to `main`.
- Workflows are configured to run from and validate `main`.
- Next action is to publish `main` and switch the GitHub default branch.

This section is a snapshot and must be updated if the repository changes.

## Current maturity assessment

| Area | Status | Notes |
|---|---|---|
| Source organization | Initial setup | Implementation source modules will be added after baseline publish. |
| Feature implementation | Not started | Functional code is intentionally deferred to follow-up development branches. |
| Requirements and scope | Defined | Baseline governance and planning documents are tracked in the repository root. |
| Tests | Initial setup | Automated workflow hooks are present; implementation test suites are added with feature work. |
| Reproducible build | Initial setup | Root CMake baseline validates configuration and workflow integration. |
| CI | Implemented | `.github/workflows/ci.yml` validates Pull Requests/pushes to `main` and manual runs on Windows with MSYS2, CMake, Ninja, build, and CTest. |
| API documentation | Implemented | Doxygen targets the public headers and source API; GitHub Actions publishes HTML to GitHub Pages and exposes PR builds as review artifacts. |
| User documentation | Initial setup | README and governance documents describe setup and planned delivery flow. |
| Versioning | Implemented | Version source is currently `0.0.0`; the first eligible push to `main` automatically creates the non-release baseline tag `v0.0.0`, and subsequent reviewed Conventional Commits merged into that branch can create approved tags. |
| Release packaging | Implemented | `release.yml` validates SemVer tags, rebuilds/tests the tagged revision, packages Windows artifacts, calculates SHA-256 checksums, and publishes a GitHub Release. |
| License | Implemented | Repository baseline includes `LICENSE` with BSL 1.0 text. |
| Contribution process | Implemented | Branching, commit, and review standards are documented before feature development starts. |

## Immediate plan

1. Create the first baseline commit on local `main`.
2. Push `main` to `origin`.
3. Change the GitHub default branch to `main`.
4. Validate CI/Doxygen/Pages/version workflows after the default-branch transition.
5. Start normal development with feature branches and pull requests targeting `main`.

## Acceptance for bootstrap completion

- `BRANCH` contains `main`.
- `LICENSE` exists and matches BSL 1.0.
- Root docs reference `main` for workflow and governance flow.
- First remote `main` push completes required checks.
