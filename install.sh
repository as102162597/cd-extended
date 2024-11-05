#!/bin/bash

CDEX_HAS_CB=$(alias | grep '^alias cb=')
CDEX_HAS_CD=$(alias | grep '^alias cd=')
CDEX_HAS_CF=$(alias | grep '^alias cf=')
CDEX_HAS_CV=$(alias | grep '^alias cv=')

if [ -z "$CDEX_HAS_CB" ]; then
    . script/cd-extended.sh
fi

if [ -z "$CDEX_HAS_CD" ]; then
    . script/cd-extended.sh
fi

if [ -z "$CDEX_HAS_CF" ]; then
    . script/cd-extended.sh
fi

if [ -z "$CDEX_HAS_CV" ]; then
    . script/cd-extended.sh
fi

echo "cd-extended has been enabled."
echo "Try using 'cb -h', 'cf -h' or 'cv -h' for more information."

unset CDEX_HAS_CB
unset CDEX_HAS_CD
unset CDEX_HAS_CF
unset CDEX_HAS_CV
