#!/usr/bin/env python3

# List

def triples(sequence):
    ts = []
    for i in sequence:
        ts.append(i * 3)
    return ts

# Generator
def triples_gr(sequence):
    for i in sequence:
        print("before")
        yield i * 3
        print("after")

# Main Execution

numbers = triples_gr(range(10))

for t in numbers:
    print(t)
