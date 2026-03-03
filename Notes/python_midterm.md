# Unit 2: Python

__Python is an interpreted, high-level, object-oriented programming language with dynamic semantics.__

## Basic Overview and Functions:

All things in Python are __objects__
- `type(<obj>)` to see type
- `dir(<obj>)` to see methods
- `<obj>.method()` to use an object method
    - most methods return a new object
- `<obj>.attr` to get an attribute of an object

For stdlib functions/objects, you can use `help(<thing>)` to see some sort of internal documentation/man page

## Imports

To import a module, use `import <module>` at the top of your file\
This import will run all the code in your file, so to avoid running __all__ code, you can include the following to only run when the program itself is run

```py
def main():
    ...

if __name__ == "__main__":
    main()
```

## Documentation/Tests

A __docstring__ is a (usually multi-line) string right under the function declaration that describes the action of the function

A __doctest__ is a unit test built right into the docstring

## Command Line Args

Arguments are stored under `sys.argv`, and `sys.argv[0]` is always the name of the program called

## Type Annotations

Python doesn't explicitly require types, but you can annotate types on variables like this: `var: type = value`

You can test types by running `mypy <script.py>` in the shell

This is an example of __static analysis__ where the code itself is not run

## Ternary Operator in Python

Recall C: `<type> x = (condition) ? (value if true) : (value if false)`

Python: `x = (value if true) if (condition) else (value if false)`

## I/O in Python

For files: `for line in open(file)`

For processes: `for line in os.popen(cmd)`

## Processes

Run a program and capture output with `os.popen(cmd)`

Run a program and send to stdout with `os.system(cmd)`

## Requests

Use `requests.get(url)` to "curl" a webpage (send a HTTP GET request)

Unpack the response with `response.text` or `response.json()`

## Regex in Python

`grep`: `re.findall(r'<regex pattern>', <string>)`

`sed`: `re.sub(r'<regex pattern search>', r'<regex pattern replace>', <string>)`

## Functional Programming and Generators

In functional programming
- Programs are compositions of functions
- State is minimized and avoids side effects
- Transforming streams of data, not the individual items themselves one-by-one
- Concurrency is implicitly added to programs

`lambda` functions define a temporary one line function
- the body is the return

`map` applies a function to every item in an iterable, returning an iterator
- `map(func, iterable)`

`filter` returns an iterable of items that match the condition 
- `filter(func, iterable)`

List comprehensions construct a list in a functional programming style:
- `x = [func(i) for i in iterable]`
- `y = [func(i) for i in iterable if (condition with i)]`

Generators lazily evaluate the function
- have `yield` when yielding a value, or `yield from` when yielding a value from another iterable
- saves memory
- can also make a generator with list comprehension by using `()` instead of `[]`

## Parallel Computing

__Concurrency__ is the composition of independent computations
- Concerned about the __structure__ of division of labor

__Parallelism__ is the simultaneous execution of (possibly related) computations
- Concerned with applying the action and resources

### Pitfalls
- A __race condition__ happens when multiple tasks compete for the same resource in an unpredictable manner
- A __deadlock__ happens when multiple tasks are stuck waiting for one another

### Hallmarks of Concurrency
- An __embarrassingly parallel__ task exhibits natural concurrency
    - It should obviously be completed in parallel
    - Little to no dependency between tasks
    - Little to no need to communicate between tasks
- A problem with __task parallelism__
    - has concurrent execution of __different__ tasks on the same/different dataset(s)
    - has different tasks coordinating/communicating with each other
    - is best supported by generators
- A problem with __data parallelism__
    - has the concurrent execution of __the same__ task on the elements of a dataset
    - has a dataset with data independence (elements can be processed individually)
    - is best supported by functional programming






