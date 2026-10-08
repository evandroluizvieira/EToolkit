# Deployment and delivery

## Release information

- Version source: `VERSION`
- Baseline: `v0.0.0`
- Delivery: GitHub Releases
- Documentation: GitHub Pages

## Environments

| Environment | Trigger | Approval |
|---|---|---|
| Validation | Pull Request or push to `master` | Required CI checks |
| Documentation | `master` push or manual dispatch | Repository Pages configuration |
| Release | Approved `vX.Y.Z` tag | Maintainer approval |

## Preconditions

- CI is green for the tagged revision.
- `VERSION` matches the tag.
- Artifacts are checksummed and traceable.
- Release notes and changelog are reviewed.

## Rollback

Delete or supersede a failed draft/release according to GitHub policy, mark the tag issue clearly, and
publish a corrected higher SemVer version. Do not rewrite a published tag.
