# Unit 4: System Calls

## Intro to System Calls

System calls talk between __libraries and the operating system__

A process requests a __service__ from the OS
- File System / Files / I/O
    - Open/Close
    - Read/Write
    - Stat
    - Opendir/Readdir/Closedir
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

## File System

__Inodes__ store administrative data about files and directories
- mode
- owner
- size
- timestamps
- direct blocks that point to file data

All input and output is performed on __files__
1. `open()`
    - create handle to a stream of data (__file descriptor__)
    - use `fdopen()` to get a stream from a file descriptor
2. `read()`
    - retrieve chunk from stream of data
3. `write()`
    - append chunk to stream of data
4. `seek()`
    - move within stream of data
5. `close()`
    - destroy handle to stream of data

## Processes

Recall: a __process__ is a unit of __allocation__
- Address Space
    - Code, data, heap, stack
- Kernel State
    - Permissions, file descriptors, exit status, etc.
- Execution Context
    - Program counter, stack pointer, data registers

### Process Life Cycle
1. `fork()` allocates a new process (that is an __exact copy__ of the parent)
    - it is a __new process__ (new pid, ...)
    - this process is known as the __child__

2. `exec()` loads new code into address space
    - runs a new program in the child process

3. `exit()` kills a process, storing that process's exit status
    - 0 = success, !0 = failure
    - a child program `return`ing does not deallocate it

4. `wait()` retrieves a child's exit status and deallocates it

### Simple Process Wrappers

`system()` runs a command, returning with exit status (like Python's `os.system()`)

`popen()` runs a command, opening up a stream with that command (like Python's `os.popen()`)
- use `pclose()` to close process stream

### Exec Family
- `execl`: takes a list of argument strings
    - `execlp`: uses input path to find binary
    - `execle`: takes an array of environment variables
- `execp`: takes a vector (array) of argument strings
    - `execvp`: uses input path to find binary

### Dangerous Process Things

__Orphan__ - a child process with no parent process waiting on it (parent has terminated before waiting)

__Zombie__ - a dead (terminated) child process that hasn't been waited on yet

__Bomb__ - excessive or uncontrollable forking

### Signals

Use `signal()` to assign a function to handle a type of signal

`signal(<signal>, <signal handler function>)`

`<signal handler function>(int signum)` (signature)


## Networking

In the __TCP/IP__ model used in this class, we have two ends: a __client__ and a __server__

A client needs to know
- an __ip address__ and __port__ for the server's service
- its own __ip address__ and __port__ for the connection service it runs

We use this __Transmission Control Protocol__ to send __packets__ over the network, it uses a control mechanism to make sure every packet is sent/received correctly

### URL Structure

For a url `http://xavier.h4x0r.space:9234/cgi-bin/hello.sh?name=pnutzh4x0r`

"http://" - __protocol__ \
"xavier.h4x0r.space" - __domain__ \
":9234" - __port__ \
"/cgi-bin/hello.sh" - __path (resource)__ \
"?name=pnutzh4x0r" - __query string__

### Client Order

- `getaddrinfo()` - talks to DNS to resolve URL -> ip
- `socket()` - creates some object to represent the server
- `connect()` - establish connection to the server
- __write__ (in some function) - send message to the server
- __read__ (in some function) - receive message from the server
- __close__ (in some function) - shut down and clean up connection with the server

### Server Order

- `getaddrinfo()` - talks to DNS to resolve URL -> ip
- `socket()` - creates some object to represent the server
- `bind()` - binds the server to a port
- `listen()` - opens the server for connections
- `accept()` - take a client connection and do something with it
    - `accept()` returns a __client socket__, typically fork to do something with the client and leave the server listening for more
- __read/write__
- __close__

### HTTP GET Request

Note: in HTTP they use __DOS__ line endings: `\r\n`

To __send__ a __GET__ request:

```
GET /<path> HTTP/1.0
Host: <domain name>
User-Agent: <program/version>
<blank line>
```
(blank line symbolizes end of message)

Server returns:
```
HTTP/1.0 200 OK
Content-Length: <length of response>
<other headers>
<blank line>
<response body>
```

### HTTP PUT Request

To __send__ a __PUT__ request:

```
PUT /<path> HTTP/1.0
Host: <domain name>
Content-Length: <length of message body>
<blank line>
<message body>
```
