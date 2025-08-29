#! /bin/sh

#./prog

if ./prog | grep 'bar returned: 5' ; then exit 0; else exit 1; fi
