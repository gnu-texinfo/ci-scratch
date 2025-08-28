AC_INIT([Test-libraries], [7.2dev])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE

LT_INIT([disable-static dlopen])

LT_LIB_DLLOAD

AC_PROG_CC

AC_MSG_CHECKING([Platform link for $host])
# Use the -no-undefined flag on MS-Windows.  See info node
# `(gnulib)Libtool and Windows'.
case "$host" in *-mingw32 | *-mingw64 | *-cygwin )
  # to be used for shared libraries
  platform_LDFLAGS='-no-undefined' 
  ;;
esac
AC_MSG_RESULT([$platform_LDFLAGS])


AC_CONFIG_FILES([Makefile])

AC_OUTPUT
