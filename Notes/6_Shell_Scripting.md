# Shell Scripting

## Beginning Notes - refer to `unit1/hello.sh`
- Remember executable permissions (`chmod +x ...`)
- Shebang can control interpreter (`#!/bin/sh`, `#!/bin/python3`, etc.)
- Variables set in the shell will not be recognized by the script unless the variable is exported using `export <var>=<value>`
- Shell commands can be run using `$(<cmd>)` or `` `<cmd>` ``

## Control Flow - refer to `unit1/exists.sh`
- Use `$?` to get the exit code of the last run program
- `0` means program ran successfully, `<not 0>` means program had an error
- `&&` runs second command IF the first command __is__ successful
- `||` runs second command IF the first command is __not__ successful
- `if` statements work in shell, `0` is true because the expression ran successfully, `!0` is false
- the `test` command, or `[ ... ]`; you __NEED__ whitespace between `[` and the rest of the arguments and the `]`
- Command line arguments can be referenced like `$1`, `$2`..., or `$#` for __argc__ and `$@` for __argv__
- `for` loops run over sequences, have an iterator variable
- Variables become easier when surrounded by double quotes `"`, this is because any space will be considered a second thing entirely without quotes
- Heredoc (`<<X ... ... X`) will take whatever lines of code in a shell script are surrounded by it and turn it into a string
- `while` loops also run while a condition is true
    - when working with cmd-line arguments and while loops, we might want to use `shift` to move all cmd-line arguments forward one space (`$n+1` --> `$n`)
- You can exit the script with an exit code by calling `exit <exitcode>`

## Writing Clean Scripts - refer to `unit1/repeat.sh`
- `while` and `case` are used to handle command line arguments