#!/bin/bash

### REPLACES THE START SCRIPT WITH THE RUNTIME VERSION ###
cat 'ai/bin/script/dont_run_this.$$$' > '../../../start'

### GIVES THE SCRIPT RUN PERMISSION ###
chmod +x '../../../start'

exit