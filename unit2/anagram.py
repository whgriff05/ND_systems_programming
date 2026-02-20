#!/usr/bin/env python3

import os
import sys

# Functions

def usage(status=0):
    print(f'''Usage: {os.path.basename(sys.argv[0])} [flags]
    -i  Ignore case distinctions

This program reads in two words per line and determines if they are anagrams.
''')
    sys.exit(status)

def count_letters(string: str) -> dict[str, int]:
    ''' Returns a dictionary containing counts of each letter in string 

    >>> count_letters('aaa bb c')
    {'a': 3, 'b': 2, 'c': 1}
    '''
    counts = {}

    for letter in string:
        if letter.isspace():
            continue

        counts[letter] = counts.get(letter, 0) + 1

        '''
        if letter in counts:
            counts[letter] += 1
        else:
            counts[letter] = 1
        '''

        '''
        try:
            counts[letter] += 1
        except KeyError:
            counts[letter] = 1
        '''

    return counts

def is_anagram(word1: str, word2: str) -> bool:
    ''' Returns whether or not word1 and word 2 are anagrams

    >>> is_anagram('dormitory', 'dirty room')
    True
    
    >>> is_anagram('asdf', 'asdfg')
    False
    '''

    counts1 = count_letters(word1)
    counts2 = count_letters(word2)
    return counts1 == counts2

# Main Execution

def main(arguments=sys.argv[1:], stream=sys.stdin) -> None:
    ignore_case = False

    # Parse command-line options
    while arguments:
        argument = arguments.pop(0)
        match argument:
            case "-i": ignore_case = True
            case "-h": usage(0)
            case _: usage(1)

    # Process standard input
    for line in stream:
        if ignore_case:
            line = line.lower()

        word1, word2 = line.rstrip().split()
        if is_anagram(word1, word2):
            print("Anagram!")
        else:
            print("Not Anagram!")

if __name__ == '__main__':
    main()
