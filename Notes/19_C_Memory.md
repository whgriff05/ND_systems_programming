# C: Allocation of Memory

## Process

A __process__ is a unit of __allocation__
- Address Space
    - Code, data, heap, stack
- Kernel State
    - Permissions, file descriptors, etc
- Execution Context
    - Program counter, stack pointer, data registers

## Addresss Space
- Stack (local vars, function parameters) 
-   *stack expands downward, heap expands upward* 
- Heap (user managed: malloc/free) 
- Data (global vars, static vars, string literals)
- Code (instructions)

## Advice for Memory

Stack:
- Pros: automatic management
- Cons: limited
- Conclusions: use whenever possible

Heap:
- Pros: basically unlimited and persistent
- Cons: you are responsible; it's slower
- Conclusions: use with persistent or large data, use common patterns
