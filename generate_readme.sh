#!/bin/bash

echo
echo "GENERATING \"README.MD\" TEXT FILE."

cat component_readme_1.txt > README.MD
cat ./ai/logs/output.log >> README.MD
cat component_readme_1.txt >> README.MD

echo "done."
exit 0