#!/bin/bash

echo
echo "~:removing and recreating \"ai/virtual/virtual-cd/\"."

if [ -d "./ai/virtual/virtual-cd/" ]
  then
  rm -rf ./ai/virtual/virtual-cd
  mkdir -p ./ai/virtual/virtual-cd/bin0
  echo "~:done."
  echo
fi

echo "~:extracting the ai model to \"ai/virtual/virtual-cd\"."
echo
tar xvf ./ai/virtual/AI/model-ai.tar.gz -C ./ai/virtual/virtual-cd/
echo
echo "~:replacing \"ai/virtual/virtual-cd/ai/ai.cpp\"."
rm -f ./ai/virtual/virtual-cd/ai/ai.cpp
pwd
tar xvf ./ai/virtual/AI/ai0.cpp.tar.gz -C ./ai/virtual/virtual-cd/ai/
mv ./ai/virtual/virtual-cd/ai/ai0.cpp ./ai/virtual/virtual-cd/ai/ai.cpp
echo "~:done."
echo
echo "~:compiling virtual instance of AI."
g++ -o ./ai/virtual/virtual-cd/bin0/runtime ./ai/virtual/virtual-cd/main.cpp
echo "~:done."
echo
echo "~:starting AI virtual instance (N)"
echo
./ai/virtual/virtual-cd/bin0/runtime
echo
echo "~:done."
echo

exit 0
