# Operations and maintenance

## Ownership

- System: EToolkit repository automation
- Owner: EToolkit maintainers
- Support: GitHub Issues

## Runtime overview

The project is a library and does not run a hosted service. Operational components are GitHub Actions,
GitHub Releases, GitHub Pages, and repository artifacts.

## Monitoring

Review failed CI, Doxygen, version, and release workflow runs. Verify artifact contents, checksums,
and published documentation after every release.

## Recovery

Do not rerun a release with a different artifact under the same tag. Fix the workflow or source and
publish a new patch version. Preserve failed-run evidence for diagnosis.

## Maintenance

Review action versions, permissions, toolchain versions, dependencies, and artifact retention during
milestones and before each release.
