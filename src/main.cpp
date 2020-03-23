#include "arcade.hpp"

int main(int ac, char **argv)
{
    if (ac != 2) {
        std::cerr << "type -h for help" << std::endl;
        return 84;
    }
    if (strcmp(argv[1], "-h") == 0) {
        std::cout << "How to use the arcade :\n ./arcade ./the_library_you_want -> ex:./arcade lib_arcade_opengl.so" << std::endl;
        return 0;
    }
    try
    {
        arcade(argv[1]);
    } catch (arcade_exception& e)
    {
        std::cout << e.what() << '\n';
        return 84;
    }
    return 0;
}
