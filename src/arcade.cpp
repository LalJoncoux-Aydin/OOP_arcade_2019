#include "arcade.hpp"
#include "arcade_exception.hpp"

bool arcade(char *lib_name)
{
    IGraphic *graphical_t = NULL;
    IGames *game_t = NULL;
    bool _running = true;

    if ((graphical_t = initGraphic(graphical_t, lib_name)) == NULL) {
        throw openLibFail();
        return false;
    }
    graphical_t->openWindow();
    if ((game_t = initGame(game_t, (char *)games_path[0].c_str())) == NULL) {
        throw openLibFail();
        return false;
    }
    if (graphical_t->displayScene(game_t->readSceneFile()) == false)
        return false;

    while (_running == true) {
        int new_id = 0;
        int key = graphical_t->getKey();
        // Select and change lib
        if (key == 6 || key == 7)
            if ((graphical_t = changeLib(graphical_t, key)) == NULL)
                return false;
        // Select and change game / restart game
        if (key == 2 || key == 3 || key == 10 || key == 4) {
            if (game_t->getId() == 0)
                game_t->changeSelection(key);
            if (game_t->getId() == 0 && key == 10) {
                new_id = game_t->getSelected() == 1 ? 2 : 1;
                if ((game_t = initGame(game_t, (char *)games_path[new_id].c_str())) == NULL)
                    return false;
            }
            if (game_t->getId() != 0 || key == 4) {
                new_id = game_t->getId() == 1 ? 2 : 1;
                if ((game_t = initGame(game_t, (char *)games_path[new_id].c_str())) == NULL)
                    return false;
            }
        }
        // Menu
        if (key == 4)
            if ((game_t = initGame(game_t, (char *)games_path[0].c_str())) == NULL)
                return false;

        // Move caracter

        // Exit
        if (key == 84)
            _running = false;

        if (graphical_t->displayScene(game_t->readSceneFile()) == false)
            return false;
    }

    graphical_t->closeWindow();
    dlclose(graphical_t->getLibPtr());
    dlclose(game_t->getLibPtr());
    return true;
}
