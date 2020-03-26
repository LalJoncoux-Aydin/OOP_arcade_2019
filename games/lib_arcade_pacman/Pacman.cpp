#include "Pacman.hpp"

Pacman::Pacman()
{
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
    // Construct map
    // for(size_t i = 0; i < config_file.size(); i++) {
    //     if (config_file[i].at(0) == '2') {
    //         _map.push_back(config_file[i]);
    //     }
    // }
    return config_file;
}

extern "C" IGames *createGame(void)
{
    return new Pacman;
}
