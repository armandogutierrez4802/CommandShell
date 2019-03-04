#!/bin/sh

INPUTS=('(echo a || echo b) && echo c' '((echo a))' 'echo a || (echo b || echo c)' '(echo a && echo b); echo c' '((echo a; echo b) || echo c)' '(((echo a); echo b) || echo c)' 'echo a && ( echo b && echo c ) || echo d' '(((echo a))')

.././integration ${INPUTS[7]}
.././integration ${INPUTS[6]}
.././integration ${INPUTS[5]}
.././integration ${INPUTS[4]}
.././integration ${INPUTS[3]}
.././integration ${INPUTS[2]}
.././integration ${INPUTS[1]}
.././integration ${INPUTS[0]}
