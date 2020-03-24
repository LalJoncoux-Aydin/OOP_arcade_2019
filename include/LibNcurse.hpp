/*
** EPITECH PROJECT, 2020
** nano
** File description:
** LIBNCURSE
*/

#ifndef LIBNCURSE_HPP_
#define LIBNCURSE_HPP_

// General libs
#include <iostream>
#include <ncurses.h>
#include <cstring>

// Local libs
#include "IGraphic.hpp"
#include "initLib.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class LibNcurse: public IGraphic
{
   public:
        LibNcurse();
        ~LibNcurse() = default;
        virtual int openWindow();
        virtual void closeWindow();

        virtual bool displayScene(std::vector<std::string> config_scene);

        virtual void cleanScreen();
        virtual bool drawText();
        virtual bool drawMap();

        // Getters
        virtual int getKey();
        virtual int getId() {
            return 0;
        };
        virtual int getState() {
            return _state;
        };
        virtual void *getLibPtr() {
            return _lib_ptr;
        };
        virtual void setLibPtr(void *new_lib) {
            _lib_ptr = (void *) new_lib;
        };

  private:
      int ch;
      int _row;
      int _col;
      void *_lib_ptr;
      std::string _name;
      std::string menu = "Menu";
      std::string getName = "Enter a name : ";
      std::string libs = "Libs : LibSfml - LibNcurse - LibOpenGl";
      std::string games = "Games : Nibbler - Pacman";
      std::string highscore = "Highscore";
      std::string exit = "Exit";
      int _state;
};

extern "C" IGraphic *createLib();

#endif /* !LIBNCURSE_HPP_ */
