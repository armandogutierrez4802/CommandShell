#!/bin/sh

INPUTS=('echo a && exit' ' echo b || exit' 'exit && echo b' 'exit')

.././integration ${INPUTS[3]}
.././integration ${INPUTS[2]}
.././integration ${INPUTS[1]}
.././integration ${INPUTS[0]}
