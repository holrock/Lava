# $Id: Makefile,v 1.9 2007/08/15 22:18:49 tmizan Exp $

TOP = ..
include $(TOP)/Make.misc

LSF_SUBDIR = intlib lib res lim lsadm lstools pim
LSF_TGT = sintlib slib sres slim slsadm slstools spim

PREFIX = ${INSTALL_PREFIX}

build all: ${LSF_TGT}

slib: 
	cd lib; $(MAKE) 

sintlib:
	cd intlib; $(MAKE)

slim:	
	cd lim; $(MAKE)

spim:	
	cd pim; $(MAKE)

sres:	
	cd res; $(MAKE)

slsadm:	
	cd lsadm; $(MAKE)

slstools:	
	cd lstools; $(MAKE)

install: 
	if [ ! -d $(PREFIX)/usr/include/lsf ]; then \
	   mkdir -p $(PREFIX)/usr/include/lsf ; \
	fi
	install -m 644 lsf.h $(PREFIX)/usr/include/lsf/lsf.h
	@set -x; for i in ${LSF_SUBDIR} man/man1 man/man8 man/man5; do\
	    (cd $$i; $(MAKE) $@ PREFIX=${INSTALL_PREFIX}); done

clean:
	rm -f $(COMCLEAN)
	@set -x; for i in ${LSF_SUBDIR}; do\
	    (if [ -d $$i ]; then cd $$i; $(MAKE) $@; fi;); done

