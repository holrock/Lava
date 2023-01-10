#$Id: Makefile,v 1.3 2007/08/10 17:22:13 tmizan Exp $

TOP = ../..
include $(TOP)/Make.misc

PREFIX = ${INSTALL_PREFIX}

install:
	if [ ! -d $(PREFIX)/usr/share/man/man8 ]; then \
	   mkdir -p $(PREFIX)/usr/share/man/man8 ; \
	fi
	install -c -m 644 *.8 $(BATCH_MAN8) $(PREFIX)/usr/share/man/man8
