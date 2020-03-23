/*
** EPITECH PROJECT, 2020
** nano
** File description:
** NIBBLER
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

// General libs
#include <iostream>

// Local libs
#include "IGames.hpp"

class Nibbler: public IGames {
    public:
        Nibbler();

        virtual void *getLibPtr() {
            return _lib_ptr;
        };
        virtual void setLibPtr(void *new_lib) {
            _lib_ptr = (void *) new_lib;
        };
        virtual int getId() {
            return _id;
        };
        virtual std::vector<std::string> getListName() {
            return list_name;
        };
        virtual std::vector<std::string> readSceneFile();

        virtual int startGame();

        ~Nibbler() = default;
    private:
        void *_lib_ptr;
        int _id = 2;
        std::string config_path = "./games/lib_arcade_nibbler/.nibbler";

        std::vector<std::string> list_name;
};

extern "C" IGames *createGame();

#endif /* !NIBBLER_HPP_ */
