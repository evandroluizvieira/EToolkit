# Code style

This document defines structural ordering rules for class and interface declarations. Adapt language-specific details as needed, but keep the ordering predictable across the project.

## Names and identifiers

Use the complete project name in identifiers, branch names, issue references, paths, targets,
workflow names, package names, namespaces, and documentation. Do not create abbreviations or
acronyms for project names, including internal identifiers; for example, use `EToolkit` rather
than `ETK`. Use an abbreviation only when it is an established external standard required by a
tool or protocol, and document that exception.

Use the project's formatter configuration for whitespace and indentation. In C and C++ projects,
copy [.clang-format.template](.clang-format.template) to `.clang-format` and run `clang-format`
instead of manually applying formatter-only rules. Structural rules such as friend placement,
access-section order, declaration order, and documentation format remain project conventions and
are defined below because they are not reliably enforced by `clang-format`.

## Friend declarations

Keep all `friend` declarations at the top of the class body, before any access label and before
constructors, destructors, operators, methods, data members, or static members. Group the friend
declarations together. This rule applies to inline and out-of-class implementations alike.

## Class preamble and visibility order

Before the first access label, keep only declarations that are intentionally outside an
access section, especially grouped `friend` declarations. This is the `default` class area.
Do not place ordinary constructors, destructors, operators, methods, data members, or static
members in this area.

When a class uses more than one access section, declare sections in this order:

1. `public:`
2. `protected:`
3. `private:`

Do not declare an empty access section. Omit `private:`, `protected:`, or `public:` when that section has no members.

## Member category order

Within the default area and each access section, use this order and include only categories that
exist:

1. Constructors
2. Destructors
3. Inherited operators
4. Operators declared by the class
5. Inherited methods
6. Methods declared by the class
7. Data members
8. Static members

Inherited operators and methods are the declarations that implement or expose a contract from a
base class or interface, usually marked with `override`. Keep them before operators and methods
introduced only by the derived class. If a category has no inherited members, omit that category.

Use the same category sequence independently in `public:`, `protected:`, and `private:`. The
access-section sequence remains `public:`, `protected:`, then `private:`.

## Inheritance order

Declare base classes in the same order in which the derived class conceptually exposes or
implements them. Keep that order consistent everywhere:

1. the base-specifier list in the class declaration;
2. base-class constructor initializers;
3. inherited operators and inherited methods in the derived declaration;
4. out-of-class definitions and forwarding code;
5. Doxygen inheritance documentation.

Do not reorder base classes alphabetically in only one of these locations. The first base in the
class declaration must remain the first base in constructor initialization and documentation,
followed by the second base, and so on. If a class has no base classes, omit inheritance
documentation.

Document inheritance with Doxygen immediately above the class declaration. Use `@extends` for a
base class and `@implements` for an interface or contract. List tags in the same order as the
base-specifier list.

For C++ interfaces, the usual arrangement is:

```cpp
class Interface {
    friend class InterfaceTest;

public:
    virtual ~Interface() = default;

    // Inherited methods
    void baseMethod() override;

    // Methods declared by the class
    virtual void execute() = 0;

protected:
    Interface() = default;

    Interface(const Interface&) = default;
    Interface& operator=(const Interface&) = default;

private:
    // Data members
};
```

Example with ordered inheritance:

```cpp
/**
 * @brief Concrete dynamic container.
 * @implements IDynamicContainer
 * @implements IIterable
 */
class DynamicArray : public IDynamicContainer, public IIterable {
public:
    DynamicArray()
        : IDynamicContainer(), IIterable(){
    }
};
```

The category order applies independently inside each visibility section. For example, inherited
operators precede class-specific operators, inherited methods precede class-specific methods,
and private methods precede private data members.

Category marker comments such as `// Constructors`, `// Methods`, or `// Members` are not required above documentation blocks and should be omitted. The declaration order itself is the source of truth.

## Declarations and definitions

Keep the declaration order and definition order consistent, whether implementation is:

- inline inside the class;
- outside the class in the same header;
- in a separate source file;
- generated by a tool.

Do not reorder methods in the implementation merely because they are defined outside the class.
Match the complete class declaration order, including the inherited-versus-class-specific split,
whenever practical. The same order applies to inline definitions and definitions in separate
source files.

## Documentation

Document public and protected API members with the project's documentation format. For C++/Doxygen declarations:

- document every public or protected constructor and destructor when its behavior is relevant;
- document public and protected operators;
- document public and protected methods, parameters, return values, exceptions, and ownership when applicable;
- keep documentation immediately above the declaration it describes.
- use a multiline documentation block; do not compress a documentation block into a single line;
- for class and local variables that require documentation, use `type name; ///< description`, aligning the `///<` markers across the variable declarations in the same group;
- do not add a category comment between an access label and the first documentation block.

Example:

```cpp
DataType*    data;     ///< Pointer to the allocated element storage
unsigned int size;     ///< Number of elements currently stored
unsigned int capacity; ///< Number of elements that can be stored
```

Private implementation details may use shorter documentation unless they are part of generated API documentation.

### Test documentation

Apply the same documentation discipline to test code. In C++ projects, use multiline Doxygen
blocks immediately above test classes, test methods, assertion helpers, and test entry-point
declarations or signatures. Keep documentation out of executable test bodies. Use complete names
for test classes, methods, helpers, diagnostics, and documentation; abbreviations are allowed
only when they are established project terminology and documented.

## Checklist

- [ ] Access sections appear in `public`, `protected`, `private` order.
- [ ] All `friend` declarations are grouped at the top of the class body, before access labels.
- [ ] Empty access sections are omitted.
- [ ] Members follow constructors, destructors, operators, methods, data members, and static members order.
- [ ] Inherited operators precede class-specific operators, and inherited methods precede class-specific methods within every access section.
- [ ] Base classes, base initializers, inherited declarations, and Doxygen inheritance tags use the same order.
- [ ] Out-of-class definitions follow the declaration order.
- [ ] Public and protected API declarations have appropriate documentation.
- [ ] Documentation blocks are multiline and variable comments use aligned trailing `///<` descriptions.
- [ ] Test declarations and signatures have appropriate Doxygen documentation.
- [ ] Test bodies contain executable code rather than documentation comments.
- [ ] Test names and diagnostics avoid unexplained abbreviations.
