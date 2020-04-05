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

SRC_SFML	=	LibNcurse.cpp 		\

# Flags
CXXFLAGS	=	 -Wall -Wextra -W -c -fpic
CPPFLAGS	=	-I../../include

# OBJ
OBJ 	=	$(SRC_SFML:.cpp=.o)

NAME	=	lib_arcade_ncurse.so


all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -shared -o $(NAME) $(OBJ) -lncurses -lsfml-audio

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) *.gcda
	$(RM) *.gcno

re:	fclean all

.PHONY:	all tests_run clean fclean re
