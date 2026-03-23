# C: Structs and Unions

## Struct
*refer to `point`*

A __composite data type__ with multiple (different typed) internal variables

While a struct is typically viewed as __one chunk of memory__, each attribute has its own portion of the total allocation (like an array, so first initializations are "lowest" in the stack)

## Union
*refer to `point` and `value`*

We can view the same chunk of memory as different types using a __union__

Looks and behaves like a struct, but all attributes are stored in __the same chunk of memory__

Used for type agnostic variables (type of __type polymorphism__)

Unions take up as much memory as their largest internal type.
