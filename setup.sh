#!/usr/bin/bash

### SETUP SCRIPT FOR THE AI ROUTINE ###

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
echo "(+one time runscript [that deletes its*elf])"
./ai/bin/script.sh
echo "H-E-R-E"
#pwd

./script.sh

echo "!~ I need your SUDO to install \"libcurl4-openssl-dev\", else press CTRL + C, and then install \"libcurl4-openssl-dev\" manually with APT."
sudo apt install libcurl4-openssl-dev

echo
echo "~:compiling..."
g++ -o a.out ./main.cpp -lcurl
echo "~:done."

echo
echo "~:checking for old runtime environment."
if [ -f "ai/bin/runtime" ]
then
  echo "-/- removing old runtime."
  rm -f ai/bin/runtime
else
  echo "-/- no old runtime found."
  echo "~: continuing"
fi

echo
echo "~:moving (new) ai model to \"ai/bin/runtime\"."
mv a.out ai/bin/runtime
echo "~:program \"model\" (ai) is stored in the \"./ai/bin/\" directory as \"./bin/runtime\"."

sleep 1

if [ -d "./ai/bin" ] && [ -f "./ai/bin/runtime" ]
  then
    echo
    echo "~:RUNNING: AI..."
    echo
    sleep 1
fi

if [ -f "./ai/bin/runtime" ]
  then
    chmod u+r ./ai/bin/runtime
    chmod u+x ./ai/bin/runtime
    ./ai/bin/runtime
    echo
    echo "~:done."
  else
    echo
    echo "~:something went wrong."

    exit 1
fi

if [ -f "a.out" ]
  then
  rm ./a.out
fi

if [ -f "ai/bin/TL/t1" ]
  then
  rm ./ai/bin/TL/t1
  touch ./ai/bin/TL/t1
fi

echo
if [ -d "ai/virtual/virtual-cd" ]
then
  echo "~:removing virtual library (if we can!)."
  #rm -Rf ai/virtual/virtual-cd
fi

exit 0
