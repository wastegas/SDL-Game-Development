bin_PROGRAMS = sdl_states
sdl_states_SOURCES = \
	main.cpp \
	inputhandler.cpp \
	game.cpp \
	texturemanager.cpp \
	loaderparams.h \
	vector2d.cpp \
	gameobject.h \
	sdlgameobject.cpp \
	player.cpp \
	gamestate.h \
	gamestatemachine.cpp \
	playstate.cpp \
	menustate.cpp \
	menubutton.cpp \
	enemy.cpp 



sdl_states_CPPFLAGS = $(SDL2_CFLAGS) $(SDL2_TTF_CFLAGS) -DDATADIR=\"$(pkgdatadir)\"
sdl_states_LDFLAGS = $(SDL2_LIBS) $(SDL2_IMAGE_LIBS) $(SDL2_TTF_LIBS)
sdl_states_LDADD = $(SDL2_LIBS) $(SDL2_IMAGE_LIBS) $(SDL2_TTF_LIBS)
