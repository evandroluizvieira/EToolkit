# Test plan

## IContainer interface validation

This branch verifies the `IContainer` contract with `etoolkit_tests`; the cases cover state,
comparison, and mutation behavior.

## Scope

- Feature/release: `feature/icontainer-interface`
- Requirements: task-derived from current `main`
- Owner: `EToolkit maintainers`

## Test strategy

This branch uses dependency-free unit tests with a local runner to validate `IContainer` behavior
(state checks, comparison semantics, and mutation contracts) through an explicit concrete test
stub. The runner reports assertion failures with file and line metadata and returns non-zero on
failure. CTest is used for execution and reporting only.

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
| Windows + MSYS2 MinGW64 | C++11, CMake 3.16+, Ninja | Synthetic in-memory integer arrays | Reconfigure and rebuild `build/` |

## Test cases

| Scenario | Type | Expected result | Evidence | Status |
|---|---|---|---|---|
| Empty container reports empty state | unit | `isEmpty()` returns true | Local `etoolkit_tests` output | pass |
| Non-empty container reports non-empty state | unit | `isEmpty()` returns false | Local `etoolkit_tests` output | pass |
| Equality for same size and same sequence | unit | `operator==` true and `operator!=` false | Local `etoolkit_tests` output | pass |
| Inequality for different sequence | unit | `operator!=` true | Local `etoolkit_tests` output | pass |
| Inequality for different sizes | unit | `operator!=` true when sizes differ | Local `etoolkit_tests` output | pass |
| Self comparison consistency | unit | `value == value` true and `value != value` false | Local `etoolkit_tests` output | pass |
| `swap()` exchanges ownership and values | unit | interface-visible sizes and first elements are exchanged | Local `etoolkit_tests` output | pass |
| `clear()` resets and remains stable | unit | size becomes zero, empty-state is true, and repeated clear remains valid | Local `etoolkit_tests` output | pass |
| Non-empty null-data safety path | unit | comparison returns unequal when one side has null data and non-zero size | Local `etoolkit_tests` output | pass |
| Empty null-data comparison path | unit | two empty containers compare equal | Local `etoolkit_tests` output | pass |
| Swap with incompatible implementation | unit | values remain unchanged when dynamic type is incompatible | Local `etoolkit_tests` output | pass |

## Quality gates

- [x] Required tests pass.
- [x] Negative and error paths covered.
- [x] Security-sensitive behavior: N/A for this interface-only task.
- [x] Supported platform/configuration validated: Windows with MSYS2 MinGW-w64, Debug.
- [x] Performance thresholds: N/A; no performance requirement applies.
- [x] No known release-blocking defect remains.

## Defect handling

Record failed cases as Issues with reproduction steps, severity, environment, and evidence.
