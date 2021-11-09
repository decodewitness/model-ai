#!/usr/bin/bash

### FILENAMES ###
LIST="archives_list.csv"
ARCHIVE="archives.tar.gz"

### URLS ###
LIST_URL="https://model-ai.com/archives_list.csv"
ARCHIVE_URL="https://model-ai.com/archives.tar.gz"

### GET FILES DESCRIBED FROM REPOSITORY URLS ABOVE
echo "-/- getting \"archives_list.csv\""
wget --output-file=$LIST $LIST_URL

echo "-/- getting \"archives.tar.gz\""
wget --output-file=$ARCHIVE $ARCHIVE_URL

# EOF