# $Header: /cvs/CVS/lava_test/lsf/pim/Makefile,v 1.7 2007/08/15 22:18:55 tmizan Exp $
############################################################################
#
# Makefile for PIM
#
###########################################################################

TOP = ../..
include $(TOP)/Make.misc

INTLIB=$(TOP)/lsf/intlib/lsfint.a
LSFLIB=$(TOP)/lsf/lib/liblsf.so

CFLAGS += $(SITE)

LIBS =  $(INTLIB) $(LSFLIB) 
LINKLIBS = $(INTLIB) -L $(TOP)/lsf/lib -llsf $(BSDLIB) -lm -ldl 
OBJS =  pim.main.o pim.os.o

PREFIX = ${INSTALL_PREFIX}

PIM_TGT = pim

all: $(PIM_TGT)

pim: $(OBJS) $(LIBS)
	$(CC) $(LDFLAGS) $(CFLAGS) $(OBJS) $(LINKLIBS) $(OUTF)

$(INTLIB):
	cd ${@D}; ${MAKE}

$(LSFLIB):
	cd ${@D}; ${MAKE}

install: $(PIM_TGT)
	if [ ! -d $(PREFIX)/usr/sbin ]; then \
	   mkdir -p $(PREFIX)/usr/sbin ; \
	fi
	install -m 755 $(PIM_TGT) $(PREFIX)/usr/sbin

clean: 
	rm -f $(COMCLEAN) $(PIM_TGT)


# These dependencies are maintained by hand
PIM = ../../config.h ../lib/lib.pim.h ../lib/lproto.h
PLATFORMS = pim.linux.h
pim.main.o:	$(PIM)
pim.os.o:	$(PIM) $(PLATFORMS)
