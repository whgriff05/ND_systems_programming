# Regex

### Special Notes on Grep / regex matchers
- will match to the end of the string, not just stop once a match is found in a given string
- `-E` allows for extended regex (usually required/nice to have)
- `-o` only returns the matched area
- `-i` case insensitive

## Patterns
- *refer to `regex_cheat_sheet.md` for more detailed notes on patterns*
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

### Practice grep on `unit1/pokemon.txt`
- All strings
    - `grep -E '.*'`
- Only charmander and chespin
    - `grep -E '^ch'`
- All the words with two 't's
    - `grep -E 'tt'`
- Words that don't start with a vowel
    - `grep -E '^[^aeiou]'`
- All words with 2 consecutive vowels
    - `grep -E '[aeiou]{2}'`
- All words with 2 consecutive same letters
    - `grep -E '(.)\1'`
- All words that begin and end with the same letter
    - `grep -E '^(.).*\1$'`
- All words with exactly 2 of r, s, or t
    - `grep -E '^[^rst]*[rst][^rst]*[rst][^rst]*$`