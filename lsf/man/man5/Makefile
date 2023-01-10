#$Id: Makefile,v 1.1 2007/08/10 15:06:39 tmizan Exp $

TOP = ../../..
include $(TOP)/Make.misc

BASE_MAN5 = install.config.5 lim.acct.5 lsf.acct.5 lsf.cluster.5 \
            lsf.conf.5  lsf.shared.5 res.acct.5

PREFIX = ${INSTALL_PREFIX}

install:
	if [ ! -d $(PREFIX)/usr/share/man/man5 ] ; then \
	   mkdir -p $(PREFIX)/usr/share/man/man5 ; \
	fi
	install -c -m 644 $(BASE_MAN5) $(PREFIX)/usr/share/man/man5
