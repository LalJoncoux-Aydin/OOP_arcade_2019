##
## EPITECH PROJECT, 2019
## makefile
## File description:
## build
##
# Mandatory
SHELL	= /bin/sh

# Security
CXX ?= g++

RM	?=	rm -f

# Sources
SRC	=	arcade.cpp			\
		initLib.cpp			\
		changeLib.cpp		\
		Player.cpp 			\
		Ennemies.cpp		\
		main.cpp			\

SRC_FILE	=	$(addprefix ./src/, $(SRC))

TESTS	=	\


# Flags
CXXFLAGS	=	 -Wall -Wextra -W
CPPFLAGS	=	-I./include

# OBJ
OBJ		 	=	$(SRC_FILE:.cpp=.o)
OBJ_LIB		=	$(SRC_LIB:.a)

NAME		=	arcade

all: $(NAME)

to_launch_games:
	$(MAKE) -C games/lib_arcade_nibbler/
	$(MAKE) -C games/lib_arcade_pacman/
	$(MAKE)	-C games/lib_menu/

graphicals:
	$(MAKE) -C lib/lib_arcade_sfml/
	$(MAKE) -C lib/lib_arcade_ncurse/
	$(MAKE) -C lib/lib_arcade_opengl/
#
# core:	$(OBJ)
# 	$(CXX) $(OBJ) -o $(NAME) -ldl

$(NAME):	to_launch_games	graphicals	$(OBJ)
	$(CXX) $(OBJ) -o $(NAME) -ldl

#$(CXX) -Wl,--whole-archive lib/lib_arcade_ncurse/lib_arcade_ncurse_static.a lib/lib_arcade_opengl/lib_arcade_opengl_static.a lib/lib_arcade_sfml/lib_arcade_sfml_static.a games/lib_arcade_nibbler/lib_arcade_nibbler_static.a games/lib_arcade_pacman/lib_arcade_pacman_static.a -Wl,--no-whole-archive -o central_lib.so

clean:
	$(MAKE) clean -C games/lib_arcade_nibbler/
	$(MAKE) clean -C games/lib_arcade_pacman/
	$(MAKE)	clean -C games/lib_menu/
	$(MAKE) clean -C lib/lib_arcade_sfml/
	$(MAKE) clean -C lib/lib_arcade_ncurse/
	$(MAKE) clean -C lib/lib_arcade_opengl/
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C games/lib_arcade_pacman/
	$(MAKE) fclean -C games/lib_arcade_nibbler/
	$(MAKE)	fclean -C games/lib_menu/
	$(MAKE) fclean -C lib/lib_arcade_sfml/
	$(MAKE) fclean -C lib/lib_arcade_ncurse/
	$(MAKE) fclean -C lib/lib_arcade_opengl/
	$(RM) $(NAME)
	$(RM) *.gcda
	$(RM) *.gcno

re:	fclean all

.PHONY:	all tests_run clean fclean re
