bin_PROGRAMS = sdl_draw
sdl_draw_SOURCES = \
	game.cpp \
	texturemanager.cpp \
	main.cpp


sdl_draw_CPPFLAGS = $(SDL2_CFLAGS) $(SDL2_TTF_CFLAGS) -DDATADIR=\"$(pkgdatadir)\"
sdl_draw_LDFLAGS = $(SDL2_LIBS) $(SDL2_IMAGE_LIBS) $(SDL2_TTF_LIBS)
sdl_draw_LDADD = $(SDL2_LIBS) $(SDL2_IMAGE_LIBS) $(SDL2_TTF_LIBS)
