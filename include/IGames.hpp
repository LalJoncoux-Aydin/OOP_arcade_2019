/*
** EPITECH PROJECT, 2020
** nano
** File description:
** IGAMES
*/

#ifndef IGAMES_HPP_
#define IGAMES_HPP_

#include <vector>
#include <iostream>
#include <fstream>

#include "Player.hpp"
#include "Ennemies.hpp"
#include "arcade_exception.hpp"

class IGames {
    public:
        virtual std::vector<std::string> readSceneFile() = 0;
        virtual void changeSelection(int selected) = 0;

        virtual int move_player(int x, int y) = 0;
        virtual int addGameInfo() = 0;
        virtual void ia_ennemy() = 0;

        virtual bool checkWalls(std::string newline) = 0;
        virtual void writeHighScore(int score, std::string name, int id) = 0;


        // Getters
        virtual void *getLibPtr() = 0;
        virtual int getId() = 0;
        virtual bool hasEnnemies() = 0;
        virtual std::string getConfigPath() = 0;
        virtual std::vector<std::string> getConfigFile() = 0;
        virtual Player getPlayer() = 0;
        virtual std::vector<Ennemies> getEnnemiesList() = 0;
        virtual int getPv() = 0;

        // Setters
        virtual void setLibPtr(void * new_lib) = 0;
        virtual void setConfigPath(std::string _config_path) = 0;

        virtual ~IGames() = default;
    protected:
        void *_lib_ptr;
};

#endif /* !IGAMES_HPP_ */
