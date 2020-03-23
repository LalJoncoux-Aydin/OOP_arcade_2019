/*
** EPITECH PROJECT, 2020
** nano
** File description:
** PLAYER
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

// General libs
#include <iostream>

class Player {
    public:
        Player();

        void pickObject();
        void getDamage();

        ~Player();
    private:
        int pos_x;
        int pos_y;
        bool win;
        int score;
        int pv;
        int nb_object;

};

#endif /* !PLAYER_HPP_ */
