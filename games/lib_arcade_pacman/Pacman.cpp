#include "Pacman.hpp"

Pacman::Pacman()
{
}
//
// if (ennemi == 1) {
//     config_file[16][46] = ' ';
//     config_file[14][46] = 'E';
//     //ennemies_list[0] = Ennemies(16, 46);
// }
// if (ennemi == 2) {
//     config_file[16][50] = ' ';
//     config_file[14][50] = 'E';
// }
// if (ennemi == 3) {
//     config_file[16][54] = ' ';
//     config_file[14][54] = 'E';
// }
// if (ennemi == 4) {
//     config_file[16][58] = ' ';
//     config_file[14][58] = 'E';
// }

std::vector<std::string> Pacman::readSceneFile()
{
    std::string newline;
    std::ifstream stream_name(config_path);
    int x = 0;

    if (stream_name) {
        while (std::getline(stream_name, newline)) {
            x++;
            if (newline[0] == '2') {
                for(std::string::size_type z = 0; z < newline.size(); z++) {
                    if (newline[z] == 'E') {
                        _hasEnnemies = true;
                        Ennemies _new_ennemie;
                        _new_ennemie.home_x = x - 1;
                        _new_ennemie.home_y = z;
                        ennemies_list.push_back(_new_ennemie);
                    }
                    if (newline[z] == 'P') {
                        _player.pos_x = x - 1;
                        _player.pos_y = z;
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
        config_file.clear();
        config_file = readSceneFile();
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

    // collision with big objects for 10 sec
    // if (config_file[new_player_x][new_player_y] == '%') {
    //     _player.setInterract(true);
    // }
    // if (_player._interract == true)
    //     _bonus += 1;
    // if (_bonus == "1000")
    //     _player.setInterract(false);

    // collision with ennemies
    if (config_file[new_player_x][new_player_y] == 'E') {
        if (_player._interract == false) {
            _player.getDammage();
            config_file.clear();
            config_file = readSceneFile();
            return 0;
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
    config_file[new_player_x][new_player_y] == ' ') {
            config_file[_player.pos_x][_player.pos_y] = ' ';
            _player.pos_x = new_player_x;
            _player.pos_y = new_player_y;
            config_file[_player.pos_x][_player.pos_y] = 'P';
    }
    return 0;
}

void Pacman::ia_ennemy()
{
    std::vector<int> posible{0, 0, 0, 0};
    int v2 = rand() % 3;

    for (size_t i = 0; i < ennemies_list.size(); i++) {
        if (ennemies_list[i].e_time == out_time[i]) {
            config_file[ennemies_list[i].home_x][ennemies_list[i].home_y] = ' ';
            config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y] = 'E';
            ennemies_list[i].e_time = ennemies_list[i].e_time + 1;
        } else if (ennemies_list[i].e_time > out_time[i]) {
            // ennemie move - Partie de zoé
            if (config_file[ennemies_list[i].pos_x][(ennemies_list[i].pos_y) - 2] ==' ' ||
                config_file[ennemies_list[i].pos_x][(ennemies_list[i].pos_y) - 2] =='P'
                || config_file[ennemies_list[i].pos_x][(ennemies_list[i].pos_y) - 2] == '0') {
                    posible[0] = 1;
            }
            if (config_file[ennemies_list[i].pos_x][(ennemies_list[i].pos_y) + 2] ==' ' ||
                config_file[ennemies_list[i].pos_x][(ennemies_list[i].pos_y) + 2] =='P'
                || config_file[ennemies_list[i].pos_x][(ennemies_list[i].pos_y) + 2] == '0') {
                    posible[1] = 1;
            }
            if (config_file[(ennemies_list[i].pos_x) + 1][ennemies_list[i].pos_y] ==' '
                || config_file[(ennemies_list[i].pos_x) + 1][ennemies_list[i].pos_y] =='P'
                || config_file[(ennemies_list[i].pos_x) + 1][ennemies_list[i].pos_y] == '0') {
                    posible[2] = 1;
            }
            if (config_file[(ennemies_list[i].pos_x) - 1][ennemies_list[i].pos_y] ==' '
                || config_file[(ennemies_list[i].pos_x) - 1][ennemies_list[i].pos_y] =='P'
                || config_file[(ennemies_list[i].pos_x) - 1][ennemies_list[i].pos_y] == '0') {
                    posible[3] = 1;
            }

            while (posible[v2] != 1)
                v2 = rand() % 4;
            if (v2 == 0) {
                move_ennemy(0, -2, i);
            }
            else if (v2 == 1) {
                move_ennemy(0, 2, i);
            }
            else if (v2 == 2) {
                move_ennemy(1, 0, i);
            }
            else if (v2 == 3) {
                move_ennemy(-1, 0, i);
            }
        } else {
            ennemies_list[i].e_time = ennemies_list[i].e_time + 1;
        }
    }
}

void Pacman::move_ennemy(int x, int y, size_t i)
{
    int new_player_x = ennemies_list[i].pos_x + x;
    int new_player_y = ennemies_list[i].pos_y + y;
    //std::cout << "yeah" << std::endl;
    //std::cout << ennemies_list[i].old_cell << std::endl;
    config_file[ennemies_list[i].pos_x][ennemies_list[i].pos_y] = ennemies_list[i].old_cell;
    config_file[new_player_x][new_player_y] = 'E';
    ennemies_list[i].pos_x += x;
    ennemies_list[i].pos_y += y;
    /*std::cout << "move : " << std::endl;
    std::cout <<     config_file[new_player.pos_x][new_player.pos_y] << std::endl;
    std::cout << "move" << std::endl;
    std::cout << config_file[ennemies_pos[ennemi * 2]][ennemies_pos[ennemi * 2 - 1]] << std::endl;*/
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
}

extern "C" IGames *createGame(void)
{
    return new Pacman;
}
