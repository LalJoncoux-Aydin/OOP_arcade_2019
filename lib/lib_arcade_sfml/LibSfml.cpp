#include "LibSfml.hpp"

sf::Music _music;

LibSfml::LibSfml()
{
    //  MANAGE ERROR LOADING
    if (!_pTexture.loadFromFile("assets/Game.png"))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_font.loadFromFile("assets/neon2.ttf"))
        std::cout << "Error: font not loading" << std::endl;
    if (!_wallA.loadFromFile("lib/lib_arcade_opengl/assets/A_small.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_blue.loadFromFile("lib/lib_arcade_opengl/assets/blue.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_pink.loadFromFile("lib/lib_arcade_opengl/assets/pink.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_orange.loadFromFile("lib/lib_arcade_opengl/assets/orange.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_died.loadFromFile("lib/lib_arcade_opengl/assets/died.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_big.loadFromFile("lib/lib_arcade_opengl/assets/Big.png", sf::IntRect(0, 0, 37, 37)))
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
    if (!_pacman.loadFromFile("lib/lib_arcade_opengl/assets/pacman.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_rouge.loadFromFile("lib/lib_arcade_opengl/assets/rouge.png", sf::IntRect(0, 0, 37, 37)))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_fruit.loadFromFile("lib/lib_arcade_opengl/assets/fruit.png", sf::IntRect(0, 0, 37, 37)))
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
    _sWallH.setTexture(_wallH);
    _sWallG.setTexture(_wallG);
    _sWall8.setTexture(_wall8);
    _sWall9.setTexture(_wall9);
    _sWallT.setTexture(_wallT);
    _sWallN.setTexture(_wallN);
    _sWall2.setTexture(_wall2);
    _sWall3.setTexture(_wall3);
    _sWall6.setTexture(_wall6);
    _sWallpp.setTexture(_wallpp);
    _sWall7.setTexture(_wall7);
    _sWall0.setTexture(_wall0);
    _sWallM.setTexture(_wallM);
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
    _sblue.setTexture(_blue);
    _spink.setTexture(_pink);
    _sbig.setTexture(_big);
    _sorange.setTexture(_orange);
    _sdied.setTexture(_died);
    _spacman.setTexture(_pacman);
    _shead.setTexture(_head);
    _sbody.setTexture(_body);
    _srouge.setTexture(_rouge);
    _sfruit.setTexture(_fruit);
}


//
// void LibSfml::check_mouse_pos(sf::Event::MouseMoveEvent const &mouse, sf::Text &text, bool isSelected)
// {
//     sf::FloatRect bounds = text.getGlobalBounds();
//
//     if (
//         isSelected
//         || (
//             mouse.x >= bounds.left
//             && mouse.y >= bounds.top
//             && mouse.x <= bounds.left + bounds.width
//             && mouse.y <= bounds.top + bounds.height
//         )
//     )
//         text.setFillColor(sf::Color::Red);
//     else
//         text.setFillColor(sf::Color::White);
// }
//
// void LibSfml::check_mouse_click(sf::Event const &event, sf::Text &text, bool &isSelected)
// {
//     sf::Event::MouseButtonEvent mouse = event.mouseButton;
//     sf::FloatRect bounds = text.getGlobalBounds();
//
//     if (
//         mouse.x >= bounds.left
//         && mouse.y >= bounds.top
//         && mouse.x <= bounds.left + bounds.width
//         && mouse.y <= bounds.top + bounds.height
//     )
//          isSelected = true;
//        //text.setFillColor(sf::Color::Magenta);
//     else {
//         text.setFillColor(sf::Color::White);
//         isSelected = false;
//     }
// }

int LibSfml::openWindow()
{

    if (!_music.openFromFile("lib/lib_arcade_opengl/assets/music.wav"))
        std::cout <<"Error: image not loading" << std::endl;

    // sf::SoundBuffer buffer;
    // sf::Sound sound;
            //OPEN WINDOW
    _window.create(sf::VideoMode(1920, 1080, 32), "Arcade", sf::Style::Fullscreen);
    _window.setVerticalSyncEnabled(true);
    _music.play();
    _music.setLoop(true);

    _playerText.setFont(_font);
    if (_name.length() != 0)
        _playerText.setString(_name);
    else
        _playerText.setString("");
    _playerText.setCharacterSize(60);
    _playerText.setFillColor(sf::Color::White);
    _playerText.setStyle(sf::Text::Bold);
    _playerText.setPosition(700, 390);

    //  if (!buffer.loadFromFile("assets/music.wav"))
    //      std::cout << "Error: music not loading" << std::endl;
    //
    // sound.setBuffer(buffer);
    // sound.play();

    return 0;
}

bool LibSfml::displayScene(std::vector<std::string> config_scene, int id, std::vector<Ennemies> ennemies_list)
{
    int x = 150;
    int y = 150;

    _window.draw(_playerImage);
    for(size_t i = 0; i < config_scene.size(); i++) {
        std::vector<std::string> l_command;
        std::stringstream s_stream(config_scene[i]);
        for(int c = 0; s_stream.good(); c++){
            std::string param;
            getline(s_stream, param, ',');
            l_command.push_back(param);
        }
        if (l_command[0] == "1") {
            if (l_command[1] == "Player name :")
                _window.draw(_playerText);
            if (drawText(l_command[1], std::stoi(l_command[2]), std::stoi(l_command[3]), l_command[4], std::stoi(l_command[5])) == false)
                return false;
        }
        if (l_command[0] == "2") {
            for(std::string::size_type z = 1; z < l_command.size(); z++) {
                if (l_command[z] == "P") {// || l_command[z] == "/") {
                    if (drawPlayer(x, y, id) == false)
                        return false;
                } else if (l_command[z] == "/") {
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
        //DISPLAY BACKGROUND
        _playerImage.setTexture(_pTexture);
    }
    _window.display();
    _name = (std::string) _playerText.getString();
//    std::cout << "sfml name " << _name << std::endl;
    return true;
}

void LibSfml::displayLoose()
{
    _window.draw(_playerImage);
    std::string _text = "You lost !";
    drawText(_text, 760, 480, "white", 50);
    _window.display();
}

bool LibSfml::drawText(std::string _name, int pos_x, int pos_y, std::string _color, int charSize)
{
    sf::Text _text((char *)_name.c_str(),_font);
    _text.setPosition(pos_x, pos_y);
    _text.setCharacterSize(charSize);
    _text.setStyle(sf::Text::Bold);
    if (_color == "cyan")
        _text.setFillColor(sf::Color(0, 0, 255, 255));
    else if (_color == "white")
        _text.setFillColor(sf::Color(255, 255, 255, 255));
    else if (_color == "pink")
        _text.setFillColor(sf::Color::Magenta);
    else if (_color == "blue")
        _text.setFillColor(sf::Color(0, 0, 191, 255));
    else {
        throw getGraphicFail();
        return false;
    }
    _window.draw(_text);
    return true;
}

bool LibSfml::drawPlayer(int x, int y, int id)
{
    if (id == 1) {
        _window.setFramerateLimit(10);
        _shead.setPosition(sf::Vector2f(x, y));
        _window.draw(_shead);
        return (true);
    }
    if (id == 2) {
        _spacman.setPosition(sf::Vector2f(x, y));
        _window.draw(_spacman);
        return true;
    }
    return false;
}

bool LibSfml::displayBody(int x, int y)
{
    _sbody.setPosition(sf::Vector2f(x - 1, y + 1));
    _window.draw(_sbody);
    return true;
}

bool LibSfml::drawEnemies(int x, int y, std::vector<Ennemies> ennemies_list, int ennemie_x, int ennemie_y)
{
    for (size_t i = 0; i < ennemies_list.size(); i++) {
        if ((ennemies_list[i].pos_x == ennemie_x && ennemies_list[i].pos_y == ennemie_y * 2) ||
            (ennemies_list[i].home_x == ennemie_x && ennemies_list[i].home_y == ennemie_y * 2)) {

            if (i == 0) {
                _srouge.setPosition(sf::Vector2f(x, y));
                _window.draw(_srouge);
                return true;
            }
            if (i == 1) {
                _spink.setPosition(sf::Vector2f(x, y));
                _window.draw(_spink);
                return true;
            }
            if (i == 2) {
                _sblue.setPosition(sf::Vector2f(x, y));
                _window.draw(_sblue);
                return true;
            }
            if (i == 3) {
                _sorange.setPosition(sf::Vector2f(x, y));
                _window.draw(_sorange);
                return true;
            }
        }
    }
    return true;
}

bool LibSfml::drawObject(int x, int y)
{
    _sfruit.setPosition(sf::Vector2f(x, y));
    _window.draw(_sfruit);
    return true;
}

bool LibSfml::drawMap(char _letter, int x, int y)
{
    if (_letter == 'A') {
        _sWallA.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallA);
        return true;
    } else if (_letter == 'B') {
        _sWallB.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallB);
        return true;
    } else if (_letter == '#') {
        _spink.setPosition(sf::Vector2f(x, y));
        _window.draw(_spink);
        return true;
    } else if (_letter == '"') {
        _sorange.setPosition(sf::Vector2f(x, y));
        _window.draw(_sorange);
        return true;
    } else if (_letter == '.') {
        _sblue.setPosition(sf::Vector2f(x, y));
        _window.draw(_sblue);
        return true;
    } else if (_letter == '-') {
        _sdied.setPosition(sf::Vector2f(x, y));
        _window.draw(_sdied);
        return true;
    } else if (_letter == '_') {
        _sbig.setPosition(sf::Vector2f(x, y));
        _window.draw(_sbig);
        return true;
    } else if (_letter == '2') {
        _sWall2.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWall2);
        return true;
    } else if (_letter == '8') {
        _sWall8.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWall8);
        return true;
    } else if (_letter == '9') {
        _sWall9.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWall9);
        return true;
    } else if (_letter == '0') {
        _sWall0.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWall0);
        return true;
    } else if (_letter == '1') {
        _sWall1.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWall1);
        return true;
    } else if (_letter == 'S') {
        _sWallE.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallE);
        return true;
    } else if (_letter == 'K') {
        _sWallK.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallK);
        return true;
    } else if (_letter == '4') {
        _sWall4.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWall4);
        return true;
    } else if (_letter == '5') {
        _sWall5.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWall5);
        return true;
    } else if (_letter == 'N') {
        _sWallN.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallN);
        return true;
    } else if (_letter == '3') {
        _sWall3.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWall3);
        return true;
    } else if (_letter == 'Z') {
        _sWallZ.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallZ);
        return true;
    } else if (_letter == '6') {
        _sWall6.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWall6);
        return true;
    } else if (_letter == '7') {
        _sWall7.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWall7);
        return true;
    } else if (_letter == 'Y') {
        _sWallY.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallY);
        return true;
    } else if (_letter == 'T') {
        _sWallT.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallT);
        return true;
    } else if (_letter == 'X') {
        _sWallX.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallX);
        return true;
    } else if (_letter == 'G') {
        _sWallG.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallG);
        return true;
    } else if (_letter == 'Q') {
        _sWallQ.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallQ);
        return true;
    } else if (_letter == 'J') {
        _sWallO.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallO);
        return true;
    } else if (_letter == 'I') {
        _sWallI.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallI);
        return true;
    } else if (_letter == 'M') {
        _sWallM.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallM);
        return true;
    } else if (_letter == 'C') {
        _sWallC.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallC);
        return true;
    } else if (_letter == 'D') {
        _sWallD.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallD);
        return true;
    } else if (_letter == 'L') {
        _sWallL.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallL);
        return true;
    } else if (_letter == 'V') {
        _sWallV.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallV);
        return true;
    } else if (_letter == 'W') {
        _sWallW.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallW);
        return true;
    } else if (_letter == 'U') {
        _sWallU.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallU);
        return true;
    } else if (_letter == 'H') {
        _sWallH.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallH);
        return true;
    } else if (_letter == 'R') {
        _sWallR.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallR);
        return true;
    } else if (_letter == ' ' || _letter == '!') {
        _sWallpp.setPosition(sf::Vector2f(x, y));
        _window.draw(_sWallpp);
        return true;
    } else if (_letter == '@') {
        return true;
    } else {
        throw uncorrectMap();
        return false;
    }
}

