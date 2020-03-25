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
#include <cmath>

class LibNcurse: public IGraphic
{
   public:
        LibNcurse();
        ~LibNcurse() = default;
        virtual int openWindow();
        virtual void closeWindow();

        virtual bool displayScene(std::vector<std::string> config_scene);
        virtual bool drawText(std::string _name, int pos_x, int pos_y, std::string _color, int charSize);
        bool drawMap();

        // Getters
        virtual int getKey();
        virtual int getId() {
            return 0;
        };
        virtual void *getLibPtr() {
            return _lib_ptr;
        };

        //Setters
        virtual void setLibPtr(void *new_lib) {
            _lib_ptr = (void *) new_lib;
        };

  private:
      int ch;
      int _row;
      int _col;
      int nb_divide = 15;
      WINDOW *BOARD[30];
};

extern "C" IGraphic *createLib();

#endif /* !LIBNCURSE_HPP_ */
