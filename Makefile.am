ACLOCAL_AMFLAGS = -I m4
AM_CFLAGS = -fPIC -DEVERYUTIL_BUILD -Wall -O2 $(shell find include -type d -name "*" -exec echo -I{} \;)
AM_LDFLAGS = -lm

lib_LTLIBRARIES = libeveryutil.la
libeveryutil_la_SOURCES = $(shell find src -name '*.c')
libeveryutil_la_LDFLAGS = -shared

include_HEADERS = $(shell find include -name '*.h')

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = pkgconfig/everyutil.pc

TESTS = $(patsubst tests/%.c,build/testExecutables/%.exe,$(shell find tests -name '*.c'))
check_PROGRAMS = $(TESTS)

build/testExecutables/%.exe: build/%.test.o libeveryutil.la
	@mkdir -p $(dir $@)
	$(CC) $(AM_CFLAGS) $< -L. -leveryutil -o $@ $(AM_LDFLAGS)

build/%.test.o: tests/%.c
	@mkdir -p $(dir $@)
	$(CC) $(AM_CFLAGS) -c $< -o $@