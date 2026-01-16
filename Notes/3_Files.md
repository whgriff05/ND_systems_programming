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