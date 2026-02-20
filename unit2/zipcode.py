#!/usr/bin/env python3

import os
import re
import sys

import requests

# Functions

def usage(exit_status=0):
    print(f'''Usage: {os.path.basename(sys.argv[0])} [flags]
    -c      CITY    Which city to search
    -s      STATE   Which state to search (Indiana)''')
    sys.exit(exit_status)

def zipcodes(city: str | None, state: str) -> None:
    url = f"https://www.zipcodestogo.com/{state}/"
    regex = r'/([^/]+)/[A-Z]{2}/([0-9]{5})/">'
    response = requests.get(url)
    matches = re.findall(regex, response.text)

    for town, zipcode in matches:
        if city is None or city == town:
            print(zipcode)

# Main execution

def main(arguments=sys.argv[1:]):
    state = "Indiana"
    city = None

    while arguments:
        argument = arguments.pop(0)
        match argument:
            case "-c": city = arguments.pop(0)
            case "-s": state = arguments.pop(0)
            case "-h": usage(0)
            case _: usage(1)

    zipcodes(city, state)

if __name__ == '__main__':
    main()
