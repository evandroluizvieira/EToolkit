# Definition of Done

Adapt this checklist to the project's risk, language, and delivery model. A work item is done only when the applicable criteria are satisfied or an explicit exception is approved.

## Discovery and planning

- [ ] Problem, goal, and scope are documented.
- [ ] Acceptance criteria are testable.
- [ ] Dependencies, risks, and compatibility impact are reviewed.

## Implementation

- [ ] Code or configuration is complete.
- [ ] The change is isolated to the intended scope.
- [ ] Public APIs, migrations, and breaking changes are documented.
- [ ] Error handling and security implications are addressed.
- [ ] Class and interface declarations follow [CODE_STYLE.md](CODE_STYLE.md), including access-section and member-category order.
- [ ] Inline and out-of-class definitions preserve the declaration order.

## Validation

- [ ] Relevant unit, integration, system, or manual tests pass.
- [ ] Negative and failure paths are considered.
- [ ] Supported platforms or configurations are validated.
- [ ] Formatter, linter, type checks, and static analysis pass when applicable.
- [ ] Performance or accessibility requirements are validated when applicable.

## Documentation and delivery

- [ ] README, API documentation, runbooks, or examples are updated.
- [ ] Changelog and release notes are updated when applicable.
- [ ] CI is green.
- [ ] Artifacts are reproducible and traceable to a commit or tag.
- [ ] Deployment and rollback instructions are available.
- [ ] The Pull Request title, complete description, and labels use the repository's default GitHub
	web labels only.
- [ ] Each Copilot review suggestion was assessed independently and has one resolution comment.

## Review and closure

- [ ] Pull Request review is complete.
- [ ] Acceptance criteria are met.
- [ ] Known limitations and follow-up tasks are recorded.
- [ ] The work item is linked to its evidence and closed only after verification.
