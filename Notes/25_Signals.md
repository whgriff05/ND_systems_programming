# System Calls: Signals

Use `signal()` to handle signals to a process

`signal(<signal>, <signal handler function>);`

`<signal handler function>(int signum)` (has to look like this)
