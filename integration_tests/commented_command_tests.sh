#!/bin/sh

INPUTS=('echo #b ' 'echo a || echo b && echo c #&& echo d && echo h' 'echo a && echo c &&  #echo')

.././integration ${INPUTS[2]}
.././integration ${INPUTS[1]}
.././integration ${INPUTS[0]}
