#!/usr/bin/env python3

import pprint
import re
import sys

import requests

# Constants

HEADERS  = {'User-Agent': __name__}
URL      = 'https://en.wikipedia.org/w/api.php'
PARAMS   = {
    'action'  : 'query', 
    'list'    : 'search', 
    'format'  : 'json', 
    'srsearch': sys.argv[1],
}

# Main Execution

def main():
    response = requests.get(URL, params=PARAMS, headers=HEADERS)
    data = response.json()
    articles = data["query"]["search"]
    articles = sorted(articles, key=lambda a: a['size'], reverse=True)[:5]
    
    for index, article in enumerate(articles, 1):
        title = article["title"]
        size = article["size"]
        text = re.sub(r'<[^>]+>', '', article["snippet"])[:60]

        print(f"{index:>4}.\t{title} ({size})\n\t{text}")
        if index != len(articles):
            print()

if __name__ == '__main__':
    main()
