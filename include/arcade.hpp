/*
** EPITECH PROJECT, 2020
** nano
** File description:
** ARCADE
*/

#ifndef ARCADE_HPP_
#define ARCADE_HPP_

// Standard libs
#include <dlfcn.h>
#include <iostream>
#include <memory>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Local libs
#include "LibSfml.hpp"
#include "LibNcurse.hpp"
#include "LibOpengl.hpp"

#include "Nibbler.hpp"
#include "Pacman.hpp"
#include "Menu.hpp"
#include "Help.hpp"

#include "initLib.hpp"
#include "selectLib.hpp"
#include "arcade_exception.hpp"

static std::vector<std::string> libs_path = {"./lib/lib_arcade_ncurse/lib_arcade_ncurse.so", "./lib/lib_arcade_opengl/lib_arcade_opengl.so", "./lib/lib_arcade_sfml/lib_arcade_sfml.so"};
static std::vector<std::string> games_path = {"./games/lib_arcade_menu/lib_arcade_menu.so", "./games/lib_arcade_nibbler/lib_arcade_nibbler.so", "./games/lib_arcade_pacman/lib_arcade_pacman.so"};

bool arcade(char *lib_name);

#endif /* !ARCADE_HPP_ */
