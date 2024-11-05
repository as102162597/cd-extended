# This script can only be executed using the dot command.
# It is not recommended to execute this script directly unless you are familiar with its content.

# set variables
CDEX_DIRCTL="/usr/local/share/cd-extended/dirctl"
CDEX_CTLMODE=$1
CDEX_HISTORY=$2
CDEX_HISTDIR=$(dirname $CDEX_HISTORY)
shift
shift

# execute the main process
if [ -f $CDEX_DIRCTL ] && [ -r $CDEX_DIRCTL ] && [ -x $CDEX_DIRCTL ]; then
    if [ -d $CDEX_HISTDIR ] && [ -r $CDEX_HISTDIR ] && [ -x $CDEX_HISTDIR ]; then
        CDEX_SOURCE=$(pwd)
        CDEX_DEST=$CDEX_SOURCE
        CDEX_OUTPUT=$($CDEX_DIRCTL $CDEX_CTLMODE o $CDEX_HISTORY $CDEX_SOURCE $CDEX_DEST $@)
        CDEX_EXITSTAT=$?

        if [ $CDEX_EXITSTAT -eq 0 ]; then
            if [ "${CDEX_OUTPUT:0:1}" = '/' ]; then
                builtin cd $CDEX_OUTPUT
                CDEX_EXITSTAT=$?
                CDEX_DEST=$(pwd)

                if [ $CDEX_EXITSTAT -eq 0 ]; then
                    $CDEX_DIRCTL $CDEX_CTLMODE i $CDEX_HISTORY $CDEX_SOURCE $CDEX_DEST $@
                fi
            else
                echo "$CDEX_OUTPUT"
            fi
        fi
    fi
fi

# unset variables
unset CDEX_DIRCTL
unset CDEX_CTLMODE
unset CDEX_HISTORY
unset CDEX_HISTDIR
unset CDEX_SOURCE
unset CDEX_OUTPUT
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
