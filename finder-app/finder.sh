#!/bin/sh

num_args=$#
if [ $num_args -lt 2 ]; then
	echo "You didn't specify all the arguments"
	echo "Usage: <Command> <Filesdir> <Serachstr>"
	exit 1
fi
filesdir=$1
serachstr=$2
if [ -d "$filesdir" ]; then
	echo "The number of files are $(find "$filesdir" | tail -n +2 | wc -l) and the number of matching lines are $(grep -rn "$serachstr" "$filesdir" | wc -l)"
else
	echo "$filesdir is not a valid directory"
	exit 1
fi
