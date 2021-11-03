#!/bin/bash

echo
echo "~:removing and recreating \"ai/virtual/virtual-cd/\"."

if [ -d "./ai/virtual/virtual-cd/" ]
  then
  rm -rf ./ai/virtual/virtual-cd
  #mkdir -p ./ai/virtual/virtual-cd/bin0
  echo "~:done."
  echo
fi

echo "~:creating \"virtual-cd\" directory in \"./ai/virtual/\"."
echo
mkdir -p ./ai/virtual/virtual-cd/

echo
echo "~:extracting the ai model to \"ai/virtual/virtual-cd/model-ai\"."
echo

tar xvf ./ai/virtual/AI/model-ai.tar.gz -C ./ai/virtual/virtual-cd/

echo "~:removing old source instance: \"./ai/virtual/virtual-cd/ai/ai.cpp\"."
echo
#rm -f ./ai/virtual/virtual-cd/ai/ai.cpp
#pwd
#echo
#echo "~:placing new source instance @: \"ai/virtual/virtual-cd/ai/ai.cpp\"."
#tar xvf ./ai/virtual/AI/ai0.cpp.tar.gz -C ./ai/virtual/virtual-cd/ai/
#mv ./ai/virtual/virtual-cd/ai/ai0.cpp ./ai/virtual/virtual-cd/ai/ai.cpp
#echo "~:done."
echo
echo "~:compiling virtual instance of AI."
g++ -o ./ai/virtual/virtual-cd/model-ai/bin/runtime ./ai/virtual/virtual-cd/model-ai/main.cpp -lcurl
echo "~:done."
echo
echo "~:starting AI virtual instance (N)"
echo
./ai/virtual/virtual-cd/model-ai/bin/runtime
echo
echo "~:removing (virtual-cd hierarchy)."
echo
rm -rf ./ai/virtual/virtual-cd
echo
echo "~:done."
echo

exit 0
