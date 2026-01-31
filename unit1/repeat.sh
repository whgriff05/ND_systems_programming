#!/bin/sh

# Globals

SHOUT=0
N=1

# Functions

usage() {
    cat 1>&2 <<EOF
Usage: repeat [-n N -s] MESSAGE
    -n N    Repeat MESSAGE N times (default is 1)
    -s      Shout MESSAGE (uppercase)
EOF
    exit $1
}

shout() {
    if [ "$SHOUT" -eq 0 ]; then
        echo "$1"
    else
        echo "$1" | tr [:lower:] [:upper:]
    fi
}

# Parse Command Line Arguments

while [ $# -gt 0 ]; do
    case $1 in
	-n) N="$2"; shift;;
	-s) SHOUT=1;;
	-h) usage 0;;
	-*) usage 1;;
	 *) break;;
    esac
    shift
done

MESSAGE="$@"

# Main Execution
for i in $(seq "$N"); do
    shout "$MESSAGE"
done
