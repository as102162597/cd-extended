#!/bin/bash

CDEX_HAS_CB=$(alias | grep '^alias cb=')
CDEX_HAS_CD=$(alias | grep '^alias cd=')
CDEX_HAS_CF=$(alias | grep '^alias cf=')
CDEX_HAS_CV=$(alias | grep '^alias cv=')

if [ -n "$CDEX_HAS_CB" ]; then
    unalias cb
fi

if [ -n "$CDEX_HAS_CD" ]; then
    unalias cd
fi

if [ -n "$CDEX_HAS_CF" ]; then
    unalias cf
fi

if [ -n "$CDEX_HAS_CV" ]; then
    unalias cv
fi

echo "cd-extended has been disabled..."

unset CDEX_HAS_CB
unset CDEX_HAS_CD
unset CDEX_HAS_CF
unset CDEX_HAS_CV
