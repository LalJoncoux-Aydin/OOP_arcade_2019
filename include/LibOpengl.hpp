/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** LibOpengl
*/

#ifndef LIBOPENGL_HPP_
#define LIBOPENGL_HPP_

// General libs
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Local libs
#include "IGraphic.hpp"
#include "initLib.hpp"
#include <GLFW/glfw3.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class LibOpengl: public IGraphic
{
   public:
        LibOpengl();
        ~LibOpengl() = default;
        virtual int openWindow();
        virtual void closeWindow();

        virtual bool displayScene(std::vector<std::string> config_scene);
        virtual void cleanScreen();
        bool drawText(std::string _text, int pos_x, int pos_y, std::string _color, int charSize);
        bool drawMap();

        // Getters
        virtual int getKey();
        virtual int getId() {
            return 1;
        };
        virtual void *getLibPtr() {
            return _lib_ptr;
        };

        // Setters
        virtual void setLibPtr(void *new_lib) {
            _lib_ptr = (void *) new_lib;
        };

  private:
      void *_lib_ptr;

      std::string _name;
      sf::RenderWindow _window;

      sf::Text playerText;
      sf::String playerInput;
      sf::Sprite playerImage;
      sf::Sprite playerFun;
      sf::Texture _texture;
      sf::Texture _texture1;
      sf::Font _font;

      void printer();
};

extern "C" IGraphic *createLib();
#endif /* !LIBOPENGL_HPP_ */
