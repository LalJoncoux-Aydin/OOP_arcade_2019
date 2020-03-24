/*
** EPITECH PROJECT, 2020
** nano
** File description:
** IGAMES
*/

#ifndef IGAMES_HPP_
#define IGAMES_HPP_

#include <vector>
#include <iostream>
#include <fstream>

#include "Player.hpp"
#include "Objects.hpp"
#include "Ennemies.hpp"
#include "arcade_exception.hpp"

class IGames {
    public:
        virtual std::vector<std::string> readSceneFile() = 0;
        virtual void changeSelection(int selected) = 0;

        // Getters
        virtual void *getLibPtr() = 0;
        virtual int getId() = 0;

        // Setters
        virtual void setLibPtr(void * new_lib) = 0;

        virtual ~IGames() = default;
    protected:
        void *_lib_ptr;

        std::vector<std::string> config_file;
        std::vector<std::string> _map;

        Player *_player;
        Ennemies *_ennemies;
        Objects *_objects;
};

#endif /* !IGAMES_HPP_ */
