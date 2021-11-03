#!/usr/bin/bash

echo
echo "~:COMPILING..."
g++ -o a.out ./main.cpp
echo "~:done."

echo
echo "~:removing old runtime."
if [ -f "bin/runtime" ]
  then
  rm -f bin/runtime
fi

echo
echo "~:moving ai model to \"bin/runtime\"."
mv a.out bin/runtime
echo "~:program \"model\" (ai) is stored in the \"./bin/\" directory as \"./bin/runtime\"."

sleep 1

if [ -d "./bin" ] && [ -f "./bin/runtime" ]
  then
  echo
  echo "~:RUNNING: AI..."
  echo
  sleep 1
  if [ -f "./bin/runtime" ]
    then
    chmod u+r ./bin/runtime
    chmod u+x ./bin/runtime
    ./bin/runtime
    echo "~:done."
  fi
else
  echo
  echo "~:something went wrong."
  exit 1
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
