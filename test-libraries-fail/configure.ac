AC_INIT([Test-libraries], [7.2dev])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE

AC_CONFIG_MACRO_DIRS([build-aux/m4])

LT_INIT([disable-static dlopen])

AC_PROG_CC

LT_LIB_DLLOAD

DLLIB=
AC_CHECK_LIB(dl, dlopen, [DLLIB='-ldl'])
AC_SUBST(DLLIB)

AC_MSG_CHECKING([Platform link for $host])
# Use the -no-undefined flag on MS-Windows.  See info node
# `(gnulib)Libtool and Windows'.
case "$host" in *-mingw32 | *-mingw64 | *-cygwin )
  # to be used for shared libraries
  platform_LDFLAGS='-no-undefined'
  ;;
esac
AC_MSG_RESULT([$platform_LDFLAGS])

AC_SUBST([platform_LDFLAGS], [$platform_LDFLAGS])

AC_CONFIG_FILES([Makefile])

AC_OUTPUT
