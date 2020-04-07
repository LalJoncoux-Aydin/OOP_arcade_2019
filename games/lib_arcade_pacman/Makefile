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

SRC	=	Pacman.cpp 					\

# Flags
CXXFLAGS	=	 -Wall -Wextra -W -c -fpic
CPPFLAGS	=	-I../../include

# OBJ
OBJ 	=	$(SRC:.cpp=.o)

NAME	=	lib_arcade_pacman.so

all: $(NAME)

$(NAME):	$(OBJ)
	$(CXX) -shared -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) *.gcda
	$(RM) *.gcno

re:	fclean all

.PHONY:	all tests_run clean fclean re
