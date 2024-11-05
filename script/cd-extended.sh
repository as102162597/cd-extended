#!/bin/bash

# set variables
CDEX_DIRCTL="/usr/local/share/cd-extended/dirctl"
CDEX_CDSHELL="/usr/local/share/cd-extended/cd.sh"
CDEX_EXSHELL="/usr/local/share/cd-extended/ex.sh"
CDEX_HISTDIR="$HOME/.local/share/cd-extended/history"
CDEX_HISTORY="$(whoami)-$(date +%s%9N)-$(uuidgen | cut -c25-36).hist"
CDEX_LIFEDAY=180

# create a directory for the history file
mkdir -p $CDEX_HISTDIR

# delete the history file that hasn't been modified in the past half year
find $CDEX_HISTDIR -type f -mtime +$CDEX_LIFEDAY -exec rm -f {} \;

# initialize the history file
echo 1 >> $CDEX_HISTDIR/$CDEX_HISTORY
echo "1 $(pwd)" >> $CDEX_HISTDIR/$CDEX_HISTORY

# declare aliases
if [ -f $CDEX_DIRCTL ] && [ -x $CDEX_DIRCTL ]; then
    if [ -f $CDEX_CDSHELL ] && [ -x $CDEX_CDSHELL ]; then
        if [ -f $CDEX_EXSHELL ] && [ -x $CDEX_EXSHELL ]; then
            alias cd=". $CDEX_CDSHELL cd $CDEX_HISTDIR/$CDEX_HISTORY"
            alias cb=". $CDEX_EXSHELL cb $CDEX_HISTDIR/$CDEX_HISTORY"
            alias cf=". $CDEX_EXSHELL cf $CDEX_HISTDIR/$CDEX_HISTORY"
            alias cv=". $CDEX_EXSHELL cv $CDEX_HISTDIR/$CDEX_HISTORY"
        fi
    fi
fi

# unset variables
unset CDEX_DIRCTL
unset CDEX_CDSHELL
unset CDEX_EXSHELL
unset CDEX_HISTDIR
unset CDEX_HISTORY
unset CDEX_LIFEDAY