int LibSfml::getKey()
{
    while(_window.pollEvent(_Event)) {
        switch (_Event.type) {
        case sf::Event::Closed:
    //        sound.stop();
            closeWindow();
            return 84;

        case sf::Event::TextEntered:
            _playerInput += _Event.text.unicode;
            _playerText.setString(_playerInput);
            break;
        default:
            break;
        }
        if (_exit.getGlobalBounds().contains(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
    //        sound.stop();
            closeWindow();
            return 84;
        }


        if (_Event.type == sf::Event::KeyPressed) {
            if (_Event.key.code == sf::Keyboard::F2) {
                return 2;
            }
            if (_Event.key.code == sf::Keyboard::F3) {
                return 3;
            }
            if (_Event.key.code == sf::Keyboard::F12) {
                return 84;
            }
            if (_Event.key.code == sf::Keyboard::F4) {
                return 4;
            }
            if (_Event.key.code == sf::Keyboard::F5) {
                return 5;
            }
            if (_Event.key.code == sf::Keyboard::F6) {
                //_music.stop();
                return 6;
            }
            if (_Event.key.code == sf::Keyboard::F7) {
               // _music.stop();
                return 7;
            }
            if (_Event.key.code == sf::Keyboard::Return) {
                _window.clear();
                _window.display();
                return 10;
            }
            if (_Event.key.code == sf::Keyboard::Left) {
                return 12;
            }
            if (_Event.key.code == sf::Keyboard::Down) {
                return 14;
            }
            if (_Event.key.code == sf::Keyboard::Right) {
                return 15;
            }
            if (_Event.key.code == sf::Keyboard::Up) {
                return 13;
            }
        }

        //     //EFFECTS ON BUTTON
        // if (_Event.type == sf::Event::MouseMoved) {
        //
        //     check_mouse_pos(_Event.mouseMove, _lib1, _isSelected3);
        //     check_mouse_pos(_Event.mouseMove, _lib2, _isSelected4);
        //     check_mouse_pos(_Event.mouseMove, _lib3, _isSelected5);
        //
        // }
        //
        //     //EFFECTS ON CLICK
        // if (_Event.type == sf::Event::MouseButtonPressed && _Event.mouseButton.button == sf::Mouse::Button::Left) {
        //     check_mouse_click(_Event, _lib1, _isSelected3);
        //     check_mouse_click(_Event, _lib2, _isSelected4);
        //     check_mouse_click(_Event, _lib3, _isSelected5);
        // }
        //
        //     //EFFECT ON BUTTON
        // if (_Event.type == sf::Event::MouseMoved) {
        //     check_mouse_pos(_Event.mouseMove, _nibbler, _isSelected);
        //     check_mouse_pos(_Event.mouseMove, _pacman, _isSelected2);
        //
        //     //EFFECT ON CLICK
        // }
        // if (_Event.type == sf::Event::MouseButtonPressed && _Event.mouseButton.button == sf::Mouse::Button::Left) {
        //     check_mouse_click(_Event, _nibbler, _isSelected);
        //     check_mouse_click(_Event, _pacman, _isSelected2);
        // }

    }
    return 0;
}

void LibSfml::closeWindow()
{
    //_music.stop();
    _window.close();
    //_sound.stop();
}

extern "C" IGraphic *createLib(void)
{
    return new LibSfml;
}
