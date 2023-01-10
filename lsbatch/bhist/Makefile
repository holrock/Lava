###########################################################################
# $Id: Makefile,v 1.5 2007/08/15 22:18:43 tmizan Exp $
#
# Makefile for Lsbatch - BHIST Command
#
###########################################################################
TOP = ../..
include $(TOP)/Make.misc

.SUFFIXES: .o

INTLIB=$(TOP)/lsf/intlib/lsfint.a
LSFLIB=$(TOP)/lsf/lib/liblsf.so
LSBLIB=$(TOP)/lsbatch/lib/liblsfbat.so

LIBS = -L $(TOP)/lsf/lib -llsf -L $(TOP)/lsbatch/lib -llsfbat $(INTLIB) $(BSDLIB) 

CFLAGS = -I$(TOP)

OBJS_BHIST = bhist.o read.event.o ../cmd/cmd.job.o \
     ../cmd/cmd.misc.o ../cmd/cmd.jobid.o ../cmd/cmd.prt.o \
     ../cmd/cmd.err.o ../cmd/cmd.hist.o

PREFIX = ${INSTALL_PREFIX} 

TGT = bhist

build all:	$(TGT)

.c.o:     $<
	$(CC) $(CFLAGS) $(OUTF) -c $<

bhist: $(OBJS_BHIST) $(INTLIB) $(LSFLIB) $(LSBLIB)
	$(CC) $(LDFLAGS) $(CFLAGS) $(OBJS_BHIST) $(LIBS) $(OUTF)

$(INTLIB):
	cd ${@D}; $(MAKE)

$(LSFLIB):
	cd ${@D}; $(MAKE)

$(LSBLIB):
	cd ${@D}; $(MAKE)

install: build
	@if [ ! -d $(PREFIX)/usr/bin ]; then \
	   mkdir -p $(PREFIX)/usr/bin ; \
	fi
	install -m 755 $(TGT) $(PREFIX)/usr/bin

clean: 
	rm -f $(COMCLEAN) $(TGT) 


# These dependencies must be maintained by hand (for now)
bhist.o read.event.o:	bhist.h ../lsbatch.h ../../lsf/lsf.h 
