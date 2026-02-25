#!/usr/bin/env python3

from typing      import Iterator, Optional
from collections import namedtuple
from dataclasses import dataclass

# Structures                                    

@dataclass
class Node:                                     # Discuss: Data class
    data: str = ''
    next: Optional['Node'] = None

# Functions (Iterative)

def slist_data(head: Optional[Node]) -> list[str]:
    data = []
    curr = head
    while curr:
        data.append(curr.data)
        curr = curr.next

    return data

# Functions (Generators)

def slist_data_generator(head: Optional[Node]) -> Iterator[str]:
    if not head:
        return

    yield head.data

    yield from slist_data_generator(head.next)


# Main Execution

def main():
    slist = Node('a', Node('b', Node('c', Node('d', None))))

    for item in slist_data_generator(slist):
        print(item)

if __name__ == '__main__':
    main()
