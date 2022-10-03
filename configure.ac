#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([Chapter 5: Game State], [0.0.1], [wastegas@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_LANG(C++)
AC_PROG_CXX
m4_include([m4/m4_ax_cxx_compile_stdcxx.m4])
AX_CXX_COMPILE_STDCXX(14)

# Checks for libraries.
PKG_CHECK_MODULES(SDL2, [sdl2])
PKG_CHECK_MODULES(SDL2_IMAGE, [SDL2_image])
PKG_CHECK_MODULES(SDL2_TTF, [SDL2_ttf])
# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile
		 assets/Makefile])
AC_OUTPUT
