# dwm - dynamic window manager
# See LICENSE file for copyright and license details.

include config.mk

SRC = drw.c dwm.c util.c
OBJ = ${SRC:.c=.o}

all: options dwm

options:
	@echo dwm build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	${CC} -c ${CFLAGS} $<

${OBJ}: config.h config.mk

config.h:
	cp config.def.h $@

dwm: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS} -lm

clean:
	rm -f config.h
	rm -f dwm ${OBJ} dwm-${VERSION}.tar.gz

dist: clean
	mkdir -p dwm-${VERSION}
	cp -R LICENSE Makefile README config.def.h config.mk\
		dwm.1 drw.h util.h ${SRC} dwm.png transient.c dwm-${VERSION}
	tar -cf dwm-${VERSION}.tar dwm-${VERSION}
	gzip dwm-${VERSION}.tar
	rm -rf dwm-${VERSION}

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f dwm ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/dwm
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	sed "s/VERSION/${VERSION}/g" < dwm.1 > ${DESTDIR}${MANPREFIX}/man1/dwm.1
	chmod 644 ${DESTDIR}${MANPREFIX}/man1/dwm.1
	ln -fs $(CURDIR)/scripts/dwmc $(DESTDIR)$(PREFIX)/bin
	ln -fs $(CURDIR)/scripts/dwm-termcmd $(DESTDIR)$(PREFIX)/bin
	ln -fs $(CURDIR)/scripts/dwm-switchmonitor $(DESTDIR)$(PREFIX)/bin
	ln -fs $(CURDIR)/scripts/dwm-changewallpaper $(DESTDIR)$(PREFIX)/bin
	ln -fs $(CURDIR)/scripts/dwm-defaultwallpaper $(DESTDIR)$(PREFIX)/bin
	ln -fs $(CURDIR)/scripts/dwm-flameshot $(DESTDIR)$(PREFIX)/bin
	ln -fs $(CURDIR)/scripts/dwm-flameshotocr $(DESTDIR)$(PREFIX)/bin
	ln -fs $(CURDIR)/scripts/dwm-flameshotqr $(DESTDIR)$(PREFIX)/bin
	ln -fs $(CURDIR)/scripts/dwm-sp0 $(DESTDIR)$(PREFIX)/bin
	ln -fs $(CURDIR)/scripts/dwm-sp1 $(DESTDIR)$(PREFIX)/bin
	ln -fs $(CURDIR)/scripts/dwm-sp2 $(DESTDIR)$(PREFIX)/bin
	ln -fs $(CURDIR)/scripts/dwm-sp3 $(DESTDIR)$(PREFIX)/bin
	ln -fs $(CURDIR)/scripts/dwm-rofi $(DESTDIR)$(PREFIX)/bin
	ln -fs $(CURDIR)/scripts/dwm-rofirun $(DESTDIR)$(PREFIX)/bin
	ln -fs $(CURDIR)/scripts/dwm-rofisearch $(DESTDIR)$(PREFIX)/bin
	ln -fs $(CURDIR)/scripts/dwm-rofipaste $(DESTDIR)$(PREFIX)/bin
	ln -fs $(CURDIR)/scripts/dwm-roficlipster $(DESTDIR)$(PREFIX)/bin
	ln -fs $(CURDIR)/scripts/dwm-titlemenu $(DESTDIR)$(PREFIX)/bin
	ln -fs $(CURDIR)/scripts/dwm-rootmenu $(DESTDIR)$(PREFIX)/bin
	ln -fs $(CURDIR)/scripts/dwm-toggletouchpad $(DESTDIR)$(PREFIX)/bin
	ln -fs $(CURDIR)/scripts/dwm-clearcache $(DESTDIR)$(PREFIX)/bin
	ln -fs $(CURDIR)/scripts/dwm-pickcolor $(DESTDIR)$(PREFIX)/bin
	ln -fs $(CURDIR)/scripts/dwm-processurgentwindow $(DESTDIR)$(PREFIX)/bin
	ln -fs $(CURDIR)/scripts/dwm-status $(DESTDIR)$(PREFIX)/bin

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/dwm\
		${DESTDIR}${MANPREFIX}/man1/dwm.1
	rm -f $(DESTDIR)$(PREFIX)/bin/dwmc
	rm -f $(DESTDIR)$(PREFIX)/bin/dwm-termcmd
	rm -f $(DESTDIR)$(PREFIX)/bin/dwm-switchmonitor
	rm -f $(DESTDIR)$(PREFIX)/bin/dwm-changewallpaper
	rm -f $(DESTDIR)$(PREFIX)/bin/dwm-defaultwallpaper
	rm -f $(DESTDIR)$(PREFIX)/bin/dwm-flameshot
	rm -f $(DESTDIR)$(PREFIX)/bin/dwm-flameshotocr
	rm -f $(DESTDIR)$(PREFIX)/bin/dwm-flameshotqr
	rm -f $(DESTDIR)$(PREFIX)/bin/dwm-sp0
	rm -f $(DESTDIR)$(PREFIX)/bin/dwm-sp1
	rm -f $(DESTDIR)$(PREFIX)/bin/dwm-sp2
	rm -f $(DESTDIR)$(PREFIX)/bin/dwm-sp3
	rm -f $(DESTDIR)$(PREFIX)/bin/dwm-rofi
	rm -f $(DESTDIR)$(PREFIX)/bin/dwm-rofirun
	rm -f $(DESTDIR)$(PREFIX)/bin/dwm-rofisearch
	rm -f $(DESTDIR)$(PREFIX)/bin/dwm-rofipaste
	rm -f $(DESTDIR)$(PREFIX)/bin/dwm-roficlipster
	rm -f $(DESTDIR)$(PREFIX)/bin/dwm-titlemenu
	rm -f $(DESTDIR)$(PREFIX)/bin/dwm-rootmenu
	rm -f $(DESTDIR)$(PREFIX)/bin/dwm-toggletouchpad
	rm -f $(DESTDIR)$(PREFIX)/bin/dwm-clearcache
	rm -f $(DESTDIR)$(PREFIX)/bin/dwm-pickcolor
	rm -f $(DESTDIR)$(PREFIX)/bin/dwm-processurgentwindow
	rm -f $(DESTDIR)$(PREFIX)/bin/dwm-status

.PHONY: all options clean dist install uninstall
