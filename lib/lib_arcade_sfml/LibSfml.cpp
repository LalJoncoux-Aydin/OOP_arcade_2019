#include "LibSfml.hpp"

LibSfml::LibSfml()
{
    //  MANAGE ERROR LOADING
    if (!_pTexture.loadFromFile("assets/background.png"))
        std::cout <<"Error: image not loading" << std::endl;
    if (!_font.loadFromFile("assets/neon2.ttf"))
        std::cout << "Error: font not loading" << std::endl;
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
    // sf::SoundBuffer buffer;
    // sf::Sound sound;
            //OPEN WINDOW

    _window.create(sf::VideoMode(1920, 1080, 32), "Arcade");
    _window.setKeyRepeatEnabled(false);

    //  if (!buffer.loadFromFile("assets/music.wav"))
    //      std::cout << "Error: music not loading" << std::endl;
    //
    // sound.setBuffer(buffer);
    // sound.play();

    return 0;
}

bool LibSfml::displayScene(std::vector<std::string> config_scene)
{
    size_t i = 0;
    int c = 0;

    for(; i < config_scene.size(); i++) {
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
            // values
            // drawMap()
        }
        //DISPLAY BACKGROUND
        _playerImage.setTexture(_pTexture);
    }
    _window.display();
    return true;
}

bool LibSfml::drawText(std::string _name, int pos_x, int pos_y, std::string _color, int charSize)
{
    sf::Text _text;
    _text.setString((char *)_name.c_str());
    _text.setFont(_font);
    _text.setStyle(sf::Text::Bold);
    _text.setPosition(pos_x, pos_y);
    _text.setCharacterSize(charSize);
    if (_color == "white")
        _text.setFillColor(sf::Color::White);
    else if (_color == "pink")
        _text.setFillColor(sf::Color::Magenta);
    else {
        throw getGraphicFail();
        return false;
    }
    _window.draw(_playerImage);
    _window.draw(_text);
    return true;
};

bool LibSfml::drawMap() {
    return true;
};

bool LibSfml::drawHero()
{

}

bool LibSfml::drawEnnemies()
{

}

bool LibSfml::drawObject()
{

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
                closeWindow();
                return 2;
            }
            if (_Event.key.code == sf::Keyboard::F) {
                closeWindow();
                return 3;
            }
            if (_Event.key.code == sf::Keyboard::F12) {
    //            sound.stop();
                closeWindow();
                return 84;
            }
            if (_Event.key.code == sf::Keyboard::F4) {
                return 4;
            }
            if (_Event.key.code == sf::Keyboard::F5) {
                return 5;
            }
            if (_Event.key.code == sf::Keyboard::F6) {
                return 6;
            }
            if (_Event.key.code == sf::Keyboard::F7) {
                return 7;
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
    _window.close();
    //_sound.stop();
}

extern "C" IGraphic *createLib(void)
{
    return new LibSfml;
}
