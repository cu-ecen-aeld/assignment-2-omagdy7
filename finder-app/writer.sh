#!/bin/sh

num_args=$#
if [ $num_args -lt 2 ]; then
	echo "You didn't specify all the arguments"
	echo "Usage: <Command> <Filepath> <Writestr>"
	exit 1
fi

filepath=$1
writestr=$2

dir=$(dirname "$filepath")

if [ -d "$dir" ]; then
	echo "$writestr" >"$filepath"
else
	mkdir -p "$dir"
	echo "$writestr" >"$filepath"
fi
