
AUTOMAKE_OPTIONS = foreign

noinst_PROGRAMS = prog

prog_SOURCES = prog.c
#prog_LDADD = lib1.la
#prog_LDFLAGS = -ldl

# NB with noinst_ prefix dynamic libraries aren't built
lib_LTLIBRARIES = lib1.la lib2.la

lib1_la_SOURCES = lib1.c
lib1_la_LDFLAGS = -module

lib2_la_SOURCES = lib2.c

#lib1_la_LIBADD = lib2.la
