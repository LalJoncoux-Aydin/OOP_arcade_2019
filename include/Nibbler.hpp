/*
** EPITECH PROJECT, 2020
** nano
** File description:
** NIBBLER
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

// General libs
#include <iostream>

// Local libs
#include "IGames.hpp"
#include "Player.hpp"
#include "Objects.hpp"
#include "Ennemies.hpp"

class Nibbler: public IGames {
    public:
        Nibbler();

        virtual std::vector<std::string> readSceneFile();
        virtual void changeSelection(__attribute__((unused))int selected) {};

        // Getters
        virtual void *getLibPtr() {
            return _lib_ptr;
        };
        virtual int getId() {
            return 2;
        };

        // Setters
        virtual void setLibPtr(void *new_lib) {
            _lib_ptr = (void *) new_lib;
        };

        ~Nibbler() = default;
    private:
        void *_lib_ptr;

        std::string config_path = "./games/lib_arcade_nibbler/.nibbler";
        std::vector<std::string> _map;
        Player _player;
        Ennemies _ennemies;
        Objects _objects;
};

extern "C" IGames *createGame();

#endif /* !NIBBLER_HPP_ */
