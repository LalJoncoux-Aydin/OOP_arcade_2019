#include "arcade.hpp"
#include "arcade_exception.hpp"
#include <stdio.h>

static void getDirectionalKey(int key, IGames *game_t)
{
    if (key == 13) {
        game_t->move_player(-1, 0);
        sleep(0.6);
    }
    if (key == 14) {
        game_t->move_player(1, 0);
        sleep(0.6);
    }
    if (key == 12) {
        game_t->move_player(0, -2);
        sleep(0.6);
    }
    if (key == 15){
        game_t->move_player(0, 2);
        sleep(0.6);
    }
    if (game_t->getPlayer()._directionY == (-1)) {
        game_t->move_player(-1, 0);
        sleep(0.96);
    }
    if (game_t->getPlayer()._directionY == 1) {
        game_t->move_player(1, 0);
        sleep(0.96);
    }
    if (game_t->getPlayer()._directionX == (-2)) {
        game_t->move_player(0, -2);
        sleep(0.96);
    }
    if (game_t->getPlayer()._directionX == 2) {
        game_t->move_player(0, 2);
        sleep(0.96);
    }
}

bool arcade(char *lib_name)
{
    IGraphic *graphical_t = NULL;
    IGames *game_t = NULL;
    bool _running = true;

    if ((graphical_t = initGraphic(graphical_t, lib_name)) == NULL)
        return false;
    graphical_t->openWindow();
    if ((game_t = initGame(game_t, (char *)games_path[0].c_str())) == NULL)
        return false;
    if (graphical_t->displayScene(game_t->readSceneFile(), game_t->getId(), game_t->getEnnemiesList()) == false)
        return false;

    while (_running == true) {

        int key = graphical_t->getKey();
        // Change graphical lib
        if (key == 6 || key == 7) {
            if ((graphical_t = selectGraphical(graphical_t, key, game_t)) == NULL)
                return false;
        }
        // Select game in menu and change game lib
        if (key == 2 || key == 3 || key == 10 || key == 4) {
            if ((game_t = selectGame(game_t, key, graphical_t)) == NULL)
                return false;
        }
        // Get back to menu
        if (key == 5) {
            if ((game_t = initGame(game_t, (char *)games_path[0].c_str())) == NULL)
                return false;
            if (graphical_t->displayScene(game_t->readSceneFile(), game_t->getId(), game_t->getEnnemiesList()) == false)
                return false;
        }
        // Move ennemies
        game_t->ia_ennemy();
        // Move caracter
        getDirectionalKey(key, game_t);
        // Exit
        if (key == 84)
            _running = false;

        // Refresh map info
        if (game_t->addGameInfo() == 1) {
            game_t->writeHighScore(game_t->getPlayer()._score, graphical_t->getName(), game_t->getId());
            graphical_t->displayLoose();
            sleep(1);
            if (graphical_t->displayScene(game_t->readSceneFile(), game_t->getId(), game_t->getEnnemiesList()) == false)
                return false;
        }

        if (graphical_t->displayScene(game_t->getConfigFile(), game_t->getId(),game_t->getEnnemiesList()) == false)
            return false;
    }

    graphical_t->closeWindow();
    dlclose(graphical_t->getLibPtr());
    dlclose(game_t->getLibPtr());
    return true;
}
