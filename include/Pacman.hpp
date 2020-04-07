/*
** EPITECH PROJECT, 2020
** nano
** File description:
** PACMAN
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

// General libs
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

// Local libs
#include "Player.hpp"
#include "Ennemies.hpp"
#include "IGames.hpp"

class Pacman: public IGames {
    public:

    /*enum struct Direction
    {
        NONE,
        UP,
        DOWN,
        LEFT,
        RIGHT
    };*/
        Pacman();

        virtual std::vector<std::string> readSceneFile();
        virtual void changeSelection(__attribute__((unused))int selected) {};
        virtual int move_player(int x, int y);
        virtual int addGameInfo();
        virtual bool checkWalls(std::string newline);
        int getNbObject();
        virtual void writeHighScore(int score, std::string name, int id);
        virtual void ia_ennemy();
        void move_ennemy(int i);

        // Getters
        virtual void *getLibPtr() {
            return _lib_ptr;
        };
        virtual int getId() {
            return _id;
        };
        virtual bool hasEnnemies() {
            return _hasEnnemies;
        };
        virtual std::string getConfigPath() {
            return config_path;
        };
        virtual std::vector<std::string> getConfigFile() {
            return config_file;
        };
        virtual Player getPlayer() {
            return _player;
        };
        virtual std::vector<Ennemies> getEnnemiesList() {
            return ennemies_list;
        };
        virtual int getPv() {
            return 5;
        };

        // Setters
        virtual void setLibPtr(void *new_lib) {
            _lib_ptr = (void *) new_lib;
        };
        virtual void setConfigPath(std::string _config_path) {
            config_path = _config_path;
        };

        ~Pacman() = default;
    private:
        bool _hasEnnemies = false;
        int direction = 1;
        std::vector<std::string> config_file;
        std::string config_path = "./games/lib_arcade_pacman/pacman.txt";
        int _id = 2;
        Player _player;
        Ennemies _ennemies;
       std::vector<int> ennemies_pos{0, 50, 14, 50, 14, 50, 14, 50, 14, 50, 14};
        std::vector<Ennemies> ennemies_list;
        int ennemie_out_x = 14;
        int ennemie_out_y = 50;
        std::vector<int> out_time{50, 100, 150, 200};
        int _bonus = 0;
//        std::vector<int> ennemies_home{46, 50, ,};
};

extern "C" IGames *createGame();

#endif /* !PACMAN_HPP_ */
