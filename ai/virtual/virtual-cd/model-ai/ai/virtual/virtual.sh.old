#!/bin/bash

if [ -d "./ai/virtual/virtual-cd/bin" ]
  then
  rm -rf ./ai/virtual/virtual-cd
fi

mkdir -p ./ai/virtual/virtual-cd/bin0
#cp model.ai.tar.gz virtual-cd
#tar new model

if [ -f "./ai/virtual/virtual.ai.tar.gz" ]
  then
  tar xvf ./ai/virtual/virtual.ai.tar.gz -C ./ai/virtual/virtual-cd/
  g++ -o ./ai/virtual/virtual-cd/bin0/runtime ./ai/virtual/virtual-cd/main.cpp

  if [ -f ./ai/virtual/ai0.cpp ]
    then
    echo
    echo "~-:: +refitting model (virtual ai)"
    echo
    cp ./ai/virtual/ai0.cpp ./ai/virtual/virtual-cd/ai/ai.cpp
  fi

  echo
  echo "!!NOTICE: - Starting virtual instance."
  echo

  ./ai/virtual/virtual-cd/bin0/runtime
else
  echo
  pwd
  echo
  echo "!!ERROR: - Virtual system is not available in your distribution."
  echo
fi  

exit 0