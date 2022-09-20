bin_PROGRAMS = sdl_oop
sdl_oop_SOURCES = \
	game.cpp \
	texturemanager.cpp \
	gameobject.cpp \
	player.cpp \
	main.cpp


sdl_oop_CPPFLAGS = $(SDL2_CFLAGS) $(SDL2_TTF_CFLAGS) -DDATADIR=\"$(pkgdatadir)\"
sdl_oop_LDFLAGS = $(SDL2_LIBS) $(SDL2_IMAGE_LIBS) $(SDL2_TTF_LIBS)
sdl_oop_LDADD = $(SDL2_LIBS) $(SDL2_IMAGE_LIBS) $(SDL2_TTF_LIBS)
