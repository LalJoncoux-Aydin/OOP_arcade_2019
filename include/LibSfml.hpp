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
        virtual bool displayScene(std::vector<std::string> config_scene);
        virtual bool drawText(std::string _name, int pos_x, int pos_y, std::string _color, int charSize);
        bool drawMap();
        bool drawHero();
        bool drawEnnemies();
        bool drawObject();

        // Getters
        virtual int getKey();
        virtual int getId() {
            return 2;
        };
        virtual void *getLibPtr() {
            return _lib_ptr;
        };

        // Setters
        virtual void setLibPtr(void *new_lib) {
            _lib_ptr = (void *) new_lib;
        };

  private:
      //DEFINE EVENT
      sf::Event _Event;
      //DEFINE WINDOW
      sf::RenderWindow _window;
      //DEFINE STRING
      sf::String _playerInput;
      std::string _name;
      //DEFINE MUSIC
     // sf::SoundBuffer _buffer;
      //sf::Sound _sound;
      //DEFINE FONT
      sf::Font _font;
      //DEFINE SPRITE
      sf::Sprite _playerImage;
      //DEFINE TEXTURE
      sf::Texture _pTexture;
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
