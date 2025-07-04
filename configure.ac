AC_INIT([everyutil], [1.0], [ilkeroztbm@gmail.com])
AC_PROG_CC
AC_PROG_RANLIB
AC_CHECK_LIB([m], [sin], [], [AC_MSG_ERROR([Math library not found])])
AC_CHECK_PROGS([MAKE], [make gmake], [AC_MSG_ERROR([make not found])])
AC_CONFIG_FILES([Makefile pkgconfig/everyutil.pc])
AC_SUBST([prefix])
AC_SUBST([exec_prefix])
AC_SUBST([libdir])
AC_SUBST([includedir])
AC_OUTPUT