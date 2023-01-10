#**********************************************************
# lava.sh:
#   Setup Lava environment variables
#********************************************************** 
#--------------------------------------------------------------------------
# This code gets the binary type when setting LSF user environment.
#---------------------------------------------------------------------------

LSF_VERSION=1.0
LSF_TOP=/usr
LSF_BINDIR=/usr/bin
LSF_SERVERDIR=/usr/sbin
LSF_LIBDIR=/usr/lib
#XLSF_UIDDIR=/usr/lib/uid
LSF_ENVDIR=/etc/lava/conf
export LSF_SERVERDIR LSF_BINDIR LSF_LIBDIR XLSF_UIDDIR LSF_ENVDIR 
