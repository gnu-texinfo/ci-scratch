
AUTOMAKE_OPTIONS = foreign

ACLOCAL_AMFLAGS = -I build-aux/m4

SUBDIRS = library

noinst_PROGRAMS = prog

prog_SOURCES = prog.c
#prog_LDADD = lib1.la
prog_LDADD = $(DLLIB) $(LIBADD_DLOPEN)
#prog_LDFLAGS = -ldl

# NB with noinst_ prefix dynamic libraries aren't built
lib_LTLIBRARIES = lib1.la

lib1_la_SOURCES = lib1.c
lib1_la_LDFLAGS = -module $(platform_LDFLAGS)

$(top_builddir)/library/lib2.la:
	cd $(top_builddir)/library && $(MAKE) $(AM_MAKEFLAGS) lib2.la

lib1_la_LIBADD = $(top_builddir)/library/lib2.la

TESTS = test_prog.sh
