#!/bin/bash

### COMPILING SCRIPT ###

# COMMANDOS - PROGRAM TO USE THE INTERFACE - COMODOS 
g++ ./ai/system/commandos/commandos.cpp -o ./ai/bin/commandos
./ai/bin/commandos --version
# COMODOS - INTERFACE - USED BY COMMANDOS TO OPERATE ON "MODEL-AI" RUNTIME
g++ ./ai/system/commandos/comodos.cpp -o ./ai/bin/comodos
./ai/bin/comodos --version
### INTEGRATE INTO THE OS FROM SCRIPT (HERE) OR ENABLE FOR (PROGRAM) COMMANDOS OR IN (MODEL-AI) RUNTIME OR (RUN) ###
### ENABLE FOLLOWING COMMANDS BY FREEING THE "if" (to the) "fi" LINES INCLUDING "sudos" FROM THE COMMENTED '#' TO INTEGRATE INTO "/USR/BIN"

#if [ -f "./ai/bin/commandos" && ! -f "/usr/bin/commandos" ]
#  then
#  sudo cp ./ai/bin/commandos /usr/bin/commandos
#  sudo cp ./ai/bin/comodos /usr/bin/comodos
#fi

#sudo 

# EOF