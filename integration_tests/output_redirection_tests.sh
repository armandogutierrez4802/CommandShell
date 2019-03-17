#!/bin/sh

INPUTS=(
'cat ../names.txt > namesTest.txt' 
'cat ../README.md > readmeTest.txt' 
'cat ../CMakeLists.txt > cmakeTest.txt'
)

.././integration ${INPUTS[2]}
.././integration ${INPUTS[1]}
.././integration ${INPUTS[0]}
