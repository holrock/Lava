#$Id: Makefile,v 1.1 2007/08/10 15:06:59 tmizan Exp $

TOP = ../../..
include $(TOP)/Make.misc

BASE_MAN8 = lim.8 lsfinstall.8 nios.8 res.8 eauth.8 lsadmin.8 pim.8

PREFIX = ${INSTALL_PREFIX}

install:
	if [ ! -d $(PREFIX)/usr/share/man/man8 ]; then \
	   mkdir -p $(PREFIX)/usr/share/man/man8 ; \
	fi
	install -c -m 644 $(BASE_MAN8) $(PREFIX)/usr/share/man/man8
