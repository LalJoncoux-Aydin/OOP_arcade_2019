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
    if (!_wallA.loadFromFile("lib/lib_arcade_opengl/assets/A_small.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wallB.loadFromFile("lib/lib_arcade_opengl/assets/B_small.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wallC.loadFromFile("lib/lib_arcade_opengl/assets/C_small.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wallD.loadFromFile("lib/lib_arcade_opengl/assets/D_small.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wallL.loadFromFile("lib/lib_arcade_opengl/assets/L_small.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wallR.loadFromFile("lib/lib_arcade_opengl/assets/R_small.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    playerImage.setTexture(_texture);
    playerFun.setTexture(_texture1);
    _sWallA.setTexture(_wallA);
    _sWallB.setTexture(_wallB);
    _sWallC.setTexture(_wallC);
    _sWallD.setTexture(_wallD);
    _sWallL.setTexture(_wallL);
    _sWallR.setTexture(_wallR);
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
    int z = 0;
    int y = 0;

    _window.pushGLStates();
    _window.draw(playerImage);
    _window.draw(playerFun);
    _window.popGLStates();
    for(; i < config_scene.size() - 1; i++) {
        std::vector<std::string> l_command;
        std::stringstream s_stream(config_scene[i]);
        c = 0;
        while(s_stream.good() && c != 6){
            std::string param;

            c++;
            getline(s_stream, param, ',');
            l_command.push_back(param);
        }
        if (l_command[0] == "1") {
            if (drawText(l_command[1], std::stoi(l_command[2]), std::stoi(l_command[3]), l_command[4], std::stoi(l_command[5])) == false)
                return false;
        }
        if (l_command[0] == "2") {
            for (int x = 0; x != 1036; x += 32) {
                z++;
                if (drawMap(l_command[z], x, y) == false)
                    return false;
            }
            y = y + 32;
        }
    }
    _window.display();
    return true;
}

bool LibOpengl::drawMap(std::string _letter, int x, int y)
{
    if (_letter.compare("A") == 0) {
        _sWallA.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallA);
        return true;
    } else if (_letter.compare("B") == 0) {
        _sWallB.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallB);
        return true;
    } else if (_letter.compare("C") == 0) {
        _sWallC.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallC);
        return true;
    } else if (_letter.compare("D") == 0) {
        _sWallD.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallD);
        return true;
    } else if (_letter.compare("L") == 0) {
        _sWallL.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallL);
        return true;
    } else if (_letter.compare("R") == 0) {
        _sWallR.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallR);
        return true;
    } else
        return false;
}

bool LibOpengl::drawText(std::string _text, int pos_x, int pos_y, std::string _color, int charSize)
{
    sf::Text text((char*)_text.c_str(), _font);
    text.setPosition(pos_x, pos_y);
    text.setCharacterSize(charSize);
    if (_color == "cyan")
        text.setColor(sf::Color(0, 0, 255, 255));
    else if (_color == "white")
        text.setColor(sf::Color(0, 255, 255, 255));
    else if (_color == "pink")
        text.setColor(sf::Color(0, 255, 105, 180));
    else if (_color == "blue")
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

void LibOpengl::closeWindow()
{
    _window.close();
}

extern "C" IGraphic *createLib(void)
{
    return new LibOpengl;
}
