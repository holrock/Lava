############################################################################
#
# Makefile for LIB
#
############################################################################

TOP = ../..
include $(TOP)/Make.misc

.SUFFIXES: .o .So

ARCH=`arch`

STATIC_OBJ = lib.eligible.o lib.init.o lib.lim.o lib.info.o \
       lib.sock.o lib.control.o lib.res.o lib.misc.o \
       lib.xdr.o lib.err.o lib.nios.o lib.term.o \
       lib.tty.o lib.table.o lib.words.o lib.load.o \
       lib.place.o lib.syntax.o lib.rdwr.o lib.sig.o \
       lib.initenv.o lib.tid.o usleep.o \
       whathost.o lib.xdrres.o lib.rf.o lib.xdrlim.o \
       lib.host.o lib.lsf.o lib.priority.o \
       lib.xdrnio.o \
       lib.resctrl.o lib.reslog.o lib.xdrmisc.o \
       lib.xdrrf.o lib.cwd.o lib.errno.o lib.conn.o \
       lib.rwait.o lib.rtask.o lib.rex.o lib.limits.o \
       lib.syslog.o lib.esub.o lib.channel.o \
       lib.eauth.o lib.osal.o \
       lib.confmisc.o lib.conf.o lib.i18n.o lib.pim.o \
       lib.queue.o lib.hosta.o lib.nioback.o lib.rcp.o \
       lib.debug.o lib.wconf.o lib.rmi.o \
       lib.dir.o lib.utmp.o lib.so.o lib.id.o

SHARED_OBJ = lib.eligible.So lib.init.So lib.lim.So lib.info.So \
       lib.sock.So lib.control.So lib.res.So lib.misc.So \
       lib.xdr.So lib.err.So lib.nios.So lib.term.So \
       lib.tty.So lib.table.So lib.words.So lib.load.So \
       lib.place.So lib.syntax.So lib.rdwr.So lib.sig.So \
       lib.initenv.So lib.tid.So usleep.So \
       whathost.So lib.xdrres.So lib.rf.So lib.xdrlim.So \
       lib.host.So lib.lsf.So lib.priority.So \
       lib.xdrnio.So \
       lib.resctrl.So lib.reslog.So lib.xdrmisc.So \
       lib.xdrrf.So lib.cwd.So lib.errno.So lib.conn.So \
       lib.rwait.So lib.rtask.So lib.rex.So lib.limits.So \
       lib.syslog.So lib.esub.So lib.channel.So \
       lib.eauth.So lib.osal.So \
       lib.confmisc.So lib.conf.So lib.i18n.So lib.pim.So \
       lib.queue.So lib.hosta.So lib.nioback.So lib.rcp.So \
       lib.debug.So lib.wconf.So lib.rmi.So \
       lib.dir.So lib.utmp.So lib.so.So lib.id.So

PREFIX = ${INSTALL_PREFIX}

STATIC_LIB = liblsf.a
SHARED_LIB = liblsf.so.1.0.0

all: $(STATIC_LIB) $(SHARED_LIB)

$(STATIC_LIB): $(STATIC_OBJ)
	$(AR) cru $(STATIC_LIB) $(STATIC_OBJ)
	$(RANLIB) $@

$(SHARED_LIB): $(SHARED_OBJ)
	$(CC) -Wl,--hash-style=both -shared -Wl,-export-dynamic,-soname,liblsf.so.1 -o $(SHARED_LIB) $(SHARED_OBJ) -lnsl -lc
	ln -sf $(SHARED_LIB) liblsf.so
	ln -sf $(SHARED_LIB) liblsf.so.1

.c.o:	$<
	$(CC) $(CFLAGS) $(OUTF) -c $<
.c.So:  $<
	$(CC) -fPIC $(CFLAGS) $(OUTF) -c $<

