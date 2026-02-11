# Unit 1: Bourne Shell

## The Unix Philosophy
1. Write programs that __do one thing__ and __do it well__
2. Write programs to __work together__
3. Write programs to __handle plain text__

## Git Basics

Git is a distributed version control system

`git clone` - clones a repository from an upstream (usually on GitHub)\
`git add` - adds modified files to the __staging area__\
`git commit` - permanently tracks the modifications to the branch\
`git log` - see all commits\
`git push` - pushes all local commits on a branch to the upstream origin\
`git pull` - fetches and merges changes on the origin to the local repository\
`git switch` - changes branch, can create a branch with `-c` flag

## Files

__inode__s store file metadata: mode, owner, size, timestamp

Linking files with `ln`
- `ln <source> <dest>` creates a __hard link__ (directly to inode)
- `ln -s <source> <dest>` creates a __symbolic (soft) link__ (just to the file's path/name)

Permissions are stored in 9 bits: 3 for owner, 3 for group, and 3 for the world
- rwx: read, write, execute
- usually stored in octal (`111000000` --> `700`)
- permissions set with chmod

Tar basics
- Compress a folder with `tar -cvzf <tar> <folder>`
- Extract a folder with `tar -xvzf <tar>`

## Processes

A __process__ is a loaded instance of a program into RAM
- contains __STDIN (0)__, __STDOUT (1)__, and __STDERR(2)__

`ps ux` shows user processes
- `kill <pid>` sends `SIGTERM` to end a process
- `kill -9 <pid>` sends `SIGKILL` to force kill a process

`C-z` "sleeps" a process (sends it to background)\
`jobs` lists all jobs including sleeping ones\
`bg <#>` runs a sleeping job in the background\
`<command> &` starts a process in the background

## Networking

`ip <-br> addr` - gets ip address
- __localhost__ (127.0.0.1)
- __private__ (usually 192.168.x.x)
- __public__ (anything else)

`host` - gets DNS hostname

Different applications listen for different requests on different __ports__
- `ss -tlpn` - to see your own ports
- `nmap -Pn -p <port range> <ip>` to see another host's ports

__Bandwidth__ is how much data is carried over time (measured by downloading a file)\
__Latency__ is how much delay is between sent data packets (measured by using `ping <ip>`)

## Regex
- `.` matches any character
- `*` matches any preceeding pattern 0 or more times
- `?` matches any preceeding pattern 0 or 1 times
- `+` matches any preceeding pattern 1 or more times
- `{n}` matches any preceeding pattern exactly n times
- `[...]` creates a set matching any character in a string to any character in the set (ex: `[aeiou]` to match any vowel)
    - `[^...]` match the complement of that set (anything not in the set)
- `^...` anchors to the beginning of the string
- `...$` anchors to the end of the string
- `(...)` creates a subexpression that keeps track of what it captured
    - `\n` references that specific subexpression again (with the result of what it originally captured)

## Filters

- `tr` translates x to y
    - `tr -d` deletes x
- `cut` cuts out a certain part
    - `cut -d _ -f _` d: delimiter, f: field
    - `cut -c <range>` only gets range of letters
- `grep`
    - `-o` to only return the matching area
    - `-v` to invert the match (select non-matching lines)
- `sed` to search and replace
    - `-e` allows you to chain expressions



