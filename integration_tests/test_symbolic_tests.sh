#!/bin/sh

INPUTS=('[ -e ../src/ ] && echo path exists' '[ -f ../src/input.cpp ] && echo file exists' '[ -d ../header/ ] && echo directory exists' '[ -e ../sr/ ] || echo invalid path' '[ -f ../header/test.h ] || echo invalid file' '[ -d ../heder/ ] || echo invalid directory' '[ ../src/ ] && echo path exists' '[ ../sr/ ] || echo invalid path')

.././integration ${INPUTS[7]}
.././integration ${INPUTS[6]}
.././integration ${INPUTS[5]}
.././integration ${INPUTS[4]}
.././integration ${INPUTS[3]}
.././integration ${INPUTS[2]}
.././integration ${INPUTS[1]}
.././integration ${INPUTS[0]}
