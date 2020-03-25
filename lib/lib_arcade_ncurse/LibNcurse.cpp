#include "LibNcurse.hpp"

LibNcurse::LibNcurse()
{
    // start_color();

    // init_pair(1, COLOR_BLACK, COLOR_BLACK);
    // init_pair(2, COLOR_RED, COLOR_BLACK);
}

int LibNcurse::openWindow()
{
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, _row, _col);
    clear();
    return 0;
}

void LibNcurse::cleanScreen()
{

};

bool LibNcurse::displayScene(std::vector<std::string> config_scene)
{
    size_t i = 0;
    int c = 0;

    clear();
    for(; i < config_scene.size(); i++) {
        std::vector<std::string> l_command;
        std::stringstream s_stream(config_scene[i]);
        c = 0;
        while(s_stream.good() && c != 6) {
            std::string param;

            c++;
            getline(s_stream, param, ',');
            l_command.push_back(param);
        }
        if (l_command[0] == "1")
            drawText(l_command[1], std::stoi(l_command[2]), std::stoi(l_command[3]), l_command[4], 0);
        if (l_command[0] == "2") {
            // values
            // drawMap()
        }
    }
    return true;
}

bool LibNcurse::drawText(std::string _name, int pos_y, int pos_x, std::string _color, __attribute__((unused))int charSize)
{
    int id = 0;

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    refresh();
    if (pos_x > 55) {
        pos_x /= 19;
    }
    pos_y = (int)(((float) pos_y / 1500) * 100);
    if (_name == "Nibbler" || _name == "Pacman") {
        if (_color == "white" || _color == "pink")
            id = 1;
        if (_color == "blue")
            id = 2;
        attron(COLOR_PAIR(id));
    }
    mvprintw(pos_x, pos_y, "%s", _name.c_str());
    attron(COLOR_PAIR(1));
    refresh();
    return true;
};

bool LibNcurse::drawMap() {
    return true;
};

int LibNcurse::getKey()
{
    int ch = getch();
    if (ch == KEY_F(2))
        return 2;
    if (ch == KEY_F(3))
        return 3;
    if (ch == KEY_F(4))
        return 4;
    if (ch == KEY_F(5))
        return 5;
    if (ch == KEY_F(6))
        return 6;
    if (ch == KEY_F(7))
        return 7;
    if (ch == KEY_F(12))
        return 84;
    if (ch == KEY_LEFT)
        return 12;
    if (ch == KEY_UP)
        return 13;
    if (ch == KEY_DOWN)
        return 14;
    if (ch == KEY_RIGHT)
        return 15;
    //     if (_name.empty()) {
    //         while (ch != '\n') {
    //             ch = getch();
    //             _name.push_back(ch);
    //         }
    //    }
    return 0;
}

void LibNcurse::closeWindow()
{
    clear();
    endwin();
}

extern "C" IGraphic *createLib(void)
{
    return new LibNcurse;
}
