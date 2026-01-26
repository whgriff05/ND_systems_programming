#!/bin/sh

NAME=${NAME:-Anonymous}
DATE=$(date)
# using backticks also works: DATE=`date`

case $NAME in
    elijah) GREETING="hafa adai" ;;
    *) GREETING="hi";;
esac

echo "$GREETING, $NAME"
echo "Today is $DATE"
