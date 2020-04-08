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
#include <SFML/Audio.hpp>

class LibOpengl: public IGraphic
{
   public:

        LibOpengl();
        ~LibOpengl() = default;
        virtual int openWindow();
        virtual void closeWindow();

        virtual bool displayScene(std::vector<std::string> config_scene, int id, std::vector<Ennemies> ennemies_list);
        virtual bool drawText(std::string _text, int pos_x, int pos_y, std::string _color, int charSize);
        bool drawMap(char _letter, int x, int y);
        virtual bool drawPlayer(int x, int y, int id);
        virtual bool drawObject(int x, int y);
        virtual bool drawEnemies(int x, int y, std::vector<Ennemies> ennemies_list, int ennemie_x, int ennemie_y);
        virtual void displayLoose();
        virtual bool displayBody(int x, int y);
      /*  virtual void playMusic(void);
        virtual void breakMusic(void);
        virtual void stopMusic(void);
*/
        //virtual void displayBody(Player_player);



        // Getters
        virtual int getKey();
        virtual int getId() {
            return 1;
        };
        virtual void *getLibPtr() {
            return _lib_ptr;
        };
        virtual std::string getName() {
            return _name;
        };

        // Setters
        virtual void setLibPtr(void *new_lib) {
            _lib_ptr = (void *) new_lib;
        };
        virtual void setName(std::string _old_name) {
            _name = _old_name;
        };

  private:
      enum Dir{Up,Down,Right,Left};
     // sf::Sound _sound;
      //sf::SoundBuffer _buffer;
      sf::RenderWindow _window;
      sf::IntRect _recto;
      sf::Text playerText;
      sf::String playerInput = (sf::String) _name;
      sf::Sprite playerImage;
      sf::Sprite playerFun;
      sf::Texture _texture;
      sf::Texture _texture1;
      sf::Texture _texture2;
      sf::Texture _wallA;
      sf::Texture _wallG;
      sf::Texture _wallZ;
      sf::Texture _wallE;
      sf::Texture _wallB;
      sf::Texture _wallC;
      sf::Texture _wall0;
      sf::Texture _wallD;
      sf::Texture _wall4;
      sf::Texture _head;
      sf::Texture _body;
      sf::Texture _wall5;
      sf::Texture _wallL;
      sf::Texture _wallR;
      sf::Texture _wallpp;
      sf::Texture _wall6;
      sf::Texture _wall8;
      sf::Texture _wall9;
      sf::Texture _wall7;
      sf::Texture _wall2;
      sf::Texture _wallQ;
      sf::Texture _wallM;
      sf::Texture _wallY;
      sf::Texture _wall3;
      sf::Texture _wall1;
      sf::Texture _wallU;
      sf::Texture _wallN;
      sf::Texture _wallO;
      sf::Texture _wallI;
      sf::Texture _wallV;
      sf::Texture _wallH;
      sf::Texture _wallT;
      sf::Texture _wallK;
      sf::Texture _wallW;
      sf::Texture _wallX;
      sf::Texture _orange;
      sf::Texture _blue;
      sf::Texture _pacman;
      sf::Texture _rouge;
      sf::Texture _pink;
      sf::Texture _died;
      sf::Texture _big;
      sf::Texture _fruit;
      sf::Sprite _sWallA;
      sf::Sprite _sWallY;
      sf::Sprite _sWallZ;
      sf::Sprite _sWall1;
      sf::Sprite _sWallX;
      sf::Sprite _sWall3;
      sf::Sprite _sWall4;
      sf::Sprite _sWall0;
      sf::Sprite _sWall5;
      sf::Sprite _sbig;
      sf::Sprite _sWall6;
      sf::Sprite _sWall7;
      sf::Sprite _sWall8;
      sf::Sprite _sWall9;
      sf::Sprite _sWallH;
      sf::Sprite _sWallN;
      sf::Sprite _sWallO;
      sf::Sprite _sWall2;
      sf::Sprite _sWallI;
      sf::Sprite _sWallB;
      sf::Sprite _sWallC;
      sf::Sprite _sWallK;
      sf::Sprite _sWallE;
      sf::Sprite _sWallG;
      sf::Sprite _sWallpp;
      sf::Sprite _sWallU;
      sf::Sprite _sWallD;
      sf::Sprite _sdied;
      sf::Sprite _sWallL;
      sf::Sprite _sWallV;
      sf::Sprite _sWallQ;
      sf::Sprite _sWallM;
      sf::Sprite _sWallT;
      sf::Sprite _sWallW;
      sf::Sprite _sWallR;
      sf::Sprite _spacman;
      sf::Sprite _shead;
      sf::Sprite _sbody;
      sf::Sprite _srouge;
      sf::Sprite _spink;
      sf::Sprite _sblue;
      sf::Sprite _sorange;
      sf::Sprite _sfruit;
      sf::Font _font;

      void printer();
};

extern "C" IGraphic *createLib();
#endif /* !LIBOPENGL_HPP_ */
