# C: Pointers, Arrays, and Strings

## Pointers
Every variable declaration is a __memory allocation__. \
A pointer is an __integer whose value is an address__. \
When we dereference a pointer, we access the value that corresponds to the address.

## Arrays
The name of an array is a label to the __first element__ (decays into a __pointer__).

For an array `int a[]`:
- `a[0] = *a = *(a + 0)`
- `a[1]      = *(a + 1) = *(1 + a) = 1[a]`

When passing an array name to a function, it __becomes a pointer__ (why you cannot compute array size within a function).
- Pass in array size in the function arguments
- Give the array an ending delimiter/sentinel value

## Strings
Strings in C are __arrays of characters__ terminated `NUL` (`\0`)

Defining a string like this: `char *s = "dog"` allocates __2__ things:
- the string itself into data memory
- a pointer to the first character into stack memory

Defining a string like this: `char s[] = "dog"` allocates __1__ thing:
- the string as an array of characters into stack memory

## Memory Regions

- Stack (local vars, function parameters) 
-   *stack expands downward, heap expands upward* 
- Heap (user managed: malloc) 
- Data (global vars, static vars, string literals)
- Code (instructions)
