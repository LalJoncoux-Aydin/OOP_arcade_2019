#include "changeLib.hpp"

IGraphic *changeLib(IGraphic *graphical_t, int key)
{
    int prev_id;

    // Find previous lib id
    if (key == 5)
        prev_id = graphical_t->getId() == 0 ? 2 : graphical_t->getId() - 1;
    else if (key == 6)
        prev_id = graphical_t->getId() == 2 ? 0 : graphical_t->getId() + 1;

    graphical_t->closeWindow();
    dlclose(graphical_t->getLibPtr());
    if ((graphical_t = initGraphic(graphical_t, (char *)libs_path[prev_id].c_str())) == NULL)
        return NULL;
    graphical_t->openWindow();
    return graphical_t;
}

//
// static IGames *changeGame(IGames *games_t, int key)
// {
//     int prev_id;
//
//     // Find previous lib id
//     if (key == 7) {
//         games_c[0]
//     }
//     else if (key == 8)
//         prev_id = graphical_t->getId() == 2 ? 0 : graphical_t->getId() + 1;
//
//     graphical_t->closeWindow();
//     if ((graphical_t = initGraphic(graphical_t, (char *)libs_path[prev_id].c_str())) == NULL)
//         return NULL;
//     graphical_t->openWindow();
//     return graphical_t;
// }
