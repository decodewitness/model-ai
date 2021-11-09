#!/usr/bin/bash

### FILENAMES ###
LIST="./patch/archives_list.csv"
ARCHIVE1="./patch/archive1.tar.gz"
ARCHIVE2="./patch/archive2.tar.gz"

### URLS ###
LIST_URL="https://model-ai.com/archives_list.csv"   # might contain additional archives

### ARCHIVES IN REPOSITORY ###
ARCHIVE_URL1="https://model-ai.com/archive1.tar.gz"
ARCHIVE_URL2="https://model-ai.com/archive2.tar.gz"
ARCHIVE_URL3="https://model-ai.com/archive3.tar.gz"

### GET FILES DESCRIBED FROM REPOSITORY URLS ABOVE
echo "-/- getting \"archives_list.csv\""
wget --output-file=$LIST $LIST_URL

echo "-/- getting \"archives\" (.tar.gz format) from online repository"
wget --output-file=$ARCHIVE $ARCHIVE_URL1
wget --output-file=$ARCHIVE $ARCHIVE_URL2
wget --output-file=$ARCHIVE $ARCHIVE_URL3

### FETCH EXTRA DATA ###

    # create for loop
    #for [ i in 10 ]:


echo "done."
exit 0

# EOF