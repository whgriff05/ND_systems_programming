#!/usr/bin/env python3

import csv
import requests

# Constants

URL    = 'https://yld.me/raw/gDQD'
POINTS = [1, 1.5, 1.5, 1, 1.5, 2.5, 2]
MAX    = sum(POINTS)

# Fetch data

data = requests.get(URL).text.splitlines()

scores = []

# Compute individual scores (Imperative)

'''
for student in csv.reader(data):
    points = []
    for point in student:
        points.append(float(point))
    scores.append(sum(points))

print(scores)
'''

# Compute individual scores (Functional) - Phase I

'''
for student in csv.reader(data):
    points = map(float, student)
    scores.append(sum(points))

print(scores)
'''

# Compute individual scores (Functional) - Phase II

'''
scores = map(lambda student: sum(map(float, student)), csv.reader(data))

print(list(scores))
'''

# Compute individual scores (List Comprehensions) - Phase I


'''
scores = [ sum(map(float, student)) for student in csv.reader(data) ]

print(scores)
'''

# Compute individual scores (List Comprehensions) - Phase II

scores = [sum([float(point) for point in student]) for student in csv.reader(data)]

print(scores)

# Filter scores (Imperative)

'''
Bs = []
for score in scores:
    if 0.8*MAX <= score < 0.9*MAX:
        Bs.append(score)

print(Bs)
'''

# Filter scores (Functional)

'''
Bs = filter(lambda score: 0.8*MAX <= score < 0.9*MAX, scores)

print(list(Bs))
'''

# Filter scores (List Comprehensions)

Bs = [score for score in scores if 0.8*MAX <= score < 0.9*MAX]

print(Bs)
