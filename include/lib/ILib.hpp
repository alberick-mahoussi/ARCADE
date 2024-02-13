/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** ILib
*/

#ifndef ILIB_HPP_
#define ILIB_HPP_

#include <iostream>

class ILib
{
    public:
        virtual ~ILib(){};
        virtual int manage_events() = 0;
        virtual void createWindow() = 0;
        virtual void destroyWindow() = 0;
        virtual void clearWindow() = 0;
        virtual void display_text(std::string, bool centered, int posX, int poxY, bool selected) = 0;
        virtual void display() = 0;
        virtual void displayPauseMenu() = 0;
        virtual void displayGame() = 0;
        virtual void displaySprite(std::string path, float x, float y, bool background) = 0;
    private:
    protected:
};

#endif /* !ILIB_HPP_ */
