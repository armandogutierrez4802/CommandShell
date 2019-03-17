#!/bin/sh

INPUTS=(
'cat ../names.txt | tr a-z A-Z' 
'cat ../names.txt | tr A-Z a-z' 
'cat < ../names.txt | (tr a-z A-Z > output.txt) || (tr A-Z a-z > output.txt); echo done >> output.txt'
)

.././integration ${INPUTS[2]}
.././integration ${INPUTS[1]}
.././integration ${INPUTS[0]}
