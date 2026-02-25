#!/usr/bin/env python3

import os

for element in [1, 2, 3, 4]:
    print(element)

for letter in "samuel":
    print(letter)

for var, value in os.environ.items():
    print(var, value)

for line in open("/etc/passwd"):
    print(line.rstrip())

