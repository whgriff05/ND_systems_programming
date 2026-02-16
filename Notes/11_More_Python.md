# Python Tests, Data Structures, Arguments, and I/O

## Imports
*refer to `fizzbuzz.py`*

To import a Python file `module.py`, use `import module` at the top of your file\
This will run all of your code in that file. To prevent code you don't want to run unless the module is run directly, use an __import guard__:\
`if __name__ == "__main__":`

To import just a particular function/class from a file without having to use dot notation, use `from <module> import <function/class>` and refer to it without dot notation

A common pattern to see is a `def main():` and a `main()` included in the import guard

## Documentation
*refer to `fizzbuzz.py`*

A __docstring__ is a (usually multi-line) string right under the function declaration that describes the action of the function

Use `help(<function>)` or `help(<module>.<function>)` to see the docstring/arguments

## Testing
*refer to `fizzbuzz.py`*

A __doctest__ is a test built into a docstring\
Use `python3 -m doctest <filename>` to test all doctests in a file
- `-v` for verbose (give result even if test passes)

## Command Line Arguments
Gotten from the `sys` module (`import sys`), under the `sys.argv` list

Usually you want to slice this array since `sys.argv[0]` includes the program name (usually use `arguments=sys.argv[1:]`)

## Type Annotations
Python doesn't explicitly require types, but you can annotate types on variables (`var: type = value`)

You can test your typing with `mypy <script.py>` in the shell

This is called __static analysis__, code itself is not run, it is just parsed

## Ternary in Python
Recall C: `int x = (condition) ? (true) : (false);`

Python Ternary: `x = (true) if (condition) else (false)`
