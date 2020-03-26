#include "Menu.hpp"

Menu::Menu()
{

}

std::vector<std::string> Menu::readSceneFile()
{
    std::string newline;
    std::ifstream stream_name(config_path);

    if (stream_name) {
        while (std::getline(stream_name, newline)) {
            config_file.push_back(newline);
        }
    }
    return config_file;
}

void Menu::changeSelection(int selected)
{
    if (selected == 2)
        config_path = nibbler_select;
    if (selected == 3)
        config_path = pacman_select;
}

extern "C" IGames *createGame(void)
{
    return new Menu;
}
