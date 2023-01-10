#**********************************************************
# cshrc.lsf:
#    Sets the C shell user environment for LSF commands
#
#--------------------------------------------------------------------------
# This code gets the binary type when setting LSF user environment.
#---------------------------------------------------------------------------

setenv LSF_TOP /usr
setenv LSF_VERSION 1.0
setenv LSF_BINDIR /usr/bin
setenv LSF_SERVERDIR /usr/sbin
setenv LSF_LIBDIR /usr/lib
setenv XLSF_UIDDIR /usr/lib/uid
setenv LSF_ENVDIR /etc/lava/conf
unsetenv LSF_TOP LSF_VERSION
