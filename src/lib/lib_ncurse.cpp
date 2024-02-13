/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** ncurse
*/

#include "../../include/lib/lib_ncurse.hpp"
#include "../../include/lib/ILib.hpp"
#include <ncurses.h>

ncurse::ncurse()
{
}

ncurse::~ncurse()
{
}

void ncurse::createWindow()
{
    initscr();
    noecho();
    keypad(stdscr, true);
	printw("Press F1 to exit");
}

int ncurse::manage_events()
{
    int key = getch();

    switch (key)
    {
    case KEY_LEFT:
        return 2;
    case KEY_RIGHT:
        return 3;
    case KEY_UP:
        return 4;
    case KEY_DOWN:
        return 5;
    case 27:
        endwin();
        return 0;
    case 32:
        return 7;
    case 10:
        return 8;
    case KEY_BACKSPACE:
        return 9;
    case 97:
        return 10;
    case 98:
        return 11;
    case 99:
        return 12;
    case 100:
        return 13;
    case 101:
        return 14;
    case 102:
        return 15;
    case 103:
        return 16;
    case 104:
        return 17;
    case 105:
        return 18;
    case 106:
        return 19;
    case 107:
        return 20;
    case 108:
        return 21;
    case 109:
        return 22;
    case 110:
        return 23;
    case 111:
        return 24;
    case 112:
        return 25;
    case 113:
        return 26;
    case 114:
        return 27;
    case 115:
        return 28;
    case 116:
        return 29;
    case 117:
        return 30;
    case 118:
        return 31;
    case 119:
        return 32;
    case 120:
        return 33;
    case 121:
        return 34;
    case 122:
        return 35;
    }
    return (-1);
}

void ncurse::display()
{
    clear();
    if (this->game_state == 0)
    {
        mvprintw(0, 0, _player);
        mvprintw(LINES / 2.2, COLS / 1.2, "CHOOSE YOUR GAME !");
        mvprintw(LINES / 2.2, COLS / 1.8, "CHOOSE YOUR LIB !");
        mvprintw(LINES / 1.1, COLS / 2.2, "ESCAPE TO EXIT");
    }
    refresh();
}

void ncurse::display_text(std::string, bool centered, int posX, int poxY, bool selected)
{
    clear();
    mvprintw(LINES / 2.2, COLS / 2.2, _player);
    refresh();
}

void ncurse::destroyWindow()
{
    refresh();
    endwin();
}

void ncurse::clearWindow()
{

}