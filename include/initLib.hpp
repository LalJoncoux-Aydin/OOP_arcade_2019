/*
** EPITECH PROJECT, 2020
** nano
** File description:
** INITLIB
*/

#ifndef INITLIB_HPP_
#define INITLIB_HPP_

// Standard libs
#include <iostream>
#include <dlfcn.h>

// Local libs
#include "IGraphic.hpp"
#include "IGames.hpp"

// Typedef
typedef IGraphic *(*fptr_file)(void);
typedef IGames *(*fptr_game)(void);

void *openLib(const char *lib_name);
IGraphic *initGraphic(IGraphic *new_graph, char *lib_name);
IGames *initGame(IGames *new_game, char *lib_name);

#endif /* !INITLIB_HPP_ */
