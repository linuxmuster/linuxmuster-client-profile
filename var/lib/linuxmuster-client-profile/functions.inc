# Functions for use with the linuxmuster-client-profile package
# Frank Schiebel <frank@linuxmuster.net>
# 14.04.2012
# GPL v2

msg2log() {
    logger -t linuxmuster-client "$1" "$2"
}

get_environment() {
    USER=$1
    VOLUME=$2
    MNTPT=$3
    OPTIONS=$4
    SERVER=$5

    local TEMP=`getent passwd $USER`

    NUMUID=`echo $TEMP | cut -d: -f 3`
    NUMPRIGID=`echo $TEMP | cut -d: -f 4`
    FULLNAME=`echo $TEMP | cut -d: -f 5`
    HOMEDIR=`echo $TEMP | cut -d: -f 6`
    LOGINSHELL=`echo $TEMP | cut -d: -f 7`
}

# Reads simple config file with one value per line,
# ignoring lines starting with a '#'
#
# @arg Configfile
# @ret White space separated list of items

read_simple_config() {
    configlines=$(egrep -v '^\s*#' $1)
    return $configlines
}
