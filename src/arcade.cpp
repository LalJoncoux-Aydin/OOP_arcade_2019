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

        int key = graphical_t->getKey();
        // Select and change lib
        if (key == 5 || key == 6) {
            if ((graphical_t = changeLib(graphical_t, key)) == NULL)
                throw openLibFail();
            if (graphical_t->displayScene(game_t->readSceneFile()) == false)
                return false;
        }
        // Select and change game
        if (key == 1 || key == 2 || key == 10 || key == 3) {
            if (game_t->getId() == 0) {
                game_t->changeSelection(key);
            }
            if (game_t->getId() != 0 || key == 10 || key == 3) {
                int new_id = game_t->getId() == 1 ? 2 : 1;
                if ((game_t = initGame(game_t, (char *)games_path[new_id].c_str())) == NULL)
                     throw openLibFail();
                std::vector<std::string> test = game_t->getMap();
                std::cout << test[0] << std::endl;
            //    std::cout << game_t->getMap()[0] << std::endl;
            }
            if (graphical_t->displayScene(game_t->readSceneFile()) == false)
                return false;

            // displayHero()
        }
        // Write name
        if (key == 11) {
            if (graphical_t->displayScene(game_t->readSceneFile()) == false)
                return false;
        }
        // Menu
        if (key == 4) {
            if ((game_t = initGame(game_t, (char *)games_path[0].c_str())) == NULL) {
                throw openLibFail();
                return false;
            }
            if (graphical_t->displayScene(game_t->readSceneFile()) == false)
                return false;
        }

        // Move caracter

        // Exit
        if (key == 84)
            _running = false;
    }

    graphical_t->closeWindow();
    dlclose(graphical_t->getLibPtr());
    dlclose(game_t->getLibPtr());
    return true;
}
