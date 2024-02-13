/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** lib_sdl
*/

#ifndef SDL_HPP_
#define SDL_HPP_

#include "ILib.hpp"

class sdl : public ILib {
    public:
        sdl();
        ~sdl();
        void sdl_entry();
        void createWindow();
        void destroyWindow();
        void clearWindow();
        void display_text(std::string, bool centered, int posX, int poxY, bool selected);
        void display();
        int manage_events();
        void displayPauseMenu();
        void displayGame();
        void displaySprite(std::string path, float x, float y, bool background);
    private:
        void *handle;
        SDL_Window *_window = NULL;
        SDL_Renderer *_renderer;
        TTF_Font *_font;
        SDL_Texture *_background;
        SDL_Texture *_cursor;
        SDL_Texture *_pause;
};

extern "C"
{
    ILib *createLib()
    {
        return new sdl();
    }
    void destroy_object(sdl *object)
    {
        delete object;
    }
}

#endif /* !SDL_HPP_ */
