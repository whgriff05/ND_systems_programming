#!/bin/sh

EXITCODE=0

stat hello.sh > /dev/null 2>&1 && echo "Yeah"
stat abcd > /dev/null 2>&1 || echo "Nope"

#####

if test -e hello.sh; then
    echo "We have hello.sh"
else
    echo "We are missing hello.sh"
fi


if [ -e "$1" ]; then
    echo "We have $1"
else
    echo "We are missing $1"
fi

#####

check_file() {
    if [ -e "$1" ]; then
        echo "We have $1"
    else
        echo "We are missing $1"
        EXITCODE=$((EXITCODE + 1))
    fi
}

<<COMMENT
for argument in "$@"; do
    check_file "$argument"
done
COMMENT

while [ $# -gt 0 ]; do
    argument="$1"
    check_file "$argument"
    shift
done

exit $EXITCODE
