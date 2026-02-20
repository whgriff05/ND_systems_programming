#!/usr/bin/env python3

import os
import random                                   
import sys

# Constants
                                               
FORBIDDEN = {'bong', 'sodomized', 'kiss', 'head-in', 'satanic', 'telebears'}

# Main Execution

def main():
    cows = []
    for index, line in enumerate(os.popen('cowsay -l')):
        if not index:
            continue

        for cow in line.split():
            if cow not in FORBIDDEN:
                cows.append(cow)

    chosen = random.choice(cows)
    message = sys.argv[1:]
    os.system(f"cowsay -f {chosen} {' '.join(message)}")

if __name__ == '__main__':
    main()
