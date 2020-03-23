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

SRC_SFML	=	Opengl.cpp 		\

# Flags
CXXFLAGS	=	 -Wall -Wextra -W -c -fpic
CPPFLAGS	=	-I../../include

# OBJ
OBJ 	=	$(SRC_SFML:.cpp=.o)

NAME	=	lib_arcade_opengl.so

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -shared -o $(NAME) $(OBJ) -lGL -lGLU -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) *.gcda
	$(RM) *.gcno

re:	fclean all

.PHONY:	all tests_run clean fclean re
