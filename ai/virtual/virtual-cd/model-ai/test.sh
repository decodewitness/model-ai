#!/bin/bash

### TESTING SCRIPT ###

echo
echo "starting test run."

echo
echo "compiling"
echo
g++ -o a.test main.cpp -lcurl
chmod +x a.test

echo
echo "running"
echo
./a.test | tee "test.output.txt"

echo
echo "cleaning up"
echo
rm ./a.test

echo
echo "opening log."
echo

less test.output.txt

echo
echo "done."
echo

exit 0