install: 
	if [ "${ARCH}" == "x86_64" ]; then \
	      mkdir -p $(PREFIX)/usr/lib64 ; \
	      install -m 644 $(STATIC_LIB) $(PREFIX)/usr/lib64 ; \
	      install -m 644 $(SHARED_LIB) $(PREFIX)/usr/lib64 ; \
	      ( cd $(PREFIX)/usr/lib64 ; ln -sf $(SHARED_LIB) liblsf.so) ; \
	else \
	      mkdir -p $(PREFIX)/usr/lib ; \
	      install -m 644 $(STATIC_LIB) $(PREFIX)/usr/lib ; \
	      install -m 644 $(SHARED_LIB) $(PREFIX)/usr/lib ; \
	      ( cd $(PREFIX)/usr/lib ; ln -sf $(SHARED_LIB) liblsf.so) ; \
	fi

clean:
	rm -f $(COMCLEAN) $(LIB) liblsf*.so* liblsf.a


# These dependencies are maintained by hand
# lib.h and the files it includes
LIB_H = lib.h ../lsf.h ../lim/limout.h ../../config.h lproto.h lsi18n.h
$(OBJS):		$(LIB_H)
lib.syslog.o:    	$(LIB_H) ../intlib/intlib.h
lib.conn.o:		$(LIB_H) lib.table.h
lib.control.o:		$(LIB_H) lib.xdr.h
lib.eligible.o:		$(LIB_H) lib.table.h
lib.err.o:		$(LIB_H)
lib.info.o:		$(LIB_H) lib.xdr.h
lib.init.o:		$(LIB_H) lib.queue.h mls.h
lib.lim.o:		$(LIB_H)
lib.load.o:		$(LIB_H) lib.xdr.h 
lib.rdwr.o:		$(LIB_H) lib.xdr.h
lib.misc.o:		$(LIB_H)
lib.place.o:		$(LIB_H) 
lib.res.o:		$(LIB_H) ../res/resout.h ../res/nios.h lib.hdr.h \
			lib.xdrres.h ../res/rescom.h lib.xdr.h \
		        lib.queue.h
lib.sock.o:		$(LIB_H)
lib.syntax.o:		$(LIB_H) 
lib.table.o:		$(LIB_H) lib.table.h
lib.queue.o:      	$(LIB_H) lib.queue.h
lib.term.o:		$(LIB_H) ../res/resout.h lib.xdrres.h lib.hdr.h \
			lib.xdr.h
lib.sig.o:		../../config.h
lib.words.o:		$(LIB_H) lib.words.h
lib.xdr.o:		$(LIB_H) lib.xdr.h 
lib.xdrlim.o:   	$(LIB_H) lib.xdrlim.h
lib.xdrres.o:   	$(LIB_H) lib.xdrres.h lib.hdr.h lib.xdr.h \
			lib.rf.h
usleep.o:		../../config.h
lib.priority.o:		../../config.h
lib.rf.o:		$(LIB_H) ../res/resout.h ../res/nios.h lib.hdr.h \
                	lib.xdrres.h ../res/rescom.h lib.xdr.h lib.rf.h
lib.nios.o:     $(LIB_H)
lib.xdrmisc.o:  $(LIB_H) lib.xdr.h 
lib.xdrnio.o:	$(LIB_H)
lib.resctrl.o:	$(LIB_H) 
lib.reslog.o:	$(LIB_H) 
lib.xdrrf.o:	$(LIB_H) lib.xdr.h
lib.esub.o:	$(LIB_H) mls.h
lib.eauth.o:	$(LIB_H) mls.h
lib.channel.o:  $(LIB_H) lib.channel.h
lib.confmisc.o: $(LIB_H) 
lib.conf.o:     $(LIB_H) lib.conf.h
lib.pim.o:      $(LIB_H) lib.pim.h
lib.osal.o:     $(LIB_H) lib.osux.h
lib.host.o:     $(LIB_H) mls.h
lib.dir.o:      $(LIB_H) mls.h
lib.rex.o:      $(LIB_H) mls.h
lib.rtask.o:    $(LIB_H) lib.queue.h mls.h ../res/nios.h ../res/resout.h
lib.so.o:       lib.so.h
lib.id.o:       $(LIB_H)
