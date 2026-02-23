# Python Functional Programming
*refer to `people.py`*

In functional programming
- Programs are compositions of functions
- State is minimized and avoids side effects
- Transforming streams of data, not the individual items themselves one-by-one

Functional Programming implicitly adds __concurrency__ to programs

## Lambda Functions

We can use the `lambda` statement to define a one-line function for temporary purposes

`lambda`'s body is the return itself

## Map Function

`map(func, iterable)` applies a function to every element in an iterable (or collection), returning it in an iterable


## Filter Function

Similar to `map()`, but decides using the function whether to add the item to the returned iterable or not

## List Comprehensions

Use a deconstructed for loop inside square brackets to generate a list

`x = [func(i) for i in iterable]`

If you want to do a filter with list comprehensions, place the if __after__ the for

`y = [i for i in iterable if (condition with i)]`
