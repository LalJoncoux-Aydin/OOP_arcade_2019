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

        virtual void *getLibPtr() {
            return _lib_ptr;
        };
        virtual int getId() {
            return _id;
        };
        virtual std::vector<std::string> getListName() {
            return list_name;
        };
        virtual std::vector<std::string> readSceneFile();

        virtual void setLibPtr(void *new_lib) {
            _lib_ptr = (void *) new_lib;
        };

        virtual int startGame();

        ~Menu() = default;
    private:
        void *_lib_ptr;
        int _id = 0;
        std::string config_path = "./games/lib_menu/.menu";

        std::vector<std::string> list_name = {"Arcade", "Menu", "Player name :", "NCurse", "OpenGl", "SFML", "Pacman", "Nibbler"};
};

extern "C" IGames *createGame();

#endif /* !MENU_HPP_ */
