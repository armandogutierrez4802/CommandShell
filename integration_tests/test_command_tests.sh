#!/bin/sh

INPUTS=('test -e src/ && echo path exists' 'test -f src/input.cpp && echo file exists' 'test -d header/ && echo directory exists' 'test -e sr/ || echo invalid path' 'test -f header/test.h || echo invalid file' 'test -d heder/ || echo invalid directory' 'test src/ && echo path exists' 'test sr/ || echo invalid path')

.././integration ${INPUTS[7]}
.././integration ${INPUTS[6]}
.././integration ${INPUTS[5]}
.././integration ${INPUTS[4]}
.././integration ${INPUTS[3]}
.././integration ${INPUTS[2]}
.././integration ${INPUTS[1]}
.././integration ${INPUTS[0]}
