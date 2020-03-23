/*
** EPITECH PROJECT, 2020
** nano
** File description:
** CHANGELIB
*/

#ifndef CHANGELIB_HPP_
#define CHANGELIB_HPP_

// Standard libs
#include <iostream>
#include <dlfcn.h>

// Local libs
#include "IGraphic.hpp"
#include "IGames.hpp"
#include "arcade.hpp"

IGraphic *changeLib(IGraphic *graphical_t, int key);

#endif /* !CHANGELIB_HPP_ */
