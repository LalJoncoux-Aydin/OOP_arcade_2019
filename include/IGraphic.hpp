/*
** EPITECH PROJECT, 2020
** nano
** File description:
** IGRAPHIC
*/

#ifndef IGRAPHIC_HPP_
#define IGRAPHIC_HPP_

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

#include "arcade_exception.hpp"

class IGraphic {
    public:
        virtual int openWindow() = 0;
        virtual void closeWindow() = 0;

        virtual bool displayScene(std::vector<std::string> config_scene) = 0;
        virtual bool drawText(std::string _name, int pos_x, int pos_y, std::string _color, int charSize) = 0;

        // Getters
        virtual int getKey() = 0;
        virtual int getId() = 0;
        virtual void *getLibPtr() = 0;

        // Setters
        virtual void setLibPtr(void * new_lib) = 0;

        virtual ~IGraphic() = default;

    protected :
        void *_lib_ptr;
        std::string _name;
};

#endif /* !IGRAPHIC_HPP_ */
