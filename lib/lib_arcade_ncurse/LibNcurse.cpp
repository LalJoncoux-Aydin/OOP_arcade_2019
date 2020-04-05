#include "LibNcurse.hpp"

//sf::Music _music;

LibNcurse::LibNcurse()
{
    // start_color();

    // init_pair(1, COLOR_BLACK, COLOR_BLACK);
    // init_pair(2, COLOR_RED, COLOR_BLACK);
}

int LibNcurse::openWindow()
{

   /* if (!_music.openFromFile("lib/lib_arcade_opengl/assets/music.wav"))
        std::cout <<"Error: image not loading" << std::endl;

    _music.play();
    _music.setLoop(true);
    */
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, _row, _col);
    clear();
    return 0;
}

bool LibNcurse::displayScene(std::vector<std::string> config_scene, __attribute__((unused))int id, std::vector<Ennemies> ennemies_list)
{
    int x = 65;
    int y = 10;
    int nb_ennemies = 0;

    clear();
    for(size_t i = 0; i < config_scene.size(); i++) {
        std::vector<std::string> l_command;
        std::stringstream s_stream(config_scene[i]);
        while(s_stream.good()) {
            std::string param;
            getline(s_stream, param, ',');
            l_command.push_back(param);
        }
        if (l_command[0] == "1") {
            if (l_command[1] == "Player name :" && _name.length() != 0)
                drawText(_name, std::stoi(l_command[2]) + 150, std::stoi(l_command[3]), l_command[4], 0);
            if (l_command[1] == "Score :")
                drawText(_name, std::stoi(l_command[2]) + 150, std::stoi(l_command[3]), l_command[4], 0);
            if (l_command[1] == "Arcade")
                drawText(l_command[1], std::stoi(l_command[2]) + 50, std::stoi(l_command[3]), l_command[4], 0);
            else
                drawText(l_command[1], std::stoi(l_command[2]), std::stoi(l_command[3]), l_command[4], 0);
        }
        if (l_command[0] == "2") {
            for(std::string::size_type z = 1; z < l_command.size(); z++) {
                if (l_command[z] == "P") {//|| l_command[z] == "/") {
                    if (drawPlayer(x, y, id) == false)
                        return false;
                } else if (l_command[z] == "/") {
                    if (displayBody(x, y) == false)
                        return false;
                } else if(l_command[z] == "O") {
                    if (drawObject(x, y) == false)
                        return false;
                } else if(l_command[z] == "E") {
                    if (drawEnemies(x, y, nb_ennemies, ennemies_list) == false)
                        return false;
                    nb_ennemies += 1;
                } else if (l_command[z] != " " && l_command[z] != "@") {
                    if (drawMap(x, y) == false)
                        return false;
                }
                x += 2;
            }
            y += 1;
            x = 65;
        }
    }
    refresh();
    return true;
}

void LibNcurse::displayLoose()
{
    clear();
    mvprintw(25, 100, "You lost !");
    refresh();
}

bool LibNcurse::drawText(std::string _name, int pos_x, int pos_y, std::string _color, __attribute__((unused))int charSize)
{
    int id = 0;

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    refresh();
    pos_x = 237 * ((( (float) pos_x / 2000) * 100) / 100);
    pos_y = 55 * ((( (float) pos_y / 1000) * 100) / 100);
    if (_name == "Nibbler" || _name == "Pacman") {
        if (_color == "white" || _color == "pink")
            id = 1;
        if (_color == "blue")
            id = 2;
        attron(COLOR_PAIR(id));
    }
    mvprintw(pos_y, pos_x, "%s", _name.c_str());
    attron(COLOR_PAIR(1));
    refresh();
    return true;
}

bool LibNcurse::drawMap(int x, int y) {
    attron(A_NORMAL);
    mvprintw(y, x, "#");
    return true;
}

bool LibNcurse::drawPlayer(int x, int y, __attribute__((unused))int id) {
    attron(A_NORMAL);
    mvprintw(y, x, "P");
    return true;
}

bool LibNcurse::displayBody(int x, int y)
{
    attron(A_NORMAL);
    mvprintw(y, x, "o");
    return true;

}

bool LibNcurse::drawObject(int x, int y) {
    attron(A_NORMAL);
    mvprintw(y, x, "O");
    return true;
}

bool LibNcurse::drawEnemies(int x, int y, int index, std::vector<Ennemies> ennemies_list)
{
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
    refresh();
    if (index == 0)
        attron(COLOR_PAIR(2));
    if (index == 1)
        attron(COLOR_PAIR(3));
    if (index == 2)
        attron(COLOR_PAIR(4));
    if (index == 3)
        attron(COLOR_PAIR(5));
    mvprintw(y, x, "E");
    attron(COLOR_PAIR(1));
    attron(A_NORMAL);
    refresh();
    return true;
}

int LibNcurse::getKey()
{
    int ch = getch();
    switch (ch) {
    case (KEY_F(2)):
        return 2;
    case (KEY_F(3)):
        return 3;
    case (KEY_F(4)):
        return 4;
    case (KEY_F(5)):
        return 5;
    case (KEY_F(6)):
       // _music.pause();
        return 6;
    case (KEY_F(7)):
        //_music.pause();
        return 7;
    case (KEY_F(12)):
       // _music.stop();
        return 84;
    case (KEY_LEFT):
        return 12;
    case (KEY_UP):
        return 13;
    case (KEY_DOWN):
        return 14;
    case (KEY_RIGHT):
        return 15;
    case ('\n'):
        return 10;
    default:
        _name.push_back(ch);
        return 0;

    }
    return 0;
}

void LibNcurse::closeWindow()
{
    clear();
    endwin();
}

void LibNcurse::clearScreen(void)
{
    clear();
}

extern "C" IGraphic *createLib(void)
{
    return new LibNcurse;
}
