/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** lib_ncurse
*/

#ifndef NCURSE_HPP_
#define NCURSE_HPP_

#include "ILib.hpp"
#include <memory>

class ncurse : public ILib
{
public:
    ncurse();
    ~ncurse();
    void ncurse_entry();
    void createWindow();
    void destroyWindow();
    void clearWindow();
    void display_text(std::string, bool centered, int posX, int poxY, bool selected);
    void display();
    int manage_events();
private:
    void *handle;
    int game_state;
    const char *_player;

};

extern "C"
{
    ILib *createLib()
    {
        return new ncurse();
    }
    void destroy_object(ncurse *object)
    {
        delete object;
    }
}

#endif /* !NCURSE_HPP_ */
