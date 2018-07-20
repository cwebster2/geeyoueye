# Process this file with autoconf to produce a configure script.
AC_INIT(geeyoueye, 0.4.2, casey@trifocus.net)
AC_CANONICAL_TARGET
AC_CONFIG_SRCDIR(config.h.in)
AM_CONFIG_HEADER(config.h)
AM_INIT_AUTOMAKE(geeyoueye, 0.4.2)

AC_LANG_CPLUSPLUS

CCW_CFLAGS

# Checks for programs.
AC_PROG_AWK
AC_PROG_CXX
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S

CCW_PROG_QTMT

# Checks for libraries.

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS(arpa/inet.h fcntl.h netinet/in.h stdint.h stdlib.h string.h sys/socket.h unistd.h)

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_CHECK_TYPE(uint8_t, unsigned char)
AC_CHECK_TYPE(uint32_t, unsigned int)

# Checks for library functions.
AC_FUNC_MALLOC

save_LIBS=$LIBS
AC_SEARCH_LIBS(socket,socket)
testtool_LIBS=$LIBS
LIBS=$save_LIBS
AC_SUBST(testtool_LIBS)

AC_CONFIG_FILES(Makefile
                 src/Makefile
                 testtools/Makefile)
AC_OUTPUT
