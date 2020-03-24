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
#include "Player.hpp"
#include "Objects.hpp"
#include "Ennemies.hpp"

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
        void *_lib_ptr;

        std::string config_path = "./games/lib_arcade_pacman/.pacman";
        std::vector<std::string> _map;
        Player _player;
        Ennemies _ennemies;
        Objects _objects;
};

extern "C" IGames *createGame();

#endif /* !PACMAN_HPP_ */
