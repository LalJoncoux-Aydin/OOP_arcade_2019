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

class Ennemies {
    public:
        Ennemies();

        void getDamage();

        ~Ennemies();
    private:
        int pos_x;
        int pos_y;
        int pv;

};

#endif /* !ENNEMIES_HPP_ */
