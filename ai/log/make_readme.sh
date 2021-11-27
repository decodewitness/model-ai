#!/bin/bash

echo "- make_readme.sh - script is * running *"
echo

### combines several documents into one "README.md" file ###

if [ -f "README.md" ]
  then
    mv README.md README.md.1
fi
if [ -d "./doc" ]
  then
    cp ./doc/README.md ./README.md.old
    rm -r ./doc
    mkdir -p ./doc
    touch ./doc/README.md
  else
    mkdir -p ./doc
    touch ./doc/README.md
fi

### download from archive the documents to constuct the "README.md" ###
wget https://model-ai.com/archive/doc.tar.gz
### extract the "README.md" documents and clean up ###
if [ -f "./doc.tar.gz" ]
  then
    tar xvf ./doc.tar.gz
    rm ./doc.tar.gz
fi
if [ -f "header1.txt" ]
  then
  mv ./header1.txt ./doc/
fi
if [ -f "header2.txt" ]
  then
  mv ./header2.txt ./doc
fi
if [ -f "./program.txt" ]
  then
  mv ./program.txt ./doc/
fi
if [ -f "./beneficial.txt" ]
  then
  mv ./beneficial.txt ./doc/
fi
if [ -f "./authors.txt" ]
  then
  mv ./authors.txt ./doc/
fi
if [ -f "./copyrightandlaw.txt" ]
  then
  mv ./copyrightandlaw.txt ./doc/
fi
if [ -f "./readme_component_1.txt" ]
  then
  mv ./readme_component_1.txt ./doc/
fi
if [ -f "./readme_component_2.txt" ]
  then
  mv ./readme_component_2.txt ./doc/
fi
if [ -f "./make_readme.sh" ]
  then
  mv ./make_readme.sh ./doc/
fi
if [ -f "./doc.tar.gz" ]
  then
  mv ./doc.tar.gz ./doc/
fi
### create the document "README.md" inside the "/doc" directory ###
if [ -f "./doc/program.txt" ]
  then
  cat ./doc/program.txt >> ./doc/README.md
  rm ./doc/program.txt
fi
if [ -f "./doc/authors.txt" ]
  then
  cat ./doc/authors.txt >> ./doc/README.md
  rm ./doc/authors.txt
  echo "//=====================================" >> README.md
fi
if [ -f "./doc/header1.txt" ]
  then
  cat ./doc/header1.txt >> ./doc/README.md
  rm ./doc/header1.txt
fi
if [ -f "./doc/beneficial.txt" ]
  then
  cat ./doc/beneficial.txt >> ./doc/README.md
  rm ./doc/beneficial.txt
fi
if [ -f "./ai/log/runtime.txt" ]
  then
  cat ./ai/log/runtime.txt >> ./doc/runtime.txt
fi
if [ -f "./doc/runtime.txt" ]
  then
  cat ./doc/runtime.txt >> ./doc/README.md
fi
if [ -f "./doc/readme_component_1.txt" ]
  then
  cat ./doc/readme_component_1.txt >> ./doc/README.md
  rm ./doc/readme_component_1.txt
  echo "//=====================================" >> README.md
fi
if [ -f "./doc/readme_component_2.txt" ]
  then
  cat ./doc/readme_component_2.txt >> ./doc/README.md
  rm ./doc/readme_component_2.txt
  echo "//=====================================" >> README.md
fi
if [ -f "./doc/copyrightandlaw.txt" ]
  then
  cat ./doc/copyrightandlaw.txt >> ./doc/README.md
  rm ./doc/copyrightandlaw.txt
fi
if [ -f "./doc/header2.txt" ]
  then
  cat ./doc/header2.txt >> ./doc/README.md
  rm ./doc/header2.txt
fi
if [ -f "./README.md.1" ]
  then
  mv ./README.md.1 ./doc/README.md.old.1
fi
if [ -f "./doc/README.md" ]
  then
  cp ./doc/README.md ./README.md
fi
### do your clean up here ###


### exit the script ###
echo
exit 0
# EOF