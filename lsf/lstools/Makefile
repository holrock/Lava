# $Id: Makefile,v 1.12 2007/08/15 22:18:55 tmizan Exp $
############################################################################
#
# Makefile for Utility programs
#
############################################################################

TOP = ../..
include $(TOP)/Make.misc

.SUFFIXES: .o

INTLIB=$(TOP)/lsf/intlib/lsfint.a
LSFLIB=$(TOP)/lsf/lib/liblsf.so

LIBS = $(INTLIB) $(LSFLIB)
LINKLIB = $(INTLIB) -L $(TOP)/lsf/lib -llsf

OBJS = lsplace.o lseligible.o lsload.o \
       lsloadadj.o lsid.o lshosts.o \
       lsinfo.o \
       lsmon.o lsacct.o \
       lsrcp.o

CMDS = lsplace lseligible lsload \
       lsloadadj lsid lshosts \
       lsinfo lsmon \
       lsacct lsrcp

PREFIX = ${INSTALL_PREFIX}

all: $(CMDS)

.c.o : $<
	$(CC) $(CFLAGS) $(OUTF) -c $<

lsplace: lsplace.o $(LIBS)
	$(CC) $(LDFLAGS) $(CFLAGS) lsplace.o $(LINKLIB) $(OUTF)

lseligible: lseligible.o $(LIBS)
	$(CC) $(LDFLAGS) $(CFLAGS) lseligible.o $(LINKLIB) $(OUTF)

lsload:	lsload.o load.o $(LIBS)
	$(CC) $(LDFLAGS) $(CFLAGS) lsload.o load.o $(LINKLIB) $(OUTF)

lsloadadj: lsloadadj.o $(LIBS)
	$(CC) $(LDFLAGS) $(CFLAGS) lsloadadj.o $(LINKLIB) $(OUTF)

lsid:	lsid.o $(LIBS)
	$(CC) $(LDFLAGS) $(CFLAGS) lsid.o $(LINKLIB) $(OUTF)

lslockhost:	lslockhost.o $(LIBS)
	$(CC) $(LDFLAGS) $(CFLAGS) lslockhost.o $(LINKLIB) $(OUTF)

lsunlockhost:	lsunlockhost.o $(LIBS)
	$(CC) $(LDFLAGS) $(CFLAGS) lsunlockhost.o $(LINKLIB) $(OUTF)

lshosts: lshosts.o $(LIBS)
	$(CC) $(LDFLAGS) $(CFLAGS) lshosts.o $(LINKLIB) $(OUTF)

lsinfo:	lsinfo.o $(LIBS)
	$(CC) $(LDFLAGS) $(CFLAGS) lsinfo.o $(LINKLIB) $(OUTF)

lsmon: lsmon.o load.o $(LIBS)
	$(CC) $(LDFLAGS) $(CFLAGS) lsmon.o load.o $(LINKLIB) -lncurses $(OUTF)

lsacct: lsacct.o $(LIBS)
	$(CC) $(LDFLAGS) $(CFLAGS) lsacct.o $(LINKLIB) $(OUTF)

lsrcp:	lsrcp.o $(LIBS)
	$(CC) $(LDFLAGS) $(CFLAGS) lsrcp.o $(LINKLIB) $(BSDLIB) $(OUTF)

$(INTLIB):
	cd ${@D}; $(MAKE)

$(LSFLIB):
	cd ${@D}; $(MAKE)

install: $(CMDS)
	if [ ! -d $(PREFIX)/usr/bin ]; then \
	   mkdir -p $(PREFIX)/usr/bin ; \
	fi
	install -m 755 $(CMDS) $(PREFIX)/usr/bin

clean:
	rm -f $(COMCLEAN) ${CMDS}


# These dependencies are maintained by hand
lseligible.$(OEXT):	../lsf.h ../../config.h
lshosts.$(OEXT):	../lsf.h
lsid.$(OEXT):	../lib/lproto.h ../lib/lib.table.h ../lsf.h
lsinfo.$(OEXT):	../lsf.h
lsload.$(OEXT):	../../config.h ../lib/lproto.h ../lib/lib.table.h ../lsf.h
lsloadadj.$(OEXT):	../../config.h ../lsf.h
lslockhost.$(OEXT):	../lsf.h
lsplace.$(OEXT):	../../config.h ../lsf.h
lsunlockhost.$(OEXT):	../lsf.h
lsmon.$(OEXT):        ../lsf.h ../../config.h
load.$(OEXT):         ../lsf.h ../../config.h
