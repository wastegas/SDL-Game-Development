#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([Chapter 2: Drawing], [0.0.0], [wastegas@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX

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
