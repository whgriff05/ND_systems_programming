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

### Inodes

Inodes store administrative data about files and directories
- Mode
- Owner
- Size
- Timestamps
- Direct Block --> Data Block



