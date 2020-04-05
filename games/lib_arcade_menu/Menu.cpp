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
            if (newline.find("Highscore :") != std::string::npos) {
                std::getline(stream_name, newline);
                std::string highscore;
                std::ifstream highscore_stream("./games/highscore.txt");

                if (stream_name) {
                    std::getline(highscore_stream, highscore);
                    if (highscore.length() != 0) {
                        //newline = highscore;
                        int before_score = newline.find(',');
                        std::string sub_before_score = newline.substr(0, before_score + 1);
                        int after_score = newline.find(',', before_score + 1);
                        std::string sub_after_score = newline.substr(after_score, newline.size());
                        highscore = sub_before_score + highscore + sub_after_score;
                    }
                    highscore_stream.close();
                    config_file.push_back(highscore);
                } else {
                    throw;
                }
            }
        }
        stream_name.close();
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

void Menu::writeHighScore(int score, __attribute__((unused))std::string name, __attribute__((unused))int id)
{


    std::cout << "score " << score << std::endl;
    // std::cout << "name " << name << std::endl;
    // std::cout << "id " << id << std::endl;
}

extern "C" IGames *createGame(void)
{
    return new Menu;
}
