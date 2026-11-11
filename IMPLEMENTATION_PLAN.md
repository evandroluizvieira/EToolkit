# Implementation plan

## Objective

Establish `main` as the new primary branch baseline with complete source, build, test, workflow,
and governance files before beginning regular feature development.

## Scope

- Include full project source tree, tests, CMake configuration, and public headers.
- Include CI, documentation, version, and release workflows.
- Include root governance documentation aligned with current repository behavior.
- Exclude historical migration-only artifacts.

## Work breakdown

| ID | Task | Evidence | Status |
|---|---|---|---|
| B-001 | Build initial `main` baseline from project source | `git status` on unborn `main` | done |
| B-002 | Add explicit primary-branch marker (`BRANCH=main`) | `BRANCH` file in repository root | done |
| B-003 | Add BSL 1.0 `LICENSE` file | `LICENSE` present in repository root | done |
| B-004 | Remove migration checklist from baseline | File removal and README update | done |
| B-005 | Align docs for new-main bootstrap | Updated README and governance docs | done |
| B-006 | Push `main` and set GitHub default branch | GitHub settings and workflow runs | pending |

## Validation checklist

- Local build config succeeds.
- Local build succeeds.
- Local CTest run succeeds.
- First push to remote `main` triggers CI/documentation workflows.
- Repository default branch is switched to `main`.
