# Filters

A __filter__ reads from `stdin`, processes data, and outputs to `stdout`

## `tr` filter
- trans-literate command
- translates characters from a certain set to another set
    - Ex: `tr [:lower:] [:upper:]` to make all lowercase letters uppercase
- can also delete certain characters
    - Ex: `tr -d [:space:]` deletes all space characters

## `cut` filter
- `cut [-d] [<delimiter>] [-f] [<field number>]`
    - Ex: `cut -d ' ' -f 2` gets the second word
- `cut -c <range>`
    - Ex: `cut -c 2-5` gets you 2nd through 5th letters
- alternative to `cut` is `awk`
    - Ex: `awk -F ' ' '{print $1}'` prints the first word (delimits by spaces)

## `grep` filter
- `grep <regex>`
    - `-E` for extended regex (usually wanted)
    - `-o` to only return the matching area
    - `-v` invert match (select non-matching lines)

## `sed` filter
- typically used for search and replace
    - `sed 's/<find>/<replace>/[g]'` (g at the end makes it happen at all times on a line)
        - find/replace can be regular expressions
    - `-e` allows you to chain expressions