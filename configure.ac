AC_INIT([closestring],[1.0],[pvankeymeulen@seanachaidh.be])
AM_INIT_AUTOMAKE([-Wall])
AC_PROG_CXX
AC_CONFIG_HEADERS([config.h])

# Checks for libraries.
AC_CHECK_LIB([cunit], [CU_initialize_registry])

AC_CONFIG_FILES([
	Makefile
	src/Makefile
	tests/Makefile
])

AC_OUTPUT
