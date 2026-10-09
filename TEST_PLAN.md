# Test plan

## Public API consumer validation

The project validates the public EColor API from a consumer perspective with the
`etoolkit_public_api_compatibility` executable and `EColorTest.cpp`. It includes public forwarding headers, links against
the supported `EToolkit` target, exercises representative container and geometry types, and runs
through CTest. It currently covers representative graphics color types.
This check complements component-level tests; it does not replace them.

## Scope

- Feature/release: `<name>`
- Requirements: `<links or IDs>`
- Owner: `<name or team>`

## Test strategy

Describe the balance of unit, integration, system, acceptance, performance, security, compatibility, and manual testing.

### Unit test organization

Keep unit-test source code in the project's test directory and generated output in one shared
repository-level build directory. Do not use both `test/build/` and `build-tests/` for the same
configuration. A conventional layout is:

```text
test/                  Test declarations and implementations
build/                 Generated build tree
build/test/             Generated test targets and test metadata
```

When an external test framework is not needed, use a small local runner with classes or suites
organized by production component. Each suite should expose explicit test method declarations,
report assertion failures with source locations, return a non-zero status when a test fails, and
integrate with the project's test discovery mechanism.

Do not describe CTest as GoogleTest. CTest discovers and executes test commands and reports their
exit status; it does not supply assertions. GoogleTest is an optional external test framework.
Projects using a local runner should state that the runner has no external test-framework
dependency and that CTest is used only for execution and reporting.

For C++ projects, apply multiline Doxygen to test classes, test methods, assertion helpers, and
test entry-point declarations or signatures. Keep test bodies free of documentation comments and
use complete, descriptive names instead of unexplained abbreviations.

## Environments and data

| Environment | Version/configuration | Data source | Reset procedure |
|---|---|---|---|
| `<environment>` | `<configuration>` | `<synthetic/staging>` | `<procedure>` |

## Test cases

| ID | Scenario | Type | Expected result | Evidence | Status |
|---|---|---|---|---|---|
| TC-001 | `<scenario>` | `<unit/integration/system>` | `<result>` | `<link>` | `<todo/pass/fail>` |

## Quality gates

- [ ] Required tests pass.
- [ ] Negative and error paths covered.
- [ ] Security-sensitive behavior validated.
- [ ] Supported platforms/configurations validated.
- [ ] Performance thresholds met, if applicable.
- [ ] No known release-blocking defect remains.

## Defect handling

Record failed cases as Issues with reproduction steps, severity, environment, and evidence.
