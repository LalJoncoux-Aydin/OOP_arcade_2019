#include "Nibbler.hpp"

Nibbler::Nibbler()
{
    // Construct map
    for(size_t i = 0; i < config_file.size(); i++) {
        if (config_file[i].at(0) == '2') {
            std::cout << config_file[i] << std::endl;
        }
    }
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
