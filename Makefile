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
SRC	=	main.cpp			\
		arcade.cpp			\
		initLib.cpp			\
		selectLib.cpp		\

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

graphicals:
	$(MAKE) -C lib/lib_arcade_sfml/
	$(MAKE) -C lib/lib_arcade_ncurse/
	$(MAKE) -C lib/lib_arcade_opengl/

games:
	$(MAKE) -C games/lib_arcade_nibbler/
	$(MAKE) -C games/lib_arcade_pacman/
	$(MAKE) -C games/lib_arcade_menu/

core:	$(OBJ)
	$(CXX) $(OBJ) -o $(NAME) -ldl

$(NAME):	graphicals	games	$(OBJ)
	$(CXX) $(OBJ) -o $(NAME) -ldl

clean:
	$(MAKE) clean -C games/lib_arcade_nibbler/
	$(MAKE) clean -C games/lib_arcade_pacman/
	$(MAKE)	clean -C games/lib_arcade_menu/
	$(MAKE) clean -C lib/lib_arcade_sfml/
	$(MAKE) clean -C lib/lib_arcade_ncurse/
	$(MAKE) clean -C lib/lib_arcade_opengl/
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C games/lib_arcade_pacman/
	$(MAKE) fclean -C games/lib_arcade_nibbler/
	$(MAKE)	fclean -C games/lib_arcade_menu/
	$(MAKE) fclean -C lib/lib_arcade_sfml/
	$(MAKE) fclean -C lib/lib_arcade_ncurse/
	$(MAKE) fclean -C lib/lib_arcade_opengl/
	$(RM) $(NAME)
	$(RM) *.gcda
	$(RM) *.gcno

re:	fclean all

.PHONY:	all clean fclean re games graphicals core
