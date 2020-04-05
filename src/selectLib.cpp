#include "selectLib.hpp"

IGraphic *selectGraphical(IGraphic *graphical_t, int key, IGames *game_t)
{
    int prev_id;

    std::string _old_name = graphical_t->getName();
    // Find previous lib id
    if (key == 6)
        prev_id = graphical_t->getId() == 0 ? 2 : graphical_t->getId() - 1;
    else if (key == 7)
        prev_id = graphical_t->getId() == 2 ? 0 : graphical_t->getId() + 1;

    graphical_t->closeWindow();
    dlclose(graphical_t->getLibPtr());
    if ((graphical_t = initGraphic(graphical_t, (char *)libs_path[prev_id].c_str())) == NULL)
        return NULL;
    graphical_t->setName(_old_name);
    graphical_t->openWindow();
    if (graphical_t->displayScene(game_t->getConfigFile(), game_t->getId(),game_t->getEnnemiesList()) == false)
        return NULL;
    return graphical_t;
}

IGames *selectGame(IGames *game_t, int key, IGraphic *graphical_t)
{
    int new_id = game_t->getId();

    // Menu selection
    if (game_t->getId() == 0) {
        game_t->changeSelection(key);
    }
    // Change game - Launch game - Restart game
    if (game_t->getId() != 0 || key == 10 || key == 4) {
        if (game_t->getId() == 0 && key == 10 && key != 4) {
            if (game_t->getConfigPath() == "./games/lib_arcade_menu/menu_nibbler.txt")
                new_id = 1;
            else if (game_t->getConfigPath() == "./games/lib_arcade_menu/menu_pacman.txt")
                new_id = 2;
        } else if (key != 4) {
            switch(game_t->getId()) {
                case (2):
                    new_id = 1;
                    break;
                case (1):
                    new_id = 2;
                    break;
            }
        }
        if ((game_t = initGame(game_t, (char *)games_path[new_id].c_str())) == NULL) {
            throw openLibFail();
            return NULL;
        }
    }
    if (graphical_t->displayScene(game_t->readSceneFile(), game_t->getId(), game_t->getEnnemiesList()) == false)
        return NULL;
    return game_t;
}
