# Regex Cheat Sheet

## Basic Regular Expressions
- `.` - matches any character
- `^` - prefix anchor, the expression is found at the start of line
- `$` - suffix anchor, the expression is found at the end of line
    - `^$` will match blank lines
- `[]` - bracket expression, can match a single character to a set of characters
    - Ex: `[bg]zip` --> bzip, gzip
    - `[^a]` - negation, that character must not be present at that position
    - `[A-Z]` - range, that character must belong to the set in the range

## Extended Regular Expressions
- `a|b` - alteration, match either a or b
    - can separate from other regex elements with `()`
- `?` - make the preceeding expression optional
- `*` - match the preceeding element 0 or more times
- `+` - match the preceeding element 1 or more times
- `{}` - match the preceeding element a certain number of times
    - `{n}` - match if exactly `n` times
    - `{n, m}` - match if n <= times <= m
    - `{n,}` - match if times >= n
    - `{,m}` - match if times <= m