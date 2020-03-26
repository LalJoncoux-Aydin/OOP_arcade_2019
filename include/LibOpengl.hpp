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
        virtual bool drawText(std::string _text, int pos_x, int pos_y, std::string _color, int charSize);
        bool drawMap(std::string _letter, int x, int y);

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
      std::string _name;
      sf::RenderWindow _window;

      sf::Text playerText;
      sf::String playerInput;
      sf::Sprite playerImage;
      sf::Sprite playerFun;
      sf::Texture _texture;
      sf::Texture _texture1;
      sf::Texture _texture2;
      sf::Texture _wallA;
      sf::Texture _wallB;
      sf::Texture _wallC;
      sf::Texture _wallD;
      sf::Texture _wallL;
      sf::Texture _wallR;
      sf::Sprite _sWallA;
      sf::Sprite _sWallB;
      sf::Sprite _sWallC;
      sf::Sprite _sWallD;
      sf::Sprite _sWallL;
      sf::Sprite _sWallR;
      sf::Font _font;

      void printer();
};

extern "C" IGraphic *createLib();
#endif /* !LIBOPENGL_HPP_ */
