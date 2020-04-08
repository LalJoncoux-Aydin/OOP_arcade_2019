#include "Pacman.hpp"

Pacman::Pacman()
{
}

std::vector<std::string> Pacman::readSceneFile()
{
    std::string newline;
    std::ifstream stream_name(config_path);
    int x = 0;

    if (stream_name) {
        config_file.clear();
        ennemies_list.clear();
        while (std::getline(stream_name, newline)) {
            x++;
            if (newline[0] == '2') {
                for(std::string::size_type z = 0; z < newline.size(); z++) {
                    if (newline[z] == 'E') {
                        _hasEnnemies = true;
                        Ennemies _new_ennemie;
                        _new_ennemie.home_x = x - 1;
                        _new_ennemie.home_y = z;
                        _new_ennemie.pos_x = x - 1;
                        _new_ennemie.pos_y = z;
                        _new_ennemie.e_time = 0;
                        ennemies_list.push_back(_new_ennemie);
                    }
                    if (newline[z] == 'P') {
                        _player.pos_x = x - 1;
                        _player.pos_y = z;
                        _player._pv = 5;
                    }
                    if (checkWalls(newline) == false) {
                        throw uncorrectMap();
                        std::exit(EXIT_FAILURE);
                    }
                }
            }
            config_file.push_back(newline);
        }
    }
    if (_hasEnnemies == false) {
        throw uncorrectMap();
        std::exit(EXIT_FAILURE);
    }
    return config_file;
}

bool Pacman::checkWalls(std::string newline)
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

int Pacman::getNbObject()
{
    int nb_object = 0;

    for(std::vector<int>::size_type i = 0; i != config_file.size(); i++) {
        if (config_file[i][0] == '2' && config_file[i].find("0") != std::string::npos)
            nb_object += 1;
    }
    return nb_object;
}

int Pacman::addGameInfo()
{
    size_t before_score = 0;
    size_t after_score = 0;

    // Check for left pv
    if (_player._pv == 0) {
        _player.setPv(5);
        _player.setScore(0);
        return 1;
    }

    // Check for left object on map
    if (getNbObject() == 0) {
        config_file.clear();
        config_file = readSceneFile();
    }

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
        if (config_file[i][0] == '1' && config_file[i].find("Pv :") != std::string::npos) {
            i++;
            before_score = config_file[i].find(',');
            std::string sub_before_score = config_file[i].substr(0, before_score + 1);
            after_score = config_file[i].find(',', before_score + 1);
            std::string sub_after_score = config_file[i].substr(after_score, config_file[i].size());
            config_file[i] = sub_before_score + std::to_string(_player._pv) + sub_after_score;
        }
    }
    return 0;
}

