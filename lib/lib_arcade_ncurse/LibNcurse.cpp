#include "LibNcurse.hpp"

LibNcurse::LibNcurse()
{

}

int LibNcurse::openWindow()
{
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, _row, _col);
    return 0;
}

void LibNcurse::cleanScreen()
{

};

bool LibNcurse::displayScene(std::vector<std::string> config_scene)
{
    size_t i = 0;
    int c = 0;

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
            drawText(l_command[1], std::stoi(l_command[2]), std::stoi(l_command[3]), "", 0);
        if (l_command[0] == "2") {
            // values
            // drawMap()
        }
    }
    return true;
}

bool LibNcurse::drawText(std::string _name, int pos_x, int pos_y, __attribute__((unused))std::string _color, __attribute__((unused))int charSize)
{
    mvprintw(pos_x, pos_y, "%s", _name.c_str());
    //     // Display Menu title
    //     _row = _row - 40;
    //     _col = (_col / 2) - strlen(menu.c_str());
    //     mvprintw(_row, _col ,"%s",menu.c_str());
    //
    //     // Get player name
    //     _row += 3;
    //     _col -= 5;
    //     mvprintw(_row, _col ,"%s", getName.c_str());
    //     if (_name.empty()) {
    //         while (ch != '\n') {
    //             ch = getch();
    //             _name.push_back(ch);
    //         }
    //     }
    //
    //     // Display libs
    //     _col -= 10;
    //     _row += 3;
    //     mvprintw(_row, _col, "%s", libs.c_str());
    //
    //     // Display games
    //     _col += 7;
    //     _row += 3;
    //     mvprintw(_row, _col,"%s", games.c_str());
    //
    //     // Display Highscore
    //     _col += 6;
    //     _row += 3;
    //     mvprintw(_row, _col,"%s", highscore.c_str());
    //
    //     // Display exit
    //     _col += 2;
    //     _row += 3;
    //     mvprintw(_row, _col,"%s", exit.c_str());
    return true;
};

bool LibNcurse::drawMap() {
    return true;
};

int LibNcurse::getKey()
{
    int ch = getch();
    if (ch == KEY_F(5))
        return 5;
    if (ch == KEY_F(6))
        return 6;
    if (ch == KEY_F(12))
        return 84;
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
