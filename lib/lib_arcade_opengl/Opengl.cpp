#include "LibOpengl.hpp"
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
// Include GLM
//#include <glm/glm.hpp>
//using namespace glm;

LibOpengl::LibOpengl()
{
    if (!_texture.loadFromFile("lib/lib_arcade_opengl/assets/fond2.jpg", sf::IntRect(0, 0, 3000, 3000)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_font.loadFromFile("lib/lib_arcade_opengl/assets/spaceranger.ttf"))
        std::cerr << "Warning: cannot load regular.tff" << std::endl;
    if (!_texture1.loadFromFile("lib/lib_arcade_opengl/assets/hilary1.jpg", sf::IntRect(0, 0, 3000, 3000)))
        std::cout <<"Error: image not loading" << std::endl;

    playerImage.setTexture(_texture);
    playerFun.setTexture(_texture1);
}

int LibOpengl::openWindow()
{
    sf::ContextSettings settings;
    _window.create(sf::VideoMode(1920, 1080, 32), "Arcade");
    _window.setVerticalSyncEnabled(true);

    playerText.setFont(_font);
    playerText.setString("||");
    playerText.setCharacterSize(50);
    playerText.setFillColor(sf::Color::White);
    playerText.setPosition(800, 300);

    // effacement les tampons de couleur/profondeur
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    return 0;
}

void LibOpengl::printer()
{
}

void LibOpengl::cleanScreen()
{
    _window.display();
}

bool LibOpengl::displayScene(std::vector<std::string> config_scene)
{
    size_t i = 0;
    int c = 0;

    _window.pushGLStates();
    _window.draw(playerImage);
    _window.draw(playerText);
    _window.popGLStates();
    for(; i < config_scene.size() - 1; i++) {
        std::vector<std::string> l_command;
        std::stringstream s_stream(config_scene[i]);
        c = 0;
        while(s_stream.good() && c != 5){
            std::string param;

            c++;
            getline(s_stream, param, ',');
            l_command.push_back(param);
        }
        _text = l_command[0];
        pos_x = std::stoi(l_command[1]);
        pos_y = std::stoi(l_command[2]);
        _color = l_command[3];
        charSize = std::stoi(l_command[4]);
        if (draw_text((char *)_text.c_str(), charSize, _color, pos_x, pos_y) == false)
            return false;
    }
    _window.display();
    return true;
}

int LibOpengl::getKey()
{
    // gestion des évènements
    sf::Event event;

    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            closeWindow();
            return 84;
        } else if (event.type == sf::Event::TextEntered) {
            playerInput += event.text.unicode;
            playerText.setString(playerInput);
//            displayMenu();
            //_window.display();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::F3) {
                return 3;
            }
            if (event.key.code == sf::Keyboard::F4) {
                return 4;
            }
            if (event.key.code == sf::Keyboard::F5) {
                return 5;
            }
            if (event.key.code == sf::Keyboard::F6) {
                return 6;
            }
            if (event.key.code == sf::Keyboard::F7)
                return 2;
            if (event.key.code == sf::Keyboard::F8)
                return 1;
            if (event.key.code == sf::Keyboard::F12) {
                return 84;
            }
            if (event.key.code == sf::Keyboard::Return) {
                _window.pushGLStates();
                _window.draw(playerFun);
                _window.popGLStates();
                _window.display();
                unsigned int nb_sec = 1;
                sleep (nb_sec);
                return 10;
            }
        }
        else if (event.type == sf::Event::Resized)
            // on ajuste le viewport lorsque la fenêtre est redimensionnée
            glViewport(0, 0, event.size.width, event.size.height);
    }
    return 0;
}

void LibOpengl::changeColor(int selected)
{
    if (selected == 1)
        _state = 1;
    if (selected == 2)
        _state = 2;
}

bool LibOpengl::draw_text(char *string, int charSize, std::string _color_st, int y_position, int x_position)
{
    sf::Text text(string, _font);
    text.setPosition(y_position, x_position);
    text.setCharacterSize(charSize);
    if (_color_st == "cyan")
        text.setColor(sf::Color(0, 0, 255, 255));
    else if (_color_st == "white")
        text.setColor(sf::Color(0, 255, 255, 255));
    else if (_color_st == "pink")
        text.setColor(sf::Color(0, 255, 105, 180));
    else if (_color_st == "blue")
        text.setColor(sf::Color(0, 0, 191, 255));
    else {
        throw getGraphicFail();
        return false;
    }
    _window.pushGLStates();
    _window.draw(text);
    _window.popGLStates();
    return true;
}

void LibOpengl::closeWindow()
{
    _window.close();
}

extern "C" IGraphic *createLib(void)
{
    return new LibOpengl;
}