int Pacman::move_player(int x, int y)
{
    int new_player_x = _player.pos_x + x;
    int new_player_y = _player.pos_y + y;

    _player._directionY = x;
    _player._directionX = y;

    // collision with objects
    if (config_file[new_player_x][new_player_y] == '0') {
        _player.pickObject();
    }

    if (config_file[new_player_x][new_player_y] == '_') {
        _player.setInterract(true);
        _player.pickObject();
        for (size_t i = 0; i < ennemies_list.size(); i++) {
            ennemies_list[i]._vulnerable = true;
        }
    }
    if (_player._interract == true) {
        _bonus += 1;
        if (_bonus == 150) {
            _player.setInterract(false);
            _bonus = 0;
            for (size_t i = 0; i < ennemies_list.size(); i++) {
                ennemies_list[i]._vulnerable = false;
            }
        }
    }
    // collision with ennemies
    if (config_file[new_player_x][new_player_y] == 'E') {
        if (_player._interract == false) {
            _player.getDammage();
            config_file = readSceneFile();
            return 0;
        } else if (_player._interract == true) {
            // Teleport ennemies
            for (size_t i = 0; i < ennemies_list.size(); i++) {
                if (ennemies_list[i].pos_x == new_player_x && ennemies_list[i].pos_y == new_player_y) {
                    ennemies_list[i].e_time = 0;
                    config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y] = ' ';
                    ennemies_list[i].pos_x = ennemies_list[i].home_x;
                    ennemies_list[i].pos_y = ennemies_list[i].home_y;
                    config_file[ennemies_list[i].home_x][ennemies_list[i].home_y] = 'E';
                    config_file[new_player_x][new_player_y] = ennemies_list[i].old_cell;
                    ennemies_list[i].old_cell = ' ';
                }
            }
        }
    }


    // Teleport to the other side of the map
    if (config_file[new_player_x][new_player_y] == '!') {
        config_file[_player.pos_x][_player.pos_y] = ' ';
        if (_player.pos_y == 18)
            _player.pos_y = 86;
        else
            _player.pos_y = 18;
        config_file[_player.pos_x][_player.pos_y] = 'P';
        return 0;
    }

    // collision with walls
    if ((config_file[new_player_x][new_player_y] == 'E' && _player._interract == true) ||
    config_file[new_player_x][new_player_y] == '0' ||
    config_file[new_player_x][new_player_y] == ' ' || config_file[new_player_x][new_player_y] == '_') {
            config_file[_player.pos_x][_player.pos_y] = ' ';
            _player.pos_x = new_player_x;
            _player.pos_y = new_player_y;
            config_file[_player.pos_x][_player.pos_y] = 'P';
    }
    return 0;
}

void Pacman::move_ennemy(int i)
{
    if (ennemies_list[i]._direction == 1 &&
        (config_file[ennemies_list[i].pos_x - 1][ennemies_list[i].pos_y] == ' ' ||
        config_file[ennemies_list[i].pos_x - 1][ennemies_list[i].pos_y] == '0' ||
        config_file[ennemies_list[i].pos_x - 1][ennemies_list[i].pos_y] == '_' ||
        config_file[ennemies_list[i].pos_x - 1][ennemies_list[i].pos_y] == 'P')) {

        config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y] = ennemies_list[i].old_cell;
        ennemies_list[i].old_cell = config_file[ennemies_list[i].pos_x - 1][ennemies_list[i].pos_y];
        config_file[ennemies_list[i].pos_x - 1][ennemies_list[i].pos_y] = 'E';
        ennemies_list[i].pos_x -= 1;

    }
    if (ennemies_list[i]._direction == 2 &&
        (config_file[ennemies_list[i].pos_x + 1][ennemies_list[i].pos_y] == ' ' ||
        config_file[ennemies_list[i].pos_x + 1][ennemies_list[i].pos_y] == '0' ||
        config_file[ennemies_list[i].pos_x + 1][ennemies_list[i].pos_y] == '_' ||
        config_file[ennemies_list[i].pos_x + 1][ennemies_list[i].pos_y] == 'P')) {

            if (ennemies_list[i].pos_x != 14 && ennemies_list[i].pos_x != 52) {
                config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y] = ennemies_list[i].old_cell;
                ennemies_list[i].old_cell = config_file[ennemies_list[i].pos_x + 1][ennemies_list[i].pos_y];
                config_file[ennemies_list[i].pos_x + 1][ennemies_list[i].pos_y] = 'E';
                ennemies_list[i].pos_x += 1;
            }

    }
    if (ennemies_list[i]._direction == 3 &&
        (config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y - 2] == ' ' ||
        config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y - 2] == '0' ||
        config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y - 2] == '_' ||
        config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y - 2] == 'P')) {

        config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y] = ennemies_list[i].old_cell;
        ennemies_list[i].old_cell = config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y - 2];
        config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y - 2] = 'E';
        ennemies_list[i].pos_y -= 2;

    }
    if (ennemies_list[i]._direction == 4 &&
        (config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y + 2] == ' ' ||
        config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y + 2] == '0' ||
        config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y + 2] == '_' ||
        config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y + 2] == 'P')) {

        config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y] = ennemies_list[i].old_cell;
        ennemies_list[i].old_cell = config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y + 2];
        config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y + 2] = 'E';
        ennemies_list[i].pos_y += 2;
    }
}

