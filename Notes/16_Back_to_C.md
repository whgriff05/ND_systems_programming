# Back to C

## How the hardware stack works

- Users
- Utilities (programs)
- Standard Library (syscalls)
- Operating System (and/or Kernel)
- Hardware

## Why use C?

C is the __language of Unix__
- imperative, procedural language
- provides __low-level access to memory__
- maps efficiently to machine instructions
- requires minimal run-time
- "first-class citizen" on Unix

## Compiling

The compiler is a pipeline of 4 main stages:

1. Preprocessing
    - expand the original C file with the headers' code included
2. Compile
    - converts the C file to an assembly file (.s)
    - optimizes the C code in the conversion
3. Assemble
    - converts the assembly code to an object file (.o)
4. Link
    - connects the object file to the libraries and system, creating the full executable file

Overall, we can safely call steps 1-3 "Compile" and 4 "Link"

## Types of linking

Executables can be __dynamically__ or __statically__ linked
- __dynamic__: OS looks for the libraries at runtime
- __static__: libraries are pre-packaged with executable

*Note: static executables are generally much larger than their dynmaic counterparts, however it can introduce issues with bugs or updates (think Log4j)*

## How can we compile easier?

Use a __makefile__!

Makefiles use a domain-specific language to build a "directed acyclic graph" of dependencies

By default, makefiles only make their first rule (when running `make` in the shell)

Or, you can name rules (`make <rule>` in the shell)

Use `ldd` to see what libraries a dynamic executable uses

Use `strace` to see what system calls an executable uses
