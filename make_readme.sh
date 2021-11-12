#!/bin/bash

### combines several documents into one "README.md" file ###

if [ -f "README.md" ]
  then
    rm README.md
fi

if [ -d "./doc" ]
  then
    rm ./doc/*
    touch ./doc/README.md
fi

### download from archive the documents to constuct the "README.md" ###
wget http:://model-ai.com/archive/doc.tar.gz

### extract the "README.md" documents and clean up ###
if [ -f "./doc.tar.gz" ]
  then
    tar xvf ./doc.tar.gz
    rm ./doc.tar.gz
fi

### create the document "README.md" inside the "/doc" directory ###
cat ./authors.txt >> ./doc/README.md
echo "//=====================================" >> README.md
cat ./beneficial.txt >> ./doc/README.md
cat ./readme_component_1.txt >> ./doc/README.md
echo "//=====================================" >> README.md
cat ./ai/log/runtime.txt >> ./doc/README.md
echo "//=====================================" >> README.md
cat ./readme_component_2.txt >> ./doc/README.md
echo "//=====================================" >> README.md
cat ./copyrightandlaw.txt >> ./doc/README.md

### do your clean up ###
if [ -f "./authors.txt" ]
  then
    rm authors.txt
fi
if [ -f "./beneficial.txt" ]
  then
    rm beneficial.txt
fi
if [ -f "./readme_component" ]
  then
    rm readme_component_1.txt
fi
if [ -f "readme_component_2.txt" ]
  then
    rm readme_component_2.txt
fi
fi [ -f "copyrightandlaw.txt" ]
  then
    rm copyrightandlaw.txt
fi


### exit the script ###
exit 0
# EOF