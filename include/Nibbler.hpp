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
#include "Player.hpp"
#include "Ennemies.hpp"
#include "IGames.hpp"

class Nibbler: public IGames {
    public:
        Nibbler();

        virtual std::vector<std::string> readSceneFile();
        virtual void changeSelection(__attribute__((unused))int selected) {};
        virtual int move_player(int x, int y);
        virtual int addGameInfo();
        virtual bool checkWalls(std::string newline);
        virtual void writeHighScore(int score, std::string name, int id);
        virtual void ia_ennemy() {};
        // Getters
        virtual void *getLibPtr() {
            return _lib_ptr;
        };
        virtual int getId() {
            return _id;
        };
        virtual bool hasEnnemies() {
            return false;
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
        virtual int getPv() {
            return 1;
        };

        virtual std::vector<Ennemies> getEnnemiesList() {
            return _ennemies_list;
        };

        // Setters
        virtual void setLibPtr(void *new_lib) {
            _lib_ptr = (void *) new_lib;
        };
        virtual void setConfigPath(std::string _config_path) {
            config_path = _config_path;
        };

        ~Nibbler() = default;
    private:
        std::vector<std::string> config_file;
        std::string config_path = "./games/lib_arcade_nibbler/nibbler.txt";
        int _id = 1;
        std::vector<Ennemies> _ennemies_list;
        Player _player;
};

extern "C" IGames *createGame();

#endif /* !NIBBLER_HPP_ */
