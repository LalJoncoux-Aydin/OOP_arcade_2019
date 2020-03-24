/*
** EPITECH PROJECT, 2020
** nano
** File description:
** PACMAN
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

// General libs
#include <iostream>

// Local libs
#include "IGames.hpp"

class Pacman: public IGames {
    public:
        Pacman();

        virtual std::vector<std::string> readSceneFile();
        virtual void changeSelection(__attribute__((unused))int selected) {};

        // Getters
        virtual void *getLibPtr() {
            return _lib_ptr;
        };
        virtual int getId() {
            return 1;
        };

        // Setters
        virtual void setLibPtr(void *new_lib) {
            _lib_ptr = (void *) new_lib;
        };

        ~Pacman() = default;
    private:
        std::string config_path = "./games/lib_arcade_pacman/pacman.txt";
};

extern "C" IGames *createGame();

#endif /* !PACMAN_HPP_ */
