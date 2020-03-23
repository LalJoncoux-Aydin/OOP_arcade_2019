#include "Nibbler.hpp"

Nibbler::Nibbler()
{

}

int Nibbler::startGame()
{
    std::cout << "caca" << std::endl;
    return 0;
}

std::vector<std::string> Nibbler::readSceneFile()
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

extern "C" IGames *createGame(void)
{
    return new Nibbler;
}
