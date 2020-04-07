/*
** EPITECH PROJECT, 2020
** nano
** File description:
** LIBSFML
*/

#ifndef LIBSFML_HPP_
#define LIBSFML_HPP_

// General libs
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
// Local libs
#include "IGraphic.hpp"
#include "initLib.hpp"

class LibSfml: public IGraphic
{
   public:
    //DEFINE PROTOTYPES
        LibSfml();
        ~LibSfml() = default;
        virtual int openWindow();
        virtual void closeWindow();
        // void check_mouse_pos(sf::Event::MouseMoveEvent const &mouse, sf::Text &text, bool isSelected);
        // void check_mouse_click(sf::Event const &event, sf::Text &text, bool &isSelected);
        virtual bool displayScene(std::vector<std::string> config_scene, int id, std::vector<Ennemies> ennemies_list);
        virtual bool drawText(std::string _name, int pos_x, int pos_y, std::string _color, int charSize);
        bool drawMap(char _letter, int x, int y);
        virtual bool drawPlayer(int x, int y, int id);
        virtual bool drawObject(int x, int y);
        virtual bool drawEnemies(int x, int y, std::vector<Ennemies> ennemies_list, int ennemie_x, int ennemie_y);
        virtual void displayLoose();
        virtual bool displayBody(int x, int y);
        /*virtual void playMusic(void);
        virtual void breakMusic(void);
        virtual void stopMusic(void);
*/

        // Getters
        virtual int getKey();
        virtual int getId() {
            return 2;
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
      //DEFINE EVENT
      sf::Event _Event;
      //DEFINE WINDOW
     //sf::Music _music;

      sf::RenderWindow _window;
      //DEFINE STRING
      sf::String _playerInput;
      //DEFINE MUSIC
     // sf::SoundBuffer _buffer;
      //sf::Sound _sound;
      //DEFINE FONT
      sf::Font _font;
      //DEFINE SPRITE
      sf::Sprite _playerImage;
      //DEFINE TEXTURE
      sf::Texture _pTexture;
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
      sf::Texture _pacman;
      sf::Texture _pink;
      sf::Texture _blue;
      sf::Texture _orange;
      sf::Texture _died;
      sf::Texture _big;
      sf::Texture _rouge;
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
      sf::Sprite _sdied;
      sf::Sprite _sbig;
      sf::Sprite _sfruit;
      //DEFINE TEXT
      sf::Text _exit;
      sf::Text _playerText;
      //DEFINE BOOELEN
      bool _isSelected;
      bool _isSelected2;
      bool _isSelected3;
      bool _isSelected4;
      bool _isSelected5;
};

extern "C" IGraphic *createLib();

#endif /* !LIBSFML_HPP_ */
