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

        virtual void changeSelection(int selected);
        virtual int startGame();
        virtual std::vector<std::string> readSceneFile();

        // Getters
        virtual void *getLibPtr() {
            return _lib_ptr;
        };
        virtual int getId() {
            return _id;
        };
        virtual std::vector<std::string> getListName() {
            return list_name;
        };

        // Setters
        virtual void setLibPtr(void *new_lib) {
            _lib_ptr = (void *) new_lib;
        };

        ~Menu() = default;
    private:
        void *_lib_ptr;
        int _id = 0;

        std::string config_path = "./games/lib_menu/.menu";
        std::string nibbler_select = "./games/lib_menu/.menu_nibbler";
        std::string pacman_select = "./games/lib_menu/.menu_pacman";

        std::vector<std::string> list_name = {"Arcade", "Menu", "Player name :", "NCurse", "OpenGl", "SFML", "Pacman", "Nibbler"};
};

extern "C" IGames *createGame();

#endif /* !MENU_HPP_ */
