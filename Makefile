# $Id: Makefile,v 1.8 2007/08/15 22:18:42 tmizan Exp $
############################################################################
#  ------- R E A D   M E   T O   A V O I D    F A I L U R E  --------
#
# All Makefiles in the source tree include the file "Make.def" in this
# directory to get platform-specific definitions.
# You must symbolic link "Make.def" to the correct platform-specific file in
# the config subdirectory.
#
# Targets:
#	make, make all, make build: compile all sources
#	make clean: clean up source tree
#	make cleanall: clean up source and binary release trees
#	
#	make brelease: build and copy binary release into utopia_bin
#	make brel_tar: create tar file of binary release
###########################################################################

#Y O U   D O N ' T   W A N T   T O   C H A N G E   A N Y T H I N G   B E L O W

# Pick up machine-specific definitions
TOP = .
include Make.misc

TOP_DIR = lsf eauth lsbatch chkpnt
TOP_TGT = slsf seauth slsbatch schkpnt

PREFIX = ${INSTALL_PREFIX}

all build:  ${TOP_TGT}

slsf: 
	cd lsf; $(MAKE)

slsbatch:  
	cd lsbatch; $(MAKE)

seauth:
	cd eauth; $(MAKE)

schkpnt:
	cd chkpnt; $(MAKE)

install: 
	set -x; for i in $(TOP_DIR); do \
	( if [ -d $$i ]; then cd $$i; $(MAKE) install PREFIX=${INSTALL_PREFIX}; fi ); done

clean:
	set -x; for i in $(TOP_DIR); do\
	    ( if [ -d $$i ]; then cd $$i; $(MAKE) clean; fi ); done
	rm -f $(COMCLEAN)

cleanall: clean
	rm -rf $(BRELEASE) 