void Pacman::ia_ennemy()
{
    for (size_t i = 0; i < ennemies_list.size(); i++) {
        if (ennemies_list[i].e_time == out_time[i]) {
            config_file[ennemies_list[i].home_x][ennemies_list[i].home_y] = ' ';
            ennemies_list[i].setPosX(14);
            ennemies_list[i].setPosY(52);
            config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y] = 'E';
            ennemies_list[i].e_time = ennemies_list[i].e_time + 1;
        } else if (ennemies_list[i].e_time > out_time[i]) {
            std::vector<int> posible;
            int nb_pos = 0;
            // Find possibilities
            if (config_file[ennemies_list[i].pos_x - 1][ennemies_list[i].pos_y] == ' ' ||
                config_file[ennemies_list[i].pos_x - 1][ennemies_list[i].pos_y] == '0' ||
                config_file[ennemies_list[i].pos_x - 1][ennemies_list[i].pos_y] == '_'  ||
                config_file[ennemies_list[i].pos_x - 1][ennemies_list[i].pos_y] == 'E' ||
                config_file[ennemies_list[i].pos_x - 1][ennemies_list[i].pos_y] == 'P') {

                    if (ennemies_list[i]._direction != 2) {
                        posible.push_back(1);
                        nb_pos += 1;
                    }
                    if (config_file[ennemies_list[i].pos_x - 1][ennemies_list[i].pos_y] == 'E')
                        ennemies_list[i]._direction = 2;
            }
            if (config_file[ennemies_list[i].pos_x + 1][ennemies_list[i].pos_y] == ' ' ||
                config_file[ennemies_list[i].pos_x + 1][ennemies_list[i].pos_y] == '0' ||
                config_file[ennemies_list[i].pos_x + 1][ennemies_list[i].pos_y] == '_' ||
                config_file[ennemies_list[i].pos_x + 1][ennemies_list[i].pos_y] == 'E' ||
                config_file[ennemies_list[i].pos_x + 1][ennemies_list[i].pos_y] == 'P') {

                    if (ennemies_list[i]._direction != 1) {
                        posible.push_back(2);
                        nb_pos += 1;
                    }
                    if (config_file[ennemies_list[i].pos_x + 1][ennemies_list[i].pos_y] == 'E')
                        ennemies_list[i]._direction = 1;
            }
            if (config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y - 2] == ' ' ||
                config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y - 2] == '0' ||
                config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y - 2] == '_' ||
                config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y - 2] == 'E' ||
                config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y - 2] == 'P') {

                    if (ennemies_list[i]._direction != 4) {
                        posible.push_back(3);
                        nb_pos += 1;
                    }
                    if (config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y - 2] == 'E')
                        ennemies_list[i]._direction = 4;
            }
            if (config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y + 2] == ' ' ||
                config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y + 2] == '0' ||
                config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y + 2] == '_'  ||
                config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y + 2] == 'E' ||
                config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y + 2] == 'P') {

                    if (ennemies_list[i]._direction != 3) {
                       posible.push_back(4);
                       nb_pos += 1;
                    }
                    if (config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y + 2] == 'E')
                        ennemies_list[i]._direction = 3;
            }
            // Compare local nb_pos and stored nb_pos
            if (nb_pos > 1) {
                // Change direction
                int v2 = std::rand() % nb_pos;

                ennemies_list[i]._direction = posible[v2];
            } else {
                ennemies_list[i]._direction = posible[0];
            }
            move_ennemy(i);

        } else {
            ennemies_list[i].e_time = ennemies_list[i].e_time + 1;
        }
    }
}

void Pacman::writeHighScore(int score, std::string name, int id)
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
    _player.setPv(5);
    _player.setScore(0);
    _player.setDirectionX(0);
    _player.setDirectionY(0);
}

extern "C" IGames *createGame(void)
{
    return new Pacman;
}
