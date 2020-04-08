#include "LibOpengl.hpp"
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
// Include GLM
//#include <glm/glm.hpp>
//using namespace glm;

//sf::Music _music;

LibOpengl::LibOpengl()
{
    if (!_texture.loadFromFile("lib/lib_arcade_opengl/assets/fond2.jpg", sf::IntRect(0, 0, 3000, 3000)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_font.loadFromFile("lib/lib_arcade_opengl/assets/spaceranger.ttf"))
        std::cerr << "Warning: cannot load regular.tff" << std::endl;
    // if (!_texture1.loadFromFile("lib/lib_arcade_opengl/assets/hilary1.jpg", sf::IntRect(0, 0, 3000, 3000)))
    //     std::cout <<"Error: image not loading" << std::endl;
    if (!_wallA.loadFromFile("lib/lib_arcade_opengl/assets/A_small.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_blue.loadFromFile("lib/lib_arcade_opengl/assets/blue.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_orange.loadFromFile("lib/lib_arcade_opengl/assets/orange.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_pink.loadFromFile("lib/lib_arcade_opengl/assets/pink.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_body.loadFromFile("lib/lib_arcade_opengl/assets/body.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_head.loadFromFile("lib/lib_arcade_opengl/assets/head.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wallpp.loadFromFile("lib/lib_arcade_opengl/assets/black.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wall0.loadFromFile("lib/lib_arcade_opengl/assets/0.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wall6.loadFromFile("lib/lib_arcade_opengl/assets/6.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wall8.loadFromFile("lib/lib_arcade_opengl/assets/8.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wall9.loadFromFile("lib/lib_arcade_opengl/assets/9.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wall7.loadFromFile("lib/lib_arcade_opengl/assets/7.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wall4.loadFromFile("lib/lib_arcade_opengl/assets/4.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wall5.loadFromFile("lib/lib_arcade_opengl/assets/5.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wallN.loadFromFile("lib/lib_arcade_opengl/assets/N.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wall3.loadFromFile("lib/lib_arcade_opengl/assets/3.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wall2.loadFromFile("lib/lib_arcade_opengl/assets/2.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wallH.loadFromFile("lib/lib_arcade_opengl/assets/H.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wallK.loadFromFile("lib/lib_arcade_opengl/assets/K.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wallO.loadFromFile("lib/lib_arcade_opengl/assets/O.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wallI.loadFromFile("lib/lib_arcade_opengl/assets/I.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wallM.loadFromFile("lib/lib_arcade_opengl/assets/M.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wallZ.loadFromFile("lib/lib_arcade_opengl/assets/Z.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wallE.loadFromFile("lib/lib_arcade_opengl/assets/E.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wallU.loadFromFile("lib/lib_arcade_opengl/assets/U.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wallV.loadFromFile("lib/lib_arcade_opengl/assets/V.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wallY.loadFromFile("lib/lib_arcade_opengl/assets/Y.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wallG.loadFromFile("lib/lib_arcade_opengl/assets/G.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wall1.loadFromFile("lib/lib_arcade_opengl/assets/1.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_died.loadFromFile("lib/lib_arcade_opengl/assets/died.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wallW.loadFromFile("lib/lib_arcade_opengl/assets/D.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wallQ.loadFromFile("lib/lib_arcade_opengl/assets/Q.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wallT.loadFromFile("lib/lib_arcade_opengl/assets/T.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_wallX.loadFromFile("lib/lib_arcade_opengl/assets/X.png", sf::IntRect(0, 0, 37, 37)))
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
    if (!_pacman.loadFromFile("lib/lib_arcade_opengl/assets/pacman.png", sf::IntRect(0, 0, 80, 80)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_rouge.loadFromFile("lib/lib_arcade_opengl/assets/rouge.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_fruit.loadFromFile("lib/lib_arcade_opengl/assets/fruit.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_big.loadFromFile("lib/lib_arcade_opengl/assets/Big.png"))
        std::cout <<"Error: image not loading" << std::endl;

    _sWallA.setTexture(_wallA);
    _sWallB.setTexture(_wallB);
    _sWallX.setTexture(_wallX);
    _sWall1.setTexture(_wall1);
    _sWallY.setTexture(_wallY);
    _sWallC.setTexture(_wallC);
    _sWallV.setTexture(_wallV);
    _sWallD.setTexture(_wallD);
    _sWall4.setTexture(_wall4);
    _sWall5.setTexture(_wall5);
    _spink.setTexture(_pink);
    _sblue.setTexture(_blue);
    _sWallH.setTexture(_wallH);
    _sWallG.setTexture(_wallG);
    _sWall8.setTexture(_wall8);
    _sWall9.setTexture(_wall9);
    _sorange.setTexture(_orange);
    _sWallT.setTexture(_wallT);
    _sWallN.setTexture(_wallN);
    _sWall2.setTexture(_wall2);
    _sWall3.setTexture(_wall3);
    _sWall6.setTexture(_wall6);
    _sWallpp.setTexture(_wallpp);
    _sWall7.setTexture(_wall7);
    _sWall0.setTexture(_wall0);
    _sWallM.setTexture(_wallM);
    _sdied.setTexture(_died);
    _sWallZ.setTexture(_wallZ);
    _sWallQ.setTexture(_wallQ);
    _sWallK.setTexture(_wallK);
    _sWallL.setTexture(_wallL);
    _sWallR.setTexture(_wallR);
    _sWallU.setTexture(_wallU);
    _sWallE.setTexture(_wallE);
    _sWallW.setTexture(_wallW);
    _sWallO.setTexture(_wallO);
    _sWallI.setTexture(_wallI);
    _spacman.setTexture(_pacman);
    _shead.setTexture(_head);
    _sbody.setTexture(_body);
    _sbig.setTexture(_big);
    _srouge.setTexture(_rouge);
    _sfruit.setTexture(_fruit);
    playerImage.setTexture(_texture);
    playerFun.setTexture(_texture1);
}

int LibOpengl::openWindow()
{
     sf::ContextSettings settings;


   /* if (!_music.openFromFile("lib/lib_arcade_opengl/assets/music.wav"))
        std::cout <<"Error: image not loading" << std::endl;*/
    _window.create(sf::VideoMode(1920, 1080, 32), "Arcade", sf::Style::Fullscreen);
    _window.setVerticalSyncEnabled(true);
    //_sound.setBuffer(_buffer);
    //_sound.play();
   // _music.play();
   // _music.setLoop(true);
    playerText.setFont(_font);
    if (_name.length() != 0)
        playerText.setString(_name);
    else
        playerText.setString("||");
    playerText.setCharacterSize(50);
    playerText.setFillColor(sf::Color::White);
    playerText.setPosition(730, 400);

    // effacement les tampons de couleur/profondeur
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    return 0;
}

bool LibOpengl::displayScene(std::vector<std::string> config_scene, int id, std::vector<Ennemies> ennemies_list)
{
    int x = 150;
    int y = 150;

    _window.pushGLStates();
    _window.draw(playerImage);
    _window.draw(playerFun);
    for(size_t i = 0; i < config_scene.size(); i++) {
        std::vector<std::string> l_command;
        std::stringstream s_stream(config_scene[i]);
        for(int c = 0; s_stream.good(); c++){
            std::string param;
            getline(s_stream, param, ',');
            l_command.push_back(param);
        }
        if (l_command[0] == "1") {
            if (l_command[1] == "Player name :") {
                _window.draw(playerText);
            }
            if (drawText(l_command[1], std::stoi(l_command[2]), std::stoi(l_command[3]), l_command[4], std::stoi(l_command[5])) == false)
                return false;
        }
        if (l_command[0] == "2") {
            for(std::string::size_type z = 1; z < l_command.size(); z++) {
                if (l_command[z] == "P") {
                    if (drawPlayer(x, y, id) == false)
                        return false;
                }
                else if (l_command[z]  == "/") {
                    if (displayBody(x, y) == false)
                        return false;

                } else if(l_command[z] == "O") {
                    if (drawObject(x, y) == false)
                        return false;
                } else if(l_command[z] == "E") {
                    if (drawEnemies(x, y, ennemies_list, i, z) == false)
                        return false;
                } else {
                    if (drawMap(l_command[z][0], x, y) == false)
                        return false;
                }
                x += 32;
            }
            y += 35;
            x = 150;
        }
    }
    _window.popGLStates();
    _window.display();
    _name = (std::string) playerText.getString();
    return true;
}

/*void LibOpengl::playMusic(void)
{
    _music.play();
    _music.setLoop(true);
}

void LibOpengl::breakMusic(void)
{
    _music.pause();
}

void LibOpengl::stopMusic(void)
{
    _music.stop();
}*/
void LibOpengl::displayLoose()
{
    _window.pushGLStates();
    _window.draw(playerImage);
    _window.draw(playerFun);
    std::string _text = "You lost !";
    drawText(_text, 760, 480, "white", 50);
    _window.popGLStates();
    _window.display();
}

bool LibOpengl::drawPlayer(int x, int y, int id)
{

    if (id == 1) {
        _window.setFramerateLimit(10);
        _shead.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_shead);
        _window.popGLStates();
        return (true);
    }
    if (id == 2) {
        _spacman.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_spacman);
        _window.popGLStates();
        return true;
    }
    return false;
}

bool LibOpengl::displayBody(int x, int y)
{
    _sbody.setPosition(sf::Vector2f(x - 1, y + 1));
    _window.pushGLStates();
    _window.draw(_sbody);
    _window.popGLStates();
    return true;

}

bool LibOpengl::drawEnemies(int x, int y, std::vector<Ennemies> ennemies_list, int ennemie_x, int ennemie_y)
{
    for (size_t i = 0; i < ennemies_list.size(); i++) {
        if ((ennemies_list[i].pos_x == ennemie_x && ennemies_list[i].pos_y == ennemie_y * 2) ||
            (ennemies_list[i].home_x == ennemie_x && ennemies_list[i].home_y == ennemie_y * 2))    {

            if (ennemies_list[i]._vulnerable == true) {
                _sdied.setPosition(sf::Vector2f(x, y));
                _window.pushGLStates();
                _window.draw(_sdied);
                _window.popGLStates();
            } else if (i == 0) {
                _srouge.setPosition(sf::Vector2f(x, y));
                _window.pushGLStates();
                _window.draw(_srouge);
                _window.popGLStates();
                return true;
            } else if (i == 1) {
                _spink.setPosition(sf::Vector2f(x, y));
                _window.pushGLStates();
                _window.draw(_spink);
                _window.popGLStates();
                return true;
            } else if (i == 2) {
                _sblue.setPosition(sf::Vector2f(x, y));
                _window.pushGLStates();
                _window.draw(_sblue);
                _window.popGLStates();
                return true;
            } else if (i == 3) {
                _sorange.setPosition(sf::Vector2f(x, y));
                _window.pushGLStates();
                _window.draw(_sorange);
                _window.popGLStates();
                return true;
            }
        }
    }
    return true;
}

bool LibOpengl::drawObject(int x, int y)
{
    _sfruit.setPosition(sf::Vector2f(x, y));
    _window.pushGLStates();
    _window.draw(_sfruit);
    _window.popGLStates();
    return true;
}

bool LibOpengl::drawText(std::string _text, int pos_x, int pos_y, std::string _color, int charSize)
{
    sf::Text text((char*)_text.c_str(), _font);
    text.setPosition(pos_x, pos_y);
    text.setCharacterSize(charSize);
    if (_color == "cyan")
        text.setFillColor(sf::Color(0, 0, 255, 255));
    else if (_color == "white")
        text.setFillColor(sf::Color(0, 255, 255, 255));
    else if (_color == "pink")
        text.setFillColor(sf::Color(0, 255, 105, 180));
    else if (_color == "blue")
        text.setFillColor(sf::Color(0, 0, 191, 255));
    else {
        throw getGraphicFail();
        return false;
    }
    _window.pushGLStates();
    _window.draw(text);
    _window.popGLStates();
    return true;
}

bool LibOpengl::drawMap(char _letter, int x, int y)
{
    if (_letter == 'A') {
        _sWallA.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWallA);
        _window.popGLStates();
        return true;
    } else if (_letter == 'B') {
        _sWallB.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWallB);
        _window.popGLStates();
        return true;
    } else if (_letter == '2') {
        _sWall2.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWall2);
        _window.popGLStates();
        return true;
    } else if (_letter == '8') {
        _sWall8.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWall8);
        _window.popGLStates();
        return true;
    } else if (_letter == '9') {
        _sWall9.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWall9);
        _window.popGLStates();
        return true;
    } else if (_letter == '0') {
        _sWall0.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWall0);
        _window.popGLStates();
        return true;
    } else if (_letter == '#') {
        _spink.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_spink);
        _window.popGLStates();
        return true;
    } else if (_letter == '_') {
        _sbig.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sbig);
        _window.popGLStates();
        return true;
    } else if (_letter == '.') {
        _sblue.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sblue);
        _window.popGLStates();
        return true;
    } else if (_letter == '1') {
        _sWall1.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWall1);
        _window.popGLStates();
        return true;
    } else if (_letter == 'S') {
        _sWallE.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWallE);
        _window.popGLStates();
        return true;
    } else if (_letter == 'K') {
        _sWallK.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWallK);
        _window.popGLStates();
        return true;
    } else if (_letter == '"') {
        _sorange.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sorange);
        _window.popGLStates();
        return true;
    } else if (_letter == '4') {
        _sWall4.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWall4);
        _window.popGLStates();
        return true;
    } else if (_letter == '5') {
        _sWall5.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWall5);
        _window.popGLStates();
        return true;
    } else if (_letter == 'N') {
        _sWallN.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWallN);
        _window.popGLStates();
        return true;
    } else if (_letter == '3') {
        _sWall3.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWall3);
        _window.popGLStates();
        return true;
    } else if (_letter == 'Z') {
        _sWallZ.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWallZ);
        _window.popGLStates();
        return true;
    } else if (_letter == '6') {
        _sWall6.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWall6);
        _window.popGLStates();
        return true;
    } else if (_letter == '7') {
        _sWall7.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWall7);
        _window.popGLStates();
        return true;
    } else if (_letter == '-') {
        _sdied.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sdied);
        _window.popGLStates();
        return true;
    } else if (_letter == 'Y') {
        _sWallY.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWallY);
        _window.popGLStates();
        return true;
    } else if (_letter == 'T') {
        _sWallT.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWallT);
        _window.popGLStates();
        return true;
    } else if (_letter == 'X') {
        _sWallX.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWallX);
        _window.popGLStates();
        return true;
    } else if (_letter == 'G') {
        _sWallG.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWallG);
        _window.popGLStates();
        return true;
    } else if (_letter == 'Q') {
        _sWallQ.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWallQ);
        _window.popGLStates();
        return true;
    } else if (_letter == 'J') {
        _sWallO.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWallO);
        _window.popGLStates();
        return true;
    } else if (_letter == 'I') {
        _sWallI.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWallI);
        _window.popGLStates();
        return true;
    } else if (_letter == 'M') {
        _sWallM.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWallM);
        _window.popGLStates();
        return true;
    } else if (_letter == 'C') {
        _sWallC.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWallC);
        _window.popGLStates();
        return true;
    } else if (_letter == 'D') {
        _sWallD.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWallD);
        _window.popGLStates();
        return true;
    } else if (_letter == 'L') {
        _sWallL.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWallL);
        _window.popGLStates();
        return true;
    } else if (_letter == 'V') {
        _sWallV.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWallV);
        _window.popGLStates();
        return true;
    } else if (_letter == 'W') {
        _sWallW.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWallW);
        _window.popGLStates();
        return true;
    } else if (_letter == 'U') {
        _sWallU.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWallU);
        _window.popGLStates();
        return true;
    } else if (_letter == 'H') {
        _sWallH.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWallH);
        _window.popGLStates();
        return true;
    } else if (_letter == 'R') {
        _sWallR.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWallR);
        _window.popGLStates();
        return true;
    } else if (_letter == ' ' || _letter == '!') {
        _sWallpp.setPosition(sf::Vector2f(x, y));
        _window.pushGLStates();
        _window.draw(_sWallpp);
        _window.popGLStates();
        return true;
    } else if (_letter == '@') {
        return true;
    } else {
        throw uncorrectMap();
        return false;
    }
}

