# Contributing

## Before you start

- Read [DEVELOPMENT.md](DEVELOPMENT.md).
- Check existing Issues.
- For larger changes, open an Issue before implementing.
- Do not include unrelated changes.

## Branches

Create each branch from the updated default branch:

- `feature/<project>-<id>-<description>`
- `fix/<project>-<id>-<description>`
- `refactor/<project>-<id>-<description>`
- `test/<project>-<id>-<description>`
- `docs/<project>-<id>-<description>`
- `build/<project>-<id>-<description>`
- `ci/<project>-<id>-<description>`
- `hotfix/<project>-<id>-<description>`

Use lowercase letters and hyphens, without spaces or accents. Avoid working directly on `<main-or-master>`.

Use the complete project name in branch names and internal identifiers; do not shorten it into an
abbreviation or acronym. For example, use `etoolkit` rather than `etk`. Preserve an abbreviation
only when it is imposed by an external tool or standard and the exception is documented.

## Commits

Use Conventional Commits. Examples:

- `feat: add export command`
- `fix: handle empty input`
- `test: cover parser errors`
- `docs: update usage guide`
- `ci: run tests on pull requests`

Each commit should represent one logical unit. Mark breaking changes with `!` or `BREAKING CHANGE:` in the body.

## Pull Request

The PR should explain the problem, solution, validation steps, executed tests, API/ABI impact, documentation, and risks. Use [the template](.github/PULL_REQUEST_TEMPLATE.md).

### GitHub Actions and triggers

Before opening a PR, identify which workflows must run for the change. The default CI workflow
should normally validate Pull Requests and pushes to the default branch. Release or packaging
workflows should be restricted to reviewed version tags or explicit `workflow_dispatch` runs.
Review path filters whenever files are added or moved; a workflow must not silently skip changes
that affect the build, tests, deployment, documentation generation, or workflow configuration.

Do not commit generated build directories, test binaries, generated documentation, caches, or
temporary outputs. If a generated result is needed as review evidence, upload it as a deliberate
workflow artifact with a retention policy rather than adding it to the repository.

Treat workflow files as executable code: review permissions, external actions, downloaded scripts,
secrets, branch restrictions, and artifact contents. Never use untrusted Pull Request data in a
privileged workflow without an explicit security review.

## Code organization

Follow [CODE_STYLE.md](CODE_STYLE.md) when adding or modifying classes and interfaces. Keep access sections in `public`, `protected`, `private` order, omit empty sections, and order members within each section as `Constructors`, `Destructors`, `Operators`, `Methods`, `Data members`, and `Static members`. Keep definitions in the same order as declarations for inline and out-of-class implementations.

## Merge criteria

- CI checks pass;
- required GitHub Actions checks are configured and successful;
- appropriate tests added or updated;
- documentation updated;
- review completed;
- no temporary or unrelated changes;
- Issue acceptance criteria met.

## Release

Releases must be created from an approved SemVer tag: `v<MAJOR>.<MINOR>.<PATCH>`.
