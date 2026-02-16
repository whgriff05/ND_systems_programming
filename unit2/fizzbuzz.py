#!/usr/bin/env python3

def fizzbuzz(start=1, end=100):
    for i in range(start, end+1):
        if i % 3 == 0 and i % 5 == 0:
            print("FizzBuzz")
        elif i % 3 == 0:
            print("Fizz")
        elif i % 5 == 0:
            print("Buzz")
        else:
            print(i)

fizzbuzz(9, 20)
print()
fizzbuzz(90)
print()
fizzbuzz(end=15)
print()
fizzbuzz()
