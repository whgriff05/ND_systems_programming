# Unit 1 Additions: Commands / Extra

## Environment Variables to Know

`USER` - user name \
`SHELL` - shell \
`PATH` - directories where executables can be found \
`LD_LIBRARY_PATH` - directories where libraries can be found \
`PYTHONPATH` - directories where Python packages can be found 

## Variable Notes in Bash

To set a variable: `NAME=VALUE` \
To export a variable to sub-processes: `export NAME` \
To get variable: `$NAME` \
To get command output as a variable: `$(cmd)`

## Bash Commands

- `alias` - creates an alias for/renames a command
    - ex: `alias la='ls -lAh'`
- `awk` - scans patterns in strings and processes them
- `bg` - resumes processing of a background job slept by `C-z`
- `cat` - concatenates files and prints to __stdout__
- `cd` - change directory
    - `cd -` - change to previous directory
    - `cd .` - change to current directory
    - `cd ..` - change to parent directory
    - `cd ~` - change to home directory in `HOME`
- `chmod` - manages permissions for files
    - `[+/-] [r/w/x]` either adds or subtracts the read, write, or execute permission to groups specified in the `umask`
    - can also take __octal__ permission (755 is rwxr-xr-x)
- `cp` - copy file
- `curl` - send a HTTP request
- `cut` - remove a section from each line of a file
    - `cut -d <delimiter> -f <1 initialized field>`
    - `cut -c <range>` gets only range of letters (1 initialized, end-inclusive)
- `diff` - compares files line by line, shows differences
    - for each difference, top content is file 1, bottom content is file 2
- `du` - "disk usage", estimates the amount of disk space used by files/directories, measures in __blocks__ and measures total space taken by a file (which may be different than shown by `ls`)
- `echo` - display a line of text or value of variable
- `env` - print all environment variables
- `export` - creates an environment variable and passes it to child processes
    - without `export`, a variable is only specific to the current shell session and will not be visible to scripts/programs run from that terminal
- `fg` - bring a background job to the foreground
- `find` - search for files in a directory hierarchy
    - `find <dir> [-name <name string>] [-exec <command to execute on file>]` 
- `grep` - perform regular expression pattern matching on string
- `head` - used with piping, show only the first 10 lines
    - `head -n <number>` prints first number of lines
- `host` - gets ip address of a URL
    - `host <URL>`
- `hostname` - gets hostname of the machine
- `id` - prints user information (what groups, what user ids)
- `ip [-br] addr` - prints ip addresses (-br is __brief mode__)
- `jobs` - shows all background processes and their current state
- `kill` - sends a signal to a process as given by its PID
    - `kill -9` - send __SIGKILL__ (force kill) to a process
- `less` - pager to be able to read through all output of files, commands, etc
- `ls` - list directory
- `ln` - create a link
    - without `-s`: creates a __hard link__
    - with `-s`: creates a __symbolic link__
- `man` - read the manual for a given command
- `mkdir` - create directory
- `mv` - move file/directory from source to destination
- `nc` - __netcat__
    - ex: `nc -l -p <port>` create a simple TCP server on port `<port>`
- `nmap` - scan ports
    - `nmap -Pn -p <port range> <ip>` to see all ports in use on machine `<ip>`
- `ping` - send pings to URL/IP to measure latency
- `pkill` - sends signal to process as given by its __name__
    - `pkill -9` - send __SIGKILL__ (force kill) to a process
- `ps` - show processes for a given tty
    - `ps ux` - show all processes for a given user
    - `ps aux` - show all processes for all users
- `pwd` - print working (current) directory
- `rm` - remove/delete a file, __does not work on directories__
    - `rm -rf` - recursively deletes a file/all files in a directory
- `rmdir` - removes an empty directory
- `sed` - uses regular expression patterns to perform substitutions in a string
- `seq` - generates a sequence
    - `seq <end>` - generates 1-end (inclusive)
    - `seq <start> <end>` - generates start-end (inclusive)
    - `seq <start> <step> <end>` - generates start-end (inclusive) by step
- `sha1sum` - generates a sha1sum hash for a file
- `sort` - sort lines of a file/input
    - `sort -n` - sort numerically (1, 2, 3, 10 instead of 1, 10, 2, 4)
    - `sort -r` - sort reversed 
- `source` - read and execute commands from given file in the current shell environment
- `ss` - "socket statistics"
    - `ss -tlpn` - list all programs and ports in use on your local machine
- `ssh` - "secure shell" to remotely access a shell on a remote machine
- `stat` - give file/directory data
- `su` - switch user
- `sudo` - do as super user (with permissions)
- `tail` - see `head`, but for end of file
- `tar` - file (un)zipping and (un)compressing
    - `tar -xvzf <folder>.tar.gz` unzips and uncompresses to `<folder>`
    - `tar -cvzf <folder>.tar.gz <folder>` zips and compresses `<folder>`
- `tee` - in piping, splits output between pipe and whatever specified output file
- `test` - test file, synonymous with `[ `
    - `test -e` - does file exist?
    - `test -d` - is it a directory?
    - `test -f` - is it a regular file?
    - `test -L` - is it a link?
    - `test -r` - is it readable?
    - `test -w` - is it writeable?
    - `test -x` - is it executable?
    - `test <1> -o <2>` - <1> __or__ <2>
    - `test <1> -a <2>` - <1> __and__ <2>
- `top` - terminal user interface for `ps aux`, better version is `htop`
- `touch` - create a file, or if file already exists, update its timestamp to now
- `tr` - "translate" 
    - `tr <set1> <set2>` - translates each character in string from set 1 to its respective character in set 2
    - `tr -d <set>` - deletes all characters in set
- `traceroute` - trace all servers packets visit between server and client
- `uname -a` - prints system information: kernel, hostname, architecture, time, operating system
- `uniq` - eliminates all duplicate items that are directly next to each other (so typically pairing is `... | sort | uniq`)
    - `uniq -c` - counts all occurrences of unique items
- `uptime` - prints system uptime
- `w` - shows all users and their currently running process
- `wc` - count lines, words, and characters in file
    - `wc -l` - count lines
    - `wc -w` - count words
    - `wc -c` - count characters
- `wget` - download a file from the URL
- `which` - shows which command executable is targeted from the `PATH`
- `who` - shows a slimmed-down version of `w`
- `whoami` - prints `USER`






