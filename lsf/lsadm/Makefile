# $Id: Makefile,v 1.7 2007/08/15 22:18:54 tmizan Exp $
############################################################################
#
# Makefile for measurement and management programs
#
############################################################################

TOP = ../..
include $(TOP)/Make.misc

.SUFFIXES: .o

INTLIB=$(TOP)/lsf/intlib/lsfint.a
LSFLIB=$(TOP)/lsf/lib/liblsf.so

LIBS =  $(INTLIB) $(LSFLIB) 
LINKLIBS = -L $(TOP)/lsf/lib -llsf $(BSDLIB)

CFLAGS += -I$(TOP) -I$(TOP)/lsf 

OBJS_LSADMIN = lsadmin.o cmd.limcontrol.o cmd.rescontrol.o \
               startup.o

LSADM_TGT = lsadmin

PREFIX = ${INSTALL_PREFIX}

all build:	$(LSADM_TGT)

.c.o):     $<
	$(CC) $(CFLAGS) $(OUTF) -c $<

lsadmin:  $(OBJS_LSADMIN) $(LIBS)
	$(CC) $(LDFLAGS) $(CFLAGS) $(OBJS_LSADMIN) $(INTLIB) $(LINKLIBS) $(OUTF)

$(INTLIB):
	cd ${@D}; $(MAKE)

$(LSFLIB):
	cd ${@D}; $(MAKE)

install: $(LSADM_TGT)
	if [ ! -d $(PREFIX)/usr/sbin ]; then \
	   mkdir -p $(PREFIX)/usr/sbin ; \
	fi
	install -m 755 $(LSADM_TGT) $(PREFIX)/usr/sbin

clean:
	rm -f $(COMCLEAN) $(LSADM_TGT)


# These dependencies are maintained by hand (for now)
lsadmin.$(OEXT) : lsadmin.h ../lsf.h
cmd.limcontrol.$(OEXT) : ../lsf.h
cmd.rescontrol.$(OEXT) : ../lsf.h ../lib/mls.h
startup.$(OEXT) : ../lsf.h ../lib/mls.h

