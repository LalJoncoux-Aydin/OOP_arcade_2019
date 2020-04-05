#include "initLib.hpp"

void *openLib(const char *lib_name)
{
    void *shared_lib = NULL;

    shared_lib = dlopen(lib_name, RTLD_LAZY | RTLD_GLOBAL);
    if (!shared_lib) {
        std::cerr << dlerror() << std::endl;
        return NULL;
    }
    return shared_lib;
}

IGraphic *initGraphic(IGraphic *new_graph, char *lib_name)
{
    fptr_file createLib;
    void *new_lib;

    if ((new_lib = openLib(lib_name)) == NULL)
        return NULL;
    if ((createLib = (fptr_file) dlsym(new_lib, "createLib")) == NULL) {
        throw openLibFail();
        return NULL;
    }
    new_graph = createLib();
    new_graph->setLibPtr(new_lib);
    return new_graph;
}

IGames *initGame(IGames *new_game, char *lib_name)
{
    fptr_game createGame;
    void *new_lib;

    if ((new_lib = openLib(lib_name)) == NULL)
        return NULL;
    if ((createGame = (fptr_game) dlsym(new_lib, "createGame")) == NULL) {
        throw openLibFail();
        return NULL;
    }
    new_game = createGame();
    new_game->setLibPtr(new_lib);
    return new_game;
}
