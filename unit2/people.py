#!/usr/bin/env python3

import collections

# Structures

Person = collections.namedtuple('Person', 'first_name last_name')

# Variables

People = [
    Person('Peter'   , 'Bui'),
    Person('Alyssa'  , 'Ritter'),
    Person('Carlos'  , 'Basurto'),
    Person('Genesis' , 'Argueta'),
    Person('Joshua'  , 'Bui'),
]

# Default sort
People.sort()

for person in People:
    print(person.last_name, person.first_name)

print()

# Sort by last_name with helper function
def get_last_name(person):
    return person.last_name

People1 = sorted(People, key=get_last_name)

for person in People1:
    print(person.last_name, person.first_name)

print()

# Sort by last_name with lambda expression

'''
When using multiple sorted's, do the highest priority sort LAST
People2 = sorted(People, key=lambda person: person.first_name) 
People2 = sorted(People2, key=lambda person: person.last_name)
'''

''' When using one sorted with multiple returns in the lambda, do the highest priority sort FIRST '''
People2 = sorted(People, key=lambda person: (person.last_name, person.first_name))

for person in People2:
    print(person.last_name, person.first_name)

print()
