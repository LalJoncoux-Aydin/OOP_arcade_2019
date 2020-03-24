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
        std::vector<std::string> config_file;
};

#endif /* !IGAMES_HPP_ */
