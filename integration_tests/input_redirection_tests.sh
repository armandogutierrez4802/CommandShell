#!/bin/sh

INPUTS=(
'cat < ../names.txt' 
'cat < ../README.md' 
'cat < ../CMakeLists.txt'
)

.././integration ${INPUTS[2]}
.././integration ${INPUTS[1]}
.././integration ${INPUTS[0]}
