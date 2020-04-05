/*
** EPITECH PROJECT, 2020
** nano
** File description:
** ENNEMIES
*/

#ifndef ENNEMIES_HPP_
#define ENNEMIES_HPP_

// General libs
#include <iostream>
//#include "IGames.hpp"
//#include "Pacman.hpp"
//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
class Ennemies {
    public:
    /*enum struct Direction
    {
        NONE,
        UP,
        DOWN,
        LEFT,
        RIGHT
    };*/
   /* void changeEnemyDirection(Ennemies &ennemies);
    void initializationEnnemy(Ennemies &ennemies, const sf::Vector2f &position);
    void moveEnnemy(Ennemies &ennemies, float time);
*/


        Ennemies();

        int pos_x = 14;
        int pos_y = 52;
        int home_x;
        int home_y;
        char old_cell = ' ';
        int e_time;

       // sf::CircleShape shape;
        // Direction direction;
        void getDammage() {
            _pv = _pv - 1;
        };

        ~Ennemies();
    private:
        int _pv = 1;

};

#endif /* !ENNEMIES_HPP_ */
