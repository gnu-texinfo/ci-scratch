#! /bin/sh

echo "JJJ"
./prog

if ./prog | grep 'inside foo' ; then exit 0; else exit 1; fi
