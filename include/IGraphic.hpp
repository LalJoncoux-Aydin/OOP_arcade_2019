/*
** EPITECH PROJECT, 2020
** nano
** File description:
** IGRAPHIC
*/

#ifndef IGRAPHIC_HPP_
#define IGRAPHIC_HPP_

#include <vector>

#include "arcade_exception.hpp"

class IGraphic {
    public:
        virtual int openWindow() = 0;
        virtual void closeWindow() = 0;

        virtual bool displayScene(std::vector<std::string> config_scene) = 0;
        virtual void changeColor(int selected) = 0;

        virtual void cleanScreen() = 0;

        virtual int getKey() = 0;
        virtual int getState() = 0;

        // Getters
        virtual int getId() = 0;
        virtual void *getLibPtr() = 0;
        virtual void setLibPtr(void * new_lib) = 0;

        virtual ~IGraphic() = default;

    protected :
        int cyan [4] = { 0, 0, 255, 255 };
        int white [4] = { 0, 255, 255, 255 };
        int pink [4] = { 0, 255, 105, 180 };
        int blue [4] = { 0, 0, 191, 255 };
};

#endif /* !IGRAPHIC_HPP_ */
