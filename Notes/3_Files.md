# Files

## Unix Hierarchy
`man hier` for more information

```sh
# The Unix Filesystem

root
 |--- bin (binaries/applications/programs)
 |--- dev (devices)
 |--- etc (configuration)
 |--- tmp (temporary/scratch space)
 |--- var (application data)
 |--- usr (user applications)
```

## Inode
An __inode__ stores file metadata
- Mode
- Owner
- Size
- Timestamp

Create links to files using `ln`
- `ln <source> <dest>` creates a __hard link__ (directly to the file inode)
- `ln -s <source> <dest>` creates a __symbolic (soft) link__ (just to the file's name)

Note: if you adjust the original file, the hard link will be kept, but the symbolic link will break

## Why do we need files?

We need a __persistent__ place to store information. Memory is temporary, whereas persistent storage can keep data even if the machine is affected (program is closed, machine turns off, etc.)

## File Permissions

Files get 9 bits to store permissions: 3 for the __owner__, 3 for the __group__, and 3 for the __world__/other. They go in order of __read__, __write__, __execute__.

Examples: \
`111000000` --> user can read/write/execute, group and world can't \
`100100100` --> user, group, and world can read, no one can write or execute

(These typically look like this when using `ls -l`: `rwx------` and `r--r--r--`)

These are typically stored in __octal__ notation

Examples: \
`111000000` --> `700` \
`100100100` --> `444`

You set file permissions with the `chmod` command

You can also shorthand some additions to a file: `+x` makes the file executable for yourself; for group/world you can do `(g/w)+x`. Just using `+x` only affects yourself because of a `umask` being set to not affect group/world perms. Otherwise, if no umask is set, user, group, and world perms will all be affected. (This also all works with `+r` and `+w`)