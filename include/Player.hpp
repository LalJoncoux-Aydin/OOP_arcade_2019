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
        Player() {};

        int pos_x;
        int pos_y;
        int _directionX = 0;
        int _directionY = 0;
        int _score = 0;
        int _pv;
        bool _interract = false;

        void getDammage() {
            _pv = _pv - 1;
        };

        // Setters
        void pickObject() {
            _score = _score + 1;
        }
        void setPosX(int x) {
            pos_x = x;
        }
        void setPosY(int y) {
            pos_y = y;
        }
        void setInterract(bool value) {
            _interract = value;
        }
        void setPv(int pv) {
            _pv = pv;
        }
        void setScore(int score) {
            _score = score;
        }
        void setDirectionX(int directionX) {
            _directionX = directionX;
        }
        void setDirectionY(int directionY) {
            _directionY = directionY;
        }

        ~Player() {};

};

#endif /* !PLAYER_HPP_ */
