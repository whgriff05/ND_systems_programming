# Shell Scripting

__Refer to `unit1/hello.sh`__

## Beginning Notes
- Remember executable permissions (`chmod +x ...`)
- Shebang can control interpreter (`#!/bin/sh`, `#!/bin/python3`, etc.)
- Variables set in the shell will not be recognized by the script unless the variable is exported using `export <var>=<value>`
- Shell commands can be run using `$(<cmd>)` or `` `<cmd>` ``