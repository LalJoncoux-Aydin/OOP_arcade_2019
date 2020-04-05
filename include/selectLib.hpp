/*
** EPITECH PROJECT, 2020
** nano
** File description:
** SELECTLIB
*/

#ifndef SELECTLIB_HPP_
#define SELECTLIB_HPP_

// Standard libs
#include <iostream>
#include <dlfcn.h>

// Local libs
#include "IGraphic.hpp"
#include "IGames.hpp"
#include "arcade.hpp"

IGraphic *selectGraphical(IGraphic *graphical_t, int key, IGames *game_t);
IGames *selectGame(IGames *game_t, int key, IGraphic *graphical_t);

#endif /* !SELECTLIB_HPP_ */
