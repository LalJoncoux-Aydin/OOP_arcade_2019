/*
** EPITECH PROJECT, 2020
** nano
** File description:
** MENU
*/

#ifndef MENU_HPP_
#define MENU_HPP_

// General libs
#include <iostream>
#include <vector>

// Local libs
#include "IGames.hpp"

class Menu: public IGames {
    public:
        Menu();

        virtual std::vector<std::string> readSceneFile();
        virtual void changeSelection(int selected);

        // Getters
        virtual void *getLibPtr() {
            return _lib_ptr;
        };
        virtual int getId() {
            return 0;
        };

        // Setters
        virtual void setLibPtr(void *new_lib) {
            _lib_ptr = (void *) new_lib;
        };

        ~Menu() = default;
    private:
        std::string config_path = "./games/lib_menu/.menu";
        std::string nibbler_select = "./games/lib_menu/.menu_nibbler";
        std::string pacman_select = "./games/lib_menu/.menu_pacman";
};

extern "C" IGames *createGame();

#endif /* !MENU_HPP_ */
