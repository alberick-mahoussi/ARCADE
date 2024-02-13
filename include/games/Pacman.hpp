/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-alberick.mahoussi
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
    #define PACMAN_HPP_
    #include "IGame.hpp"
    #include <iostream>
    #include <fstream>

class Pacman: public IGame {
    public:
        Pacman();
        ~Pacman();
        void gameUpdate(int input);
        void map_generator();
        void moveSnake();
        std::string displayMap();
        std::vector<std::string>  getMap();
        int getLimitX() {
            return 17;
        };
        int getLimitY() {
            return 28;
        };

        void gameInput(int input);
        void gameIsOver();
        bool checkGameOver();
        int getScore();
        void PacmanUp();
        void PacmanDown();
        void PacmanLeft();
        void PacmanRight();
        std::vector<std::vector<char>> genmap(std::string file);
        void reset();


    private:
        int life;
        int _score;
        bool _isGameOver;
        int _direction;
        double _speed;
        int _index = 20;
        std::vector<std::string> _map;
        std::vector<std::string> _mapPacman;
        std::vector<int> _pacmanPos;
        std::vector<std::vector<int>> ghost_pos;
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
        return new Pacman();
    }
    void destroy_object(Pacman *object)
    {
        delete object;
    }
}
#endif /* !PACMAN_HPP_ */

