/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-lise-emmanuelle.christian
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include <vector>
#include <memory>

class IGame {
    public:
        virtual ~IGame() {};
        virtual void gameUpdate(int input) = 0;
        virtual std::string displayMap() = 0;
        virtual std::vector<std::string> getMap() = 0;
        virtual int getLimitX() = 0;
        virtual int getLimitY() = 0;
        virtual void gameInput(int input) = 0;
        virtual bool checkGameOver() = 0;
        virtual int getScore() = 0;
    protected:
    private:
};

#endif /* !IGAME_HPP_ */
