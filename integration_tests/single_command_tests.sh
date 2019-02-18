#!/bin/sh

INPUTS=('echo a' 'ls' 'git status')

.././integration ${INPUTS[2]}
.././integration ${INPUTS[1]}
.././integration ${INPUTS[0]}
