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

        Ennemies() {};

        int pos_x;
        int pos_y;
        int home_x;
        int home_y;
        char old_cell = ' ';
        int e_time;
        int _direction;
        bool _vulnerable = false;

        void getDammage() {
            _pv = _pv - 1;
        };

        // Setters
        void setPosX(int posx) {
            pos_x = posx;
        }
        void setPosY(int posy) {
            pos_y = posy;
        }

        ~Ennemies() {};
    private:
        int _pv = 1;

};

#endif /* !ENNEMIES_HPP_ */
