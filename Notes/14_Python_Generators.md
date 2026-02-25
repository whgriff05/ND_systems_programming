# Python Generators

## Iterators
*refer to `iterators.py`*

Classes in Python usually are iterable (they have `__iter__()` and `__next__()` magic methods)

This is what allows you to go through a sequence with a for loop (`for x in seq`)

## Generators
*refer to `triples.py`*

With a generator, we __lazily evaluate__, or process, the function
- Start evaluation until a `yield` statement
- At a `yield`, pause the function and return the value
- When called again, the function picks back up where we left off

Generators are __lazy__
- Nothing is called until a value is requested from a generator
- Could save time, definitely saves memory

You can also do a generator with a list comprehension by using `()` instead of `[]` 

What if we want to use some type of recursion with generators? Be sure to use `yield from` when trying to yield a function that returns a generator (will yield the values in the generator instead of just the generator object itself)

*Note: other programming languages might call these __coroutines__*
