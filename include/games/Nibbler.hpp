/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-lise-emmanuelle.christian
** File description:
** snake
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "IGame.hpp"
#include <iostream>

class Nibbler: public IGame {
    private:
        int _score;
        bool _isGameOver;
        int _direction;
        double _speed;
        int _index = 21;
        std::vector<std::string> _map;
        std::vector<std::string> _mapNibbler;
        std::vector<int> _NibblerPos;
    public:
        Nibbler();
        ~Nibbler(){};
        void gameUpdate(int input);
        void map_generator();
        void moveSnake();
        std::string displayMap();
        std::vector<std::string>  getMap();
        int getLimitX() {
            return 16;
        };
        int getLimitY() {
            return 18;
        };

        void snakeUp();
        void snakeDown();
        void snakeLeft();
        void snakeRight();
        void gameInput(int input);
        void gameIsOver();
        bool checkGameOver();
        int getScore();
};

enum Direction {
    LEFT_DIRECTION = 1,
    RIGHT_DIRECTION = 2,
	UP_DIRECTION = 3,
	DOWN_DIRECTION = 4,
};

extern "C"
{
    IGame *createGame()
    {
        return new Nibbler();
    }
    void destroy_object(Nibbler *object)
    {
        delete object;
    }
}
#endif/* !/* !SNAKE_HPP_ */