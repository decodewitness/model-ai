#!/usr/bin/bash

### FILENAMES ###
LIST="./ai/patch/archives_list.csv"
ARCHIVE1="./ai/patch/archive1.tar.gz"
ARCHIVE2="./ai/patch/archive2.tar.gz"
ARCHIVE2="./ai/patch/archive3.tar.gz"
EXTRA="./ai/patch/extra.txt"

### URLS ###
LIST_URL="https://model-ai.com/archives_list.csv"   # might contain additional archives

### ARCHIVES IN REPOSITORY ###
ARCHIVE_URL1="https://model-ai.com/archive1.tar.gz"
ARCHIVE_URL2="https://model-ai.com/archive2.tar.gz"
ARCHIVE_URL3="https://model-ai.com/archive3.tar.gz"
EXTRA_URL="https://model-ai.com/extra.txt"

### GET ARCHIVE FILES LIST FETCHED FROM THE REPOSITORY URLS ABOVE AT HTTPS://MODEL-AI.COM
echo "-/- getting \"archives_list.csv\""
wget --output-file=$LIST $LIST_URL

echo "-/- getting \"archives\" (.tar.gz format) from online repository"
wget --output-file=$ARCHIVE1 $ARCHIVE_URL1
wget --output-file=$ARCHIVE2 $ARCHIVE_URL2
wget --output-file=$ARCHIVE3 $ARCHIVE_URL3

### FETCH EXTRA DATA ###
wget --output-file=$EXTRA $EXTRA_URL

### DONE WITH THE SCRIPT ###
echo "done."
exit 0

# EOF