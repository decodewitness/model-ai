#!/usr/bin/bash

### check for GCC compiler

echo "~:checking for GCC compiler."
if [ -f "/usr/bin/gcc" ]
then
  echo "-/- found GCC compiler"
else
  echo "-/- could not find GCC compiler"
  echo "-/- installing GCC compiler"
  echo "!~ I need SUDO to install GCC else press CTRL+C and install GCC manually."
  sudo apt update && sudo apt install gcc
fi

echo
echo "~:checking for Curl libraries"
if [ -d /usr/include/c++/10/curl ]
then
  echo "-/- found Curl."
else
  echo
  echo "~:fixing C headers & Curl libraries."
  echo "-/- extracting Curl library."
  tar xvf libs/curl.tar.gz 
  echo "-/- creating \"/usr/include/c++/10/curl\" directory."
  echo "!~ I need SUDO to install the Curl library in your C++ headers."
  echo "else press CTRL+C and install the Curl header files for C++ manually."
  sudo mkdir -p /usr/include/c++/10/curl
  sudo mv ./curl/* /usr/include/c++/10/curl
  echo "-/- removing empty directory \"./curl\" to keep the project folder clean."
  rmdir curl
fi

echo
echo "~:compiling..."
g++ -o a.out ./main.cpp
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
