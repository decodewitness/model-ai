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
