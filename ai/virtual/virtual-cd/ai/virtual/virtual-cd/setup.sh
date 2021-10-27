#!/usr/bin/bash

echo
echo "COMPILING..."
g++ -o a.out ./main.cpp
cp a.out runtime/model
echo "Program is stored in the \"./runtime\" directory and called \"model\"."
echo "done."

sleep 1

if [ -f "a.out" ]
  then
  echo
  echo "RUNNING: AI..."
  echo
  sleep 1
  ./a.out
  echo "done."
fi

if [ -f "a.out" ]
  then
  rm ./a.out
fi

if [ -f "bin/t1" ]
  then
  rm ./bin/t1
  touch ./bin/t1
fi

exit 0
