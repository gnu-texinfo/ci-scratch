
AUTOMAKE_OPTIONS = foreign

ACLOCAL_AMFLAGS = -I build-aux/m4

noinst_PROGRAMS = prog

prog_SOURCES = prog.c
#prog_LDADD = lib1.la
prog_LDADD = $(DLLIB) $(LIBADD_DLOPEN)
#prog_LDFLAGS = 

# NB with noinst_ prefix dynamic libraries aren't built
lib_LTLIBRARIES = lib1.la lib2.la

lib1_la_SOURCES = lib1.c
lib1_la_LDFLAGS = -module $(platform_LDFLAGS)

lib2_la_SOURCES = lib2.c
lib2_la_LDFLAGS = $(platform_LDFLAGS)

#lib1_la_LIBADD = lib2.la

TESTS = test_prog.sh
