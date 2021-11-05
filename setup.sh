#!/usr/bin/bash

### check for GCC compiler

echo "~:checking for GCC compiler."
if [ -f "/usr/bin/gcc" ]
then
  echo "-/- found GCC compiler"
else
  echo "-/- could not find GCC compiler"
  echo "-/- installing GCC compiler"
  echo "!~ I need SUDO to install GCC, else press CTRL+C and install GCC manually."
  sudo apt update && sudo apt install gcc
fi

echo
echo "~:installing Curl libraries"
echo "!~ I need SUDO to install \"libcurl4-openssl-dev\", else press CTRL + C, then install \"libcurl4-openssl-dev\" manually with APT."
sudo apt install libcurl4-openssl-dev

echo
echo "~:compiling..."
g++ -o a.out ./main.cpp -lcurl
echo "~:done."

echo
echo "~:checking for old runtime environment."
if [ -f "bin/runtime" ]
then
  echo "-/- removing old runtime."
  rm -f bin/runtime
else
  echo "-/- no old runtime found."
  echo "~: continuing"
fi

echo
echo "~:moving (new) ai model to \"bin/runtime\"."
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
  exit 0
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
