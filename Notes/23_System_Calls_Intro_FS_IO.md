# System Calls: Intro, File System, and I/O

## Recall the computing stack

- Applications
- Libraries
- Operating System / Kernel
- Computer Hardware

To talk between libraries and the OS, use __system calls__

## System Calls

A process requests a __service__ from the OS

- File System / Files / I/O
    - Open/Close
    - Read/Write
    - Stat
    - Opendir/Readdir
- Processes
    - Fork/Exec
    - Wait
    - Kill
    - Signal
- Networking
    - Getaddrinfo
    - Socket
    - Listen/Bind
    - Connect

## Files
*refer to `list.c` and `check.c`*

### Inodes

Inodes store administrative data about files and directories
- Mode
- Owner
- Size
- Timestamps
- Direct Block --> Data Block

### I/O
*refer to `copy.c`*

All __input__ and __output__ is performed on files
1. `open()`
    - create handle to stream of data (file descriptor)
    - use `fdopen()` to get a stream from a file descriptor
2. `close()`
    - destory handle to stream of data
3. `read()`
    - retrieve chunk from stream of data
4. `write()`
    - append chunk to stream of data
5. `seek()`
    - move within stream of data


