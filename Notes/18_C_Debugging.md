# C: Debugging with gdb and valgrind

## gdb

- `q` - quits
- `run` - runs the program
- `bt` - backtraces the stack frame
- `f #` - shows the line where a segfault occurs in a function frame
- `p <var>` - shows a value for the variable
- `b #` - set a breakpoint at line #

## Valgrind

`valgrind --leak-check=full` to check memory errors (not just memory leaks!)