int LibOpengl::getKey()
{
    // gestion des évènements
    sf::Event event;




    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            //_music.stop();
            closeWindow();
           // _sound.stop();
           //_music.stop();
            return 84;
        } else if (event.type == sf::Event::TextEntered) {
            playerInput += event.text.unicode;
            playerText.setString(playerInput);
            return 0;
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::F2)
                return 2;
            if (event.key.code == sf::Keyboard::F3)
                return 3;
            if (event.key.code == sf::Keyboard::F4)
                return 4;
            if (event.key.code == sf::Keyboard::F5)
                return 5;
            if (event.key.code == sf::Keyboard::F6) {
                //_music.stop();
                return 6;
            }
            if (event.key.code == sf::Keyboard::F7) {
                //_music.stop();
                return 7;
            }
            if (event.key.code == sf::Keyboard::Left)
                return 12;
            if (event.key.code == sf::Keyboard::Right)
                return 15;
            if (event.key.code == sf::Keyboard::Down)
                return 14;
            if (event.key.code == sf::Keyboard::Up)
                return 13;
            if (event.key.code == sf::Keyboard::F12) {
               // _sound.stop();
                return 84;
            }
            if (event.key.code == sf::Keyboard::Return) {
               // _window.clear();
                _window.pushGLStates();
                _window.draw(playerFun);
                _window.popGLStates();
               // _window.draw(rectangle);
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

void LibOpengl::closeWindow()
{
    //_music.stop();
    _window.close();
   // _music.stop();
}

extern "C" IGraphic *createLib(void)
{
    return new LibOpengl;
}
