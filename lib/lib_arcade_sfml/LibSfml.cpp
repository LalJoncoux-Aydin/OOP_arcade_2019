#include "LibSfml.hpp"

LibSfml::LibSfml()
{
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
//
// void LibSfml::displayMenu(std::vector<std::string> list_name)
// {
//     //MANAGE ERROR LOADING
//     if (!_pTexture.loadFromFile("assets/background.png"))
//         std::cout <<"Error: image not loading" << std::endl;
//     if (!_font.loadFromFile("assets/neon2.ttf"))
//         std::cout << "Error: font not loading" << std::endl;
//
//     //         //PLAY MUSIC
//     //
//
//     //INIT THE BUTTON NIBBLER IN MENU
//     _nibbler.setFont(_font);
//     _nibbler.setCharacterSize(60);
//     _nibbler.setFillColor(sf::Color::White);
//     _nibbler.setStyle(sf::Text::Bold);
//     _nibbler.setString("NIBBLER");
//     _nibbler.setPosition(530, 660);
//
//
//     //INIT THE BUTTON EXIT IN MENU
//     _exit.setFont(_font);
//     _exit.setCharacterSize(60);
//     _exit.setFillColor(sf::Color::Magenta);
//     _exit.setStyle(sf::Text::Bold);
//     _exit.setString("EXIT");
//     _exit.setPosition(190, 770);
//
//
//     //INIT THE BUTTON PACMAN IN MENU
//     _pacman.setFont(_font);
//     _pacman.setCharacterSize(60);
//     _pacman.setFillColor(sf::Color::White);
//     _pacman.setStyle(sf::Text::Bold);
//     _pacman.setString("PACMAN");
//     _pacman.setPosition(900, 660);
//
//
//     //INIT THE BUTTON SFML IN MENU
//     _lib1.setFont(_font);
//     _lib1.setCharacterSize(60);
//     _lib1.setFillColor(sf::Color::White);
//     _lib1.setStyle(sf::Text::Bold);
//     _lib1.setString("SFML");
//     _lib1.setPosition(580, 545);
//
//
//     //INIT THE BUTTON NCURSE IN MENU
//     _lib2.setFont(_font);
//     _lib2.setCharacterSize(60);
//     _lib2.setFillColor(sf::Color::White);
//     _lib2.setStyle(sf::Text::Bold);
//     _lib2.setString("NCURSE");
//     _lib2.setPosition(770, 545);
//
//
//     //INIT THE BUTTON OPENGL IN MENU
//     _lib3.setFont(_font);
//     _lib3.setCharacterSize(60);
//     _lib3.setFillColor(sf::Color::White);
//     _lib3.setStyle(sf::Text::Bold);
//     _lib3.setString("OPENGL");
//     _lib3.setPosition(1000, 545);
//
//     //INIT THE NAME OF PLAYER IN MENU
//     _playerText.setFont(_font);
//     _playerText.setCharacterSize(60);
//     _playerText.setFillColor(sf::Color::White);
//     _playerText.setStyle(sf::Text::Bold);
//     _playerText.setPosition(480, 423);
//
//     //DISPLAY BACKGROUND
//     _playerImage.setTexture(_pTexture);
//
//     //DISPLAY BUTTON
// //    draw_text("NIBBLER", 60, sf::Color::White, 530, 660);
//     _window.draw(_playerImage);
//     _window.draw(_playerText);
//     _window.draw(_nibbler);
//     _window.draw(_exit);
//     _window.draw(_pacman);
//     _window.draw(_lib1);
//     _window.draw(_lib2);
//     _window.draw(_lib3);
//
//     // Display
//     _window.display();
// }

bool LibSfml::displayScene(std::vector<std::string> config_scene)
{
    return true;
}

void LibSfml::cleanScreen() {

};

bool drawText() {
    return true;
};

bool LibSfml::drawMap() {
    return true;
};

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
        }
        if (_exit.getGlobalBounds().contains(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
    //        sound.stop();
            closeWindow();
            return 84;
        }


        if (_Event.type == sf::Event::KeyPressed) {
            if (_Event.key.code == sf::Keyboard::F5) {
                closeWindow();
                return 5;
            }
            if (_Event.key.code == sf::Keyboard::F6) {
                closeWindow();
                return 6;
            }
            if (_Event.key.code == sf::Keyboard::F12) {
    //            sound.stop();
                closeWindow();
                return 84;
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
//
// void LibSfml::draw_text_sfml(char *string, int charSize, sf::Color color, int y_position, int x_position)
// {
//     // sf::Text text(string, _font);
//     // text.setPosition(y_position, x_position);
//     // text.setCharacterSize(charSize);
//     // text.setColor(color);
//     // _window.pushGLStates();
//     // _window.draw(text);
//     // _window.popGLStates();
//     //
//     // _lib3.setFont(_font);
//     // _lib3.setCharacterSize(60);
//     // _lib3.setFillColor(sf::Color::White);
//     // _lib3.setStyle(sf::Text::Bold);
//     // _lib3.setString("OPENGL");
//     // _lib3.setPosition(1000, 545);
// }

void LibSfml::closeWindow()
{
    _window.close();
    //_sound.stop();
}

extern "C" IGraphic *createLib(void)
{
    return new LibSfml;
}
