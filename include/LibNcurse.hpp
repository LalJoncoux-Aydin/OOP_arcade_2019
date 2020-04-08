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
#include <SFML/Audio.hpp>
#include <cmath>

class LibNcurse: public IGraphic
{
   public:

        LibNcurse();
        ~LibNcurse() = default;
        virtual int openWindow();
        virtual void closeWindow();

        virtual bool displayScene(std::vector<std::string> config_scene, int id, std::vector<Ennemies> ennemies_list);
        virtual bool drawText(std::string _name, int pos_x, int pos_y, std::string _color, int charSize);
        bool drawMap(int x, int y);
        virtual bool drawPlayer(int x, int y, int id);
        virtual bool drawObject(int x, int y);
        virtual bool drawEnemies(int x, int y, std::vector<Ennemies> ennemies_list, int ennemie_x, int ennemie_y);
        virtual void displayLoose();
        virtual bool displayBody(int x, int y);
        /*virtual void playMusic(void);
        virtual void breakMusic(void);
        virtual void stopMusic(void);
*/
        //virtual bool drawRectangle(int x, int y);


        void clearScreen(void);

        // Getters
        virtual int getKey();
        virtual int getId() {
            return 0;
        };
        virtual void *getLibPtr() {
            return _lib_ptr;
        };
        virtual std::string getName() {
            return _name;
        };

        //Setters
        virtual void setLibPtr(void *new_lib) {
            _lib_ptr = (void *) new_lib;
        };
        virtual void setName(std::string _old_name) {
            _name = _old_name;
        };

  private:
      int ch;
      int _row;
      int _col;
};

extern "C" IGraphic *createLib();

#endif /* !LIBNCURSE_HPP_ */
