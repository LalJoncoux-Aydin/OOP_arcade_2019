/*
** EPITECH PROJECT, 2020
** nano
** File description:
** MENU
*/

#ifndef MENU_HPP_
#define MENU_HPP_

// General libs
#include <iostream>
#include <vector>

// Local libs
#include "IGames.hpp"

class Menu: public IGames {
    public:
        Menu();

        virtual std::vector<std::string> readSceneFile();
        virtual void changeSelection(int selected);
        virtual bool checkWalls(__attribute__((unused))std::string newline){
            return false;
        };
        virtual int move_player(__attribute__((unused))int x, __attribute__((unused))int y) {
            return 0;
        };
        virtual int addGameInfo() {
            return 0;
        };
        virtual void writeHighScore(int score, std::string name, int id);
        virtual void ia_ennemy(){};

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
            return 0;
        };

        virtual std::vector<Ennemies>getEnnemiesList() {
            return _ennemies_list;
        };

        // Setters
        virtual void setLibPtr(void *new_lib) {
            _lib_ptr = (void *) new_lib;
        };
        virtual void setConfigPath(std::string _config_path) {
            config_path = (std::string) _config_path;
        };

        ~Menu() = default;
    private:
        std::vector<std::string> config_file;
        std::string nibbler_select = "./games/lib_arcade_menu/menu_nibbler.txt";
        std::string pacman_select = "./games/lib_arcade_menu/menu_pacman.txt";
        std::string config_path = "./games/lib_arcade_menu/menu.txt";
        int _id = 0;
        Player _player;
        std::vector<Ennemies> _ennemies_list;
        // std::string _highscore = "no highscore";
};

extern "C" IGames *createGame();

#endif /* !MENU_HPP_ */
