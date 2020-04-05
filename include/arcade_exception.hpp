/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** arcade_exception
*/

#ifndef ARCADE_EXCEPTION_HPP_
#define ARCADE_EXCEPTION_HPP_

#include <exception>
#include <iostream>

class arcade_exception: public std::exception
{
    public:
    virtual const char* what() const throw()
    {
        return "An exception happenned";
    }
};

class openLibFail: public std::exception
{
    public:
    virtual const char* what() const throw()
    {
        return "Failed to open the lib";
    }
};

class getGraphicFail: public std::exception
{
    public:
    virtual const char* what() const throw()
    {
        return "Failed to get the library";
    }
};

class getGameFail: public std::exception
{
    public:
    virtual const char* what() const throw()
    {
        return "Failed to get the game";
    }
};

class dlOpenFail: public std::exception
{
    public:
    virtual const char* what() const throw()
    {
        return "Failed to dlOpen the requested library";
    }
};

class uncorrectMap: public std::exception
{
    public:
    virtual const char* what() const throw()
    {
        return "Map filled with uncorrect caracters or empty";
    }
};

#endif /* !EXCEPTION_HPP_ */
