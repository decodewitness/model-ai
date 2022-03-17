#!/usr/bin/bash

### PYTUBE INSTALLATION SCRIPT
echo
echo "~!~ I need SUDO to install \"Python3\" and \"python3-pip\"."
echo
sudo apt-get install python3 python3-pip
echo
echo "~:now running \"pip\" to install \"Pytube\"."
pip install pytube
echo
echo "~:moving pytube to the \"/usr/bin\" directory."
sudo mv ~/.local/bin/pytube /usr/bin/pytube
echo
### create evidence that pytube was installed.
touch ai/lib/.pyt
echo "~:done."
echo

### eof