# System Calls: Processes

## Recall

A __process__ is a unit of __allocation__

- Address Space
    - Code, data, heap, stack
- Kernel State
    - Permissions, file descriptors, exit status, etc.
- Execution Context
    - Program counter, stack pointer, data registers

## Process Life Cycle
*refer to `processes/`*

__fork()__ allocates a new (EXACT COPY) process
- but it is a __new process__ (new pid, ...)
- this new process is the __child__, the old process is the __parent__

__exec()__ load new code into address space
- runs a new program in the child process

__exit()__ kills a process, storing that process's exit status
- exit 0 is a success
- exit !0 is a failure

__wait()__ retrieves a child's exit status

1. Parent __fork()__ to create a new process
2. Child performs actions, possibly __exec()__ to run another program
3. Parent __wait()__ for child process
4. Child __exit()__
5. Parent recieves child's exit status

## Easy Process Management in C

`system()` runs a command, returning exit status (like Python's `os.system()`)

`popen()` runs a command, opening up a stream with that command (like Python's `os.popen()`)
- remember: use `pclose()` to close the process stream

## Explaining the differences in exec()s

`execl` family: takes a list of arguments \
`execv` family: takes a vector of arguments
- `l`/`v` just takes in a file name, searches PATH
- `p` takes the input path to find the binary
- `e` takes an array of environment variables
