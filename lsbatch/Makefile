#$Id: Makefile,v 1.4 2007/08/10 14:57:46 tmizan Exp $

TOP = ..
include $(TOP)/Make.misc

LSB_SUBDIR = lib daemons cmd bhist 
LSB_TGT = slib sdaemons scmd sbhist 

build all: ${LSB_TGT}

PREFIX = ${INSTALL_PREFIX}

slib: 
	cd lib; $(MAKE)

sdaemons: 
	cd daemons; $(MAKE)

scmd: 
	cd cmd; $(MAKE)

sbhist: 
	cd bhist; $(MAKE)

clean:
	rm -f $(COMCLEAN)
	@for d in $(LSB_SUBDIR); do (if [ -d $$d ]; then \
	    echo "cd $$d; $(MAKE) $@"; cd $$d; $(MAKE) $@; fi); done

install: 
	@for d in ${LSB_SUBDIR} man1 man5 man8; do\
	    (echo "cd $$d; $(MAKE) $@ PREFIX=$(INSTALL_PREFIX)"; cd $$d; $(MAKE) $@ PREFIX=$(INSTALL_PREFIX)); done
	if [ ! -d $(PREFIX)/usr/include/lsf ]; then \
	   mkdir -p $(PREFIX)/usr/include/lsf ; \
	fi
	install -m 644 lsbatch.h $(PREFIX)/usr/include/lsf/lsbatch.h
