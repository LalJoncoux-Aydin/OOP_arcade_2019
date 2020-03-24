#include "Pacman.hpp"

Pacman::Pacman()
{
    // Construct map
}

std::vector<std::string> Pacman::readSceneFile()
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
    return new Pacman;
}
