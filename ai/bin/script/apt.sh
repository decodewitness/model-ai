### set permissions
echo
if [ -f "ai/bin/script/perm.sh" ]
  then
  echo "~:setting permissions in a script."
  chmod +x ai/bin/script/perm.sh
  ai/bin/script/perm.sh
  echo
fi

### update libraries for installation
echo "~:!:~ now will SUDO ;; update libraries here and install prerequisites:"
echo
sudo apt update
echo

### install GCC compiler
echo "~:checking for GCC compiler."
if [ -f "/usr/bin/gcc" ]
then
  echo "-/- found GCC compiler"
else
  echo "-/- could not find GCC compiler"
  echo "-/- installing GCC compiler"
  echo "~!~ I need SUDO to install \"GCC\", else press CTRL+C and install GCC manually."
  sudo apt -y install gcc
fi

### install Curl libraries
echo
echo "!~ I need your SUDO to install \"libcurl4-openssl-dev\", else press CTRL + C, and then install \"libcurl4-openssl-dev\" manually with APT."
echo

echo "~:installing Curl libraries"
sudo apt -y install libcurl4-openssl-dev

echo
echo "~:(+one time runscript [that deletes its*elf])"
#!/bin/bash

# // AI/BIN/SCRIPT/APT.SH -- USED BY "MODEL-AI/RUN" (MAIN RUN SCRIPT)
  # // runs libraries from apt  # // installs libraries

if [ -f "./ai/bin/script/script.sh" ]
  then
  echo
  echo "(executing script)"
  chmod u+x ./ai/bin/script/script.sh
  ./ai/bin/script/script.sh | tee ./ai/log/runtime.txt
fi
echo "~:done."
#pwd

### install libssl-dev
echo
echo "~!~ I need SUDO to install \"libssl-dev\", \"libsdl2-dev\", \"libsdl2-mixer-dev\", \"libsdl2-net-dev\", \"libsdl2-ttf-dev\", \"libsdl2-image-dev\", \"libsdl2-gfx-dev\", and \"libasound2-dev\"."
echo
echo "~:installing \"libssl-dev\"."
echo
sudo apt -y install libssl-dev libasound2-dev libsdl2-dev libsdl2-mixer-dev libsdl2-net-dev libsdl2-ttf-dev libsdl2-image-dev libsdl2-gfx-dev
echo "~:done."

echo
echo "~:installing speech/audio dependencies."
echo
### install PyAudio requirements
echo
echo "~!~ I need SUDO to install \"portaudio19-dev\" && \"python-all-dev\" for support for \"PyAudio\"."
sudo apt-get install portaudio19-dev python-all-dev
echo
echo "IF PyAudio FAILS TO INSTALL YOU CAN TRY UNCOMMENTING THE NEXT LINE, THEN IT SHOULD WORK".
###IF PyAudio FAILS TO INSTALL YOU CAN TRY UNCOMMENTING THE NEXT LINE, THEN IT SHOULD WORK

#sudo apt install libasound-dev portaudio19-dev libportaudio2 libportaudiocpp0 ffmpeg libav-tools
echo "~:installing \"SpeechRecognition\", \"pyttsx3\", \"pyaudio\", \"pywhatkit\", \"wikipedia\", \"pyjokes\"."
echo
pip install SpeechRecognition
pip install pyttsx3
pip3 install pyaudio
pip install pywhatkit
pip install wikipedia
pip install pyjokes

echo
echo "~:done."
echo