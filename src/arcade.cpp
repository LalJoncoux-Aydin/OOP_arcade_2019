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
        // Change lib
        if (key == 5 || key == 6) {
            if ((graphical_t = changeLib(graphical_t, key)) == NULL)
                throw openLibFail();
            if (graphical_t->displayScene(game_t->readSceneFile()) == false)
                return false;
        }
        // Exit
        if (key == 84)
            _running = false;
        // Select game
        // if (key == 1) {
        //     graphical_t->changeColor(1);
            // if (graphical_t->displayScene(game_t->readSceneFile()) == false)
            //     return false;
        // }
        // if (key == 2) {
        //      graphical_t->changeColor(2);
            // if (graphical_t->displayScene(game_t->readSceneFile()) == false)
            //     return false;
        // }
        // // init game or restart
        // if (key == 10 || key == 3) {
        //   if (graphical_t->getState() == 1 || graphical_t->getState() == 2) {
        //         // Clear the window
        //
        //         if ((game_t = initGame(game_t, (char *)games_path[graphical_t->getState()].c_str())) == NULL)
        //           throw openLibFail();
        //
        //         // Display map
        //   }
        // }
        // Menu
        // if (key == 4) {
        //      if ((game_t = initGame(game_t, (char *)games_path[0].c_str())) == NULL) {
        //           throw openLibFail();
        //           return false;
        //      }
        //      if (graphical_t->displayScene(game_t->readSceneFile()) == false)
        //           return false;
        // }

        // Change game
        // if (key == 7 || key == 8)
        //

        // Move caracter
    }

    graphical_t->closeWindow();
    dlclose(graphical_t->getLibPtr());
    return true;
}
