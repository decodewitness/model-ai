#!/bin/bash

### ENABLE "app=true" near the top of "/model-ai/ai/ai.cpp" ###
echo "-/- executing \"virtual.sh\"."

### update the cabinet (then run "maestro")
echo "-/- updating (fetching from repository)"
./repos.sh

### prune files here ###
echo "-/- pruning file dependencies"

# roll over library files adding new library to the hierarchy
# (probably best to build a new model for the "virtual-cd" and "instance")
# get new script editor "ai.cpp" and compile it
    # archive.tar.gz ~ (some sort of cabinet file) probably from https://model-ai.com/archive.tar.gz downloaded file
    # list.info ~ (list of utilities included)
    # ./scripts/script.####.sh
# combine scripts to the proper place in the hierarchy or simply replace modules
# keep a "/model-ai/ai/lib/manifest" (cabinets indexed in manifest)
# use "lib" to keep an extension of libraries for the scripts


### create "/model-ai/ai/lib" directory if it doesn't exist yet
if [ -d "./ai/lib" ]
  then
  echo "-/- found ai/lib libraries"
  else
  echo "-/- creating \"ai/lib\" directory"
  mkdir ./ai/lib
fi

### back up old AI virtual-cd program in "./ai/lib" called "ai" to "ai.old"
if [ -f "./ai/lib/ai" ]
  then
  mv ./ai/lib/ai ./ai/lib/ai.old
fi

### extract ./ai/bay/archives.tar.gz
tar xvf ./ai/bay/archives.tar.gz

### move "./ai/bay/scripts" in place hierarchy if having been created
if [ -d "./ai/bay/scripts" ]
  then
  mv ./ai/bay/scripts/* ./ai/lib
  echo "-/- removing scripts directory"
  rm -r ./ai/bay/scripts
fi

### integrate "list.info" into library its "manifest"
if [ -f "./ai/bay/list.info" ]
  then
  cat ./ai/bay/list.info >> ./ai/lib/manifest
  echo "-/- removing list.info"
  rm ./ai/bay/list.info
fi

### compile logic ###
if [ -f "./ai/bay/ai.cpp" ]
  then
  g++ -o ./ai/lib/ai ./ai/bay/ai.cpp
fi

### run appliance ###
echo "!!~you still need to create the virtual instance compressed archive and such."
if [ -f "./ai/lib/ai" ]
  then
  echo "-/- running script editor from modular bay"
  ./ai/lib/ai
  else
  echo "!!~ no freaky script editor found -- skipping modules"
fi

### end of script ###
echo "done."
exit 0

#EOF