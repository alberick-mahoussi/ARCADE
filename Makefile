##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Malloc project
##

## Core
NAME = arcade

SRC = src/arcade.cpp \
	src/library.cpp	\
	src/launch_game.cpp \
	src/game.cpp

OBJ = $(SRC:.cpp=.o)

CXXFLAGS = -Wall -Wextra -I include/ -ldl

## Lib NCurses
NAME_NCURSE = lib/arcade_ncurses.so

SRC_NCURSE = src/lib/ncurse.cpp

OBJ_NCURSE = $(SRC_NCURSE:.cpp=.o)

LDFLAGS_NCURSE = -shared -fPIC 

## Lib SFML
NAME_SFML = lib/arcade_sfml.so

SRC_SFML = src/lib/sfml.cpp

OBJ_SFML = $(SRC_SFML:.cpp=.o)

LDFLAGS_SFML = -shared -fPIC -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio

## Lib SDL
NAME_SDL = lib/arcade_sdl2.so

SRC_SDL = src/lib/sdl.cpp

OBJ_SDL = $(SRC_SDL:.cpp=.o)

LDFLAGS_SDL = -shared -fPIC -lSDL2 -lSDL2_ttf -lSDL2_image
##-lSDL2_image

## SNAKE

NAME_SNAKE	=	games/lib_arcade_snake.so

SRC_SNAKE	=	src/games/snake.cpp

OBJ_SNAKE	=	$(SRC_SNAKE:.cpp=.o)

LDFLAGS_SNAKE	=	-shared -fPIC

## NIBBLER

NAME_NIBBLER	=	games/lib_arcade_nibbler.so

SRC_NIBBLER	=	src/games/nibbler.cpp

OBJ_NIBBLER	=	$(SRC_NIBBLER:.cpp=.o)

LDFLAGS_NIBBLER	=	-shared -fPIC

RM = rm

## PACMAN

NAME_PACMAN	=	games/lib_arcade_pacman.so

SRC_PACMAN	=	src/games/pacman.cpp

OBJ_PACMAN	=	$(SRC_PACMAN:.cpp=.o)

LDFLAGS_PACMAN	=	-shared -fPIC

all: core graphicals games

core: $(OBJ)
	g++ -o $(NAME) $(SRC) $(CXXFLAGS)

graphicals: $(NAME_SFML) $(NAME_SDL) ##$(NAME_NCURSE)

games: $(NAME_NIBBLER) $(NAME_SNAKE)  ##$(NAME_PACMAN)

$(NAME_NCURSE):
	g++ -c -o $(OBJ_NCURSE) $(SRC_NCURSE) $(LDFLAGS_NCURSE)
	gcc -shared -o $(NAME_NCURSE) $(OBJ_NCURSE) -lncurses
	
$(NAME_SFML):
	g++ -c -o $(OBJ_SFML) $(SRC_SFML) $(LDFLAGS_SFML) -fPIC
	gcc -shared -o $(NAME_SFML) $(OBJ_SFML) -lsfml-graphics -lsfml-window -lsfml-system

$(NAME_SDL):
	g++ -c -o $(OBJ_SDL) $(SRC_SDL) $(LDFLAGS_SDL) -fPIC
	gcc -shared -o $(NAME_SDL) $(OBJ_SDL) $(LDFLAGS_SDL)

$(NAME_NIBBLER):
	g++ -c -o $(OBJ_NIBBLER) $(SRC_NIBBLER) $(LDFLAGS_NIBBLER) -fPIC
	gcc -shared -o $(NAME_NIBBLER) $(OBJ_NIBBLER) $(LDFLAGS_NIBBLER)

$(NAME_SNAKE):
	g++ -c -o $(OBJ_SNAKE) $(SRC_SNAKE) $(LDFLAGS_SNAKE) -fPIC
	gcc -shared -o $(NAME_SNAKE) $(OBJ_SNAKE) $(LDFLAGS_SNAKE)

##$(NAME_PACMAN):
##	g++ -c -o $(OBJ_PACMAN) $(SRC_PACMAN) $(LDFLAGS_PACMAN) -fPIC
##	gcc -shared -o $(NAME_PACMAN) $(OBJ_PACMAN) $(LDFLAGS_PACMAN)

clean:
		rm -f $(OBJ_NCURSE) $(OBJ_SFML) $(OBJ_SDL)

fclean:         clean
		rm -f lib/*.so
		rm -f src/*.o
		rm arcade
		rm -f games/*.so
		rm -f src/games/*.o

re:             fclean all

.PHONY:         all clean fclean re
