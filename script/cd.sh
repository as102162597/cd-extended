# This script can only be executed using the dot command.
# It is not recommended to execute this script directly unless you are familiar with its content.

# set variables
CDEX_DIRCTL="/usr/local/share/cd-extended/dirctl"
CDEX_CTLMODE=$1
CDEX_HISTORY=$2
CDEX_HISTDIR=$(dirname $CDEX_HISTORY)
shift
shift

# change directory
CDEX_SOURCE=$(pwd)
builtin cd $@
CDEX_EXITSTAT=$?
CDEX_DEST=$(pwd)

# execute the main process
if [ -f $CDEX_DIRCTL ] && [ -r $CDEX_DIRCTL ] && [ -x $CDEX_DIRCTL ]; then
    if [ -d $CDEX_HISTDIR ] && [ -r $CDEX_HISTDIR ] && [ -x $CDEX_HISTDIR ]; then
        $CDEX_DIRCTL $CDEX_CTLMODE i $CDEX_HISTORY $CDEX_SOURCE $CDEX_DEST >/dev/null 2>&1
    fi
fi

# unset varables
unset CDEX_DIRCTL
unset CDEX_CTLMODE
unset CDEX_HISTORY
unset CDEX_SOURCE
unset CDEX_DEST

# return
case $CDEX_EXITSTAT in
    0)
        unset CDEX_EXITSTAT
        true
        ;;
    *)
        unset CDEX_EXITSTAT
        false
        ;;
esac
