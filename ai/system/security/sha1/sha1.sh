#!/bin/bash

echo
echo "~:initializing script."
echo "~:compiling \"sha1.cpp\"."

# compile here
g++ -Wall -Wextra -Werror ai/system/security/sha1/sha1.cpp -Lopenssl/openssl-0.9.8k/ -lssl -lcrypto -Iopenssl/openssl-0.9.8k/include -o ai/bin/sha1

if [ -f "ai/bin/sha1" ]
  then
  # finished compiling
  echo "~:finished compiling: \"sha1.cpp\"."
  else
  # failed compiling
  echo "~!!!~ failed compiling: \"sha1.cpp\"."
fi

echo
echo "done."
# end of script
exit 0

# EOF 