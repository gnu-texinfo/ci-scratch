
# NB with noinst_ prefix dynamic libraries aren't built
lib_LTLIBRARIES = lib2.la

lib2_la_SOURCES = lib2.c
lib2_la_LDFLAGS = $(platform_LDFLAGS) module -avoid-version \
                          -export-dynamic
