# Risk register

| ID | Risk | Probability | Impact | Mitigation | Status |
|---|---|---|---|---|---|
| R-001 | Version workflow creates an incorrect tag | Medium | High | Central `VERSION`, commit-range analysis, protected `master`, review logs | Open |
| R-002 | Release artifact does not match its tag | Low | High | Clean tagged checkout and VERSION/tag verification | Open |
| R-003 | GitHub Pages configuration blocks deployment | Medium | Medium | Verify Pages source and environment before first publication | Open |
| R-004 | Toolchain drift breaks Windows build | Medium | High | Pin/document MSYS2 tools and keep CI evidence | Open |

## Review

Review risks before the first release and after any failed workflow or release.
