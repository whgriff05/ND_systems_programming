# C: Bitsets and Linked Lists

|Data Structure|C    |Python|
|Sequence      |     |list|
|Fixed         |array|tuple|
|Associative   |     |dict|
|Membership    |     |set|

## Review

__Set__
- `add()`: add value to set
- `contains()`: determines if value is in set
- `remove()`: removes value from set
- implement using a bitset, linked list, hash table

## Bitset
*refer to `bitset`*

Instead of storing values in a sequence container, we can simply store whether or not the value is in the set by __marking a corresponding bit__

- Use integers as sets
- Use logical operators to set and clear individual bits

To represent a particular value, we need to produce a __bitmask__ which contains a 1 at the bit we want and 0s everywhere else. Typically to make one, we use bit shifts (`<<` and `>>`)

To add a value to a bitset, we use a __logical OR__ `|` on the bitset and bitmask that represents the value

To see if the bitset contains a value, we use a __logical AND__ `&` on the bitset, and that bitset will become the bitmask if it contains that value

## Linked List
*refer to `list`*

A linked list is a data structure that consists of a sequence of connected nodes. Each node stores a value and a pointer to the next node in the sequence.
