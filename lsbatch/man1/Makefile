#$Id: Makefile,v 1.2 2007/08/10 14:59:24 tmizan Exp $

TOP = ../..
include $(TOP)/Make.misc

BATCH_MAN1 = bsub.1 bhosts.1 bjobs.1 bkill.1 \
		bmod.1 bparams.1 bpeek.1 bqueues.1 bresume.1 \
		bstop.1 bmgroup.1 busers.1  \
		bchkpnt.1 bmig.1 brestart.1 \
                lsfbatch.1 bbot.1 btop.1 \
                bugroup.1 brequeue.1 

PREFIX = ${INSTALL_PREFIX}

install:
	if [ ! -d $(PREFIX)/usr/share/man/man1 ]; then \
	   mkdir -p $(PREFIX)/usr/share/man/man1 ; \
	fi 
	install -c -m 644 $(BATCH_MAN1) $(PREFIX)/usr/share/man/man1
