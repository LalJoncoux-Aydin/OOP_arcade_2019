#include "LibNcurse.hpp"

LibNcurse::LibNcurse()
{

}

int LibNcurse::openWindow()
{
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    return 0;
}
//
// void LibNcurse::displayMenu(std::vector<std::string> list_name)
// {
//     getmaxyx(stdscr, _row, _col);
//
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
// }

bool LibNcurse::displayScene(std::vector<std::string> config_scene)
{
    return true;
}

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
