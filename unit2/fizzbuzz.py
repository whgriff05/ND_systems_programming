#!/usr/bin/env python3

import sys

def fizzbuzz(start: int=1, end: int=100) -> list[str]:
    '''
    Prints fizzbuzz from start to end

    >>> fizzbuzz(1, 5)
    ["1", "2", "Fizz", "4", "Buzz"]
    '''
    
    results = []

    for i in range(start, end+1):
        if i % 3 == 0 and i % 5 == 0:
            results.append("FizzBuzz")
        elif i % 3 == 0:
            results.append("Fizz")
        elif i % 5 == 0:
            results.append("Buzz")
        else:
            results.append(f"{i}")

    return results

def main(arguments=sys.argv[1:]):
    '''
    Print fizzbuzz from first two arguments

    >>> main(['1', '5'])
    1
    2
    Fizz
    4
    Buzz
    '''
    
    start = int(arguments[0]) if len(arguments) >= 1 else 1
    stop = int(arguments[1]) if len(arguments) >= 2 else 100


    print("\n".join(fizzbuzz(start, stop)))

if __name__ == "__main__":
    main()
