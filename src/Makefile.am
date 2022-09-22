bin_PROGRAMS = sdl_input
sdl_input_SOURCES = \
	game.cpp \
	texturemanager.cpp \
	loaderparams.h \
	gameobject.h \
	sdlgameobject.cpp \
	player.cpp \
	enemy.cpp \
	main.cpp


sdl_input_CPPFLAGS = $(SDL2_CFLAGS) $(SDL2_TTF_CFLAGS) -DDATADIR=\"$(pkgdatadir)\"
sdl_input_LDFLAGS = $(SDL2_LIBS) $(SDL2_IMAGE_LIBS) $(SDL2_TTF_LIBS)
sdl_input_LDADD = $(SDL2_LIBS) $(SDL2_IMAGE_LIBS) $(SDL2_TTF_LIBS)
