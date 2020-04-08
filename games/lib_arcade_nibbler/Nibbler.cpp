#include "Nibbler.hpp"

Nibbler::Nibbler()
{
}

std::vector<std::string> Nibbler::readSceneFile()
{
    std::string newline;
    std::ifstream stream_name(config_path);
    int x = 0;
    int y = 0;

    if (stream_name) {
        while (std::getline(stream_name, newline)) {
            x++;
            y = 0;
            config_file.push_back(newline);
            if (newline[0] == '2') {
                for(std::string::size_type z = 0; z < newline.size(); z++) {
                    if (newline[z] == 'P') {
                        _player.pos_x = x - 1;
                        _player.pos_y = y;
                        _player._pv = 1;
                    }
                    if (newline[z] == 'E') {
                        throw uncorrectMap();
                        std::exit(EXIT_FAILURE);
                    }
                    if (checkWalls(newline) == false) {
                        throw uncorrectMap();
                        std::exit(EXIT_FAILURE);
                    }
                    y++;
                }
            }
        }
    }
    return config_file;
}

bool Nibbler::checkWalls(std::string newline)
{
    std::string::size_type z = 0;

    while(z < newline.size())
        z++;
    if ((newline[z] != 'E' && newline[z] != '0' &&
    newline[z] != ' ') && (newline[2] != 'E' && newline[2] != '0' &&
    newline[2] != ' '))
        return true;
    return false;
}

int Nibbler::addGameInfo()
{
    size_t before_score = 0;
    size_t after_score = 0;

    // Check for left pv
    if (_player._pv == 0)
        return 1;

    // Rewrite score and pv
    for(std::vector<int>::size_type i = 0; i != config_file.size(); i++) {
        if (config_file[i][0] == '1' && config_file[i].find("Score :") != std::string::npos) {
            i++;
            before_score = config_file[i].find(',');
            std::string sub_before_score = config_file[i].substr(0, before_score + 1);
            after_score = config_file[i].find(',', before_score + 1);
            std::string sub_after_score = config_file[i].substr(after_score, config_file[i].size());
            config_file[i] = sub_before_score + std::to_string(_player._score) + sub_after_score;
        }
    }
    return 0;
}

int Nibbler::move_player(int x, int y)
{
    int new_player_y = _player.pos_y + y;
    int new_player_x = _player.pos_x + x;
    size_t randomX = rand()%(31-4 + 1) + 4;
    size_t randomY = rand()%(90 + 1);

    if (config_file[new_player_x][new_player_y] != ' ' && config_file[new_player_x][new_player_y] != 'O') {
        _player.getDammage();
        return 0;
    }

    config_file[_player.pos_x][_player.pos_y] = '/';

    // collision with walls
    if (config_file[new_player_x][new_player_y] == ' ') {
        int pos_x = _player.pos_x;
        int pos_y = _player.pos_y;
        int nb_body = 1;
        int direction = 0;

        for (nb_body = 1; nb_body <= (3 + _player._score); nb_body++) {
            if (config_file[pos_x + 1][pos_y] == '/' && direction != 1) {
                pos_x += 1;
                direction = 2;
            }
            if (config_file[pos_x - 1][pos_y] == '/' && direction != 2) {
                pos_x -= 1;
                direction = 1;
            }
            if (config_file[pos_x][pos_y + (-2)] == '/' && direction != 4) {
                pos_y += (-2);
                direction = 3;
            }
            if (config_file[pos_x][pos_y + 2] == '/' && direction != 3) {
                pos_y += 2;
                direction = 4;
            }
        }
        config_file[pos_x][pos_y] = ' ';

    } else if (config_file[new_player_x][new_player_y] == 'O') {
        randomX = rand()%(29-4 + 1) + 4;
        randomY = rand()%(90 + 1);
        while (config_file[randomX][randomY] != ' ') {
            randomX = rand()%(29-4 + 1) + 4;
            randomY = rand()%(90 + 1);
        }
        config_file[randomX][randomY] = 'O';
        _player.pickObject();
    }

    config_file[new_player_x][new_player_y] = 'P';

    _player._directionY = x;
    _player._directionX = y;
    _player.pos_x = new_player_x;
    _player.pos_y = new_player_y;
    return 0;
}

void Nibbler::writeHighScore(int score, std::string name, int id)
{
    std::string newline;
    std::ifstream stream_name("./games/highscore.txt");

    if (stream_name) {
        std::getline(stream_name, newline);
        if (newline.length() == 0) {
            std::ofstream outfile("./games/highscore.txt", std::ios::out | std::ios::trunc);
            if (outfile.is_open())
                outfile << std::to_string(score) << std::endl;
            outfile.close();
        } else {
            std::string temp = newline;
            std::string old_score;
            for (size_t pos = 0; (pos = temp.find(" ")) != std::string::npos; temp.erase(0, pos + 1));
            if (score > std::stoi(temp)) {
                std::string id_name = id == 1 ? "Nibbler" : "Pacman";
                if (name.length() <= 1)
                    name = "ANONYME";
                name = name + " " + id_name + " " + std::to_string(score);
                std::ofstream outfile("./games/highscore.txt", std::ios::out | std::ios::trunc);
                if (outfile.is_open())
                    outfile << name << std::endl;
                outfile.close();
            }
        }
        stream_name.close();
    } else {
        throw;
    }
    config_file.clear();
    _player.setPv(1);
    _player.setScore(0);
    _player.setDirectionX(0);
    _player.setDirectionY(0);
}

extern "C" IGames *createGame(void)
{
    return new Nibbler;
}
