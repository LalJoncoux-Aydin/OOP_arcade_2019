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

        virtual void *getLibPtr() {
            return _lib_ptr;
        };
        virtual void setLibPtr(void *new_lib) {
            _lib_ptr = (void *) new_lib;
        };
        virtual int getId() {
            return _id;
        };
        virtual std::vector<std::string> getListName() {
            return list_name;
        };
        virtual std::vector<std::string> readSceneFile();

        virtual int startGame();

        ~Pacman() = default;
    private:
        void *_lib_ptr;
        int _id = 1;
        std::string config_path = "./games/lib_arcade_pacman/.pacman";

        std::vector<std::string> list_name;
};

extern "C" IGames *createGame();

#endif /* !PACMAN_HPP_ */
