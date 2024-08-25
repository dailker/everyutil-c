AC_INIT([everyutil], [1.0.0], [your@email.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_CONFIG_SRCDIR([src/array/array_cumulative_product.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_RANLIB

# Checks for libraries.
# (add any library checks here if needed)

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h stdio.h string.h])

# Set installation directories
AC_PREFIX_DEFAULT(/usr/local)

# Substitute variables for Makefile.in
AC_SUBST([CC])
AC_SUBST([CFLAGS])
AC_SUBST([LDFLAGS])
AC_SUBST([prefix])
AC_SUBST([exec_prefix])
AC_SUBST([libdir])
AC_SUBST([includedir])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
