/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** sdl
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "../../include/lib/lib_sdl.hpp"

sdl::sdl()
{
}

sdl::~sdl()
{
}

void sdl::createWindow()
{
    SDL_Init(SDL_INIT_VIDEO);
    _window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_OPENGL);
    if (_window == NULL)
        std::cerr << "SDL window failed to open" << std::endl;
    TTF_Init();
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);	
	_font = TTF_OpenFont("sprites/font.ttf", 100);
	_background = IMG_LoadTexture(_renderer, "sprites/arcade_menu.png");
    _cursor = IMG_LoadTexture(_renderer, "sprites/cursor.png");
    _pause = IMG_LoadTexture(_renderer, "sprites/pause.png");
    SDL_SetTextureBlendMode(_pause, SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(_pause, 128);
}

void sdl::sdl_entry()
{
}

void sdl::display()
{
    SDL_RenderPresent(_renderer);
}

int sdl::manage_events()
{
    SDL_Event event;

    if (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT)
            return (0);
        else if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
                case SDLK_LEFT :
                    return 2;
                case SDLK_RIGHT :
                    return 3;
                case SDLK_UP :
                    return 4;
                case SDLK_DOWN :
                    return 5;
                case SDLK_ESCAPE :
                    return 6;
                case SDLK_SPACE :
                    return 7;
                case SDLK_RETURN :
                    return 8;
                case SDLK_BACKSPACE :
                    return 9;
                case SDLK_a :
                    return 10;
                case SDLK_b :
                    return 11;
                case SDLK_c :
                    return 12;
                case SDLK_d :
                    return 13;
                case SDLK_e :
                    return 14;
                case SDLK_f :
                    return 15;
                case SDLK_g :
                    return 16;
                case SDLK_h :
                    return 17;
                case SDLK_i :
                    return 18;
                case SDLK_j :
                    return 19;
                case SDLK_k :
                    return 20;
                case SDLK_l :
                    return 21;
                case SDLK_m :
                    return 22;
                case SDLK_n :
                    return 23;
                case SDLK_o :
                    return 24;
                case SDLK_p :
                    return 25;
                case SDLK_q :
                    return 26;
                case SDLK_r :
                    return 27;
                case SDLK_s :
                    return 28;
                case SDLK_t :
                    return 29;
                case SDLK_u :
                    return 30;
                case SDLK_v :
                    return 31;
                case SDLK_w :
                    return 32;
                case SDLK_x :
                    return 33;
                case SDLK_y :
                    return 34;
                case SDLK_z :
                    return 35;
                case SDLK_F1 :
                    return 36;
                case SDLK_F2 :
                    return 37;
                case SDLK_F3 :
                    return 38;
                case SDLK_F4 :
                    return 39;
                case SDLK_F5 :
                    return 40;
                case SDLK_F6 :
                    return 41;
                case SDLK_F7 :
                    return 42;
            }
        }
    }
    return (-1);
}


void sdl::destroyWindow()
{
    SDL_DestroyTexture(_cursor);
    _cursor = nullptr;
    SDL_DestroyTexture(_background);
	_background = nullptr;
	SDL_DestroyRenderer(_renderer);
	_renderer = nullptr;
	SDL_DestroyWindow(_window);
	_window = nullptr;
	TTF_CloseFont(_font);
	_font = nullptr;
	TTF_Quit();
	SDL_Quit();
}

void sdl::displaySprite(std::string path, float x, float y, bool background)
{
    SDL_Texture *texture = IMG_LoadTexture(_renderer, path.c_str());
    SDL_Rect fullScreen;
    if (background) {
        fullScreen.h = 600;
        fullScreen.w = 600;
        fullScreen.x = x;
        fullScreen.y = y;
    } else {
        fullScreen.h = 40;
        fullScreen.w = 35;
        fullScreen.x = x;
        fullScreen.y = y;
    }
    SDL_RenderCopy(_renderer, texture, NULL, &fullScreen);
    SDL_DestroyTexture(texture);
}

void sdl::displayGame()
{
	SDL_RenderClear(_renderer);
    
}

void sdl::clearWindow()
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	SDL_RenderClear(_renderer);
    SDL_Rect fullScreen;
	fullScreen.h = 1080;
	fullScreen.w = 1920;
	fullScreen.x = 0;
	fullScreen.y = 0;
    SDL_RenderCopy(_renderer, _background, NULL, &fullScreen);
}

void sdl::displayPauseMenu()
{
    SDL_Rect fullScreen;
	fullScreen.h = 1080;
	fullScreen.w = 1920;
	fullScreen.x = 0;
	fullScreen.y = 0;
    SDL_RenderCopy(_renderer, _pause, NULL, &fullScreen);
}

void sdl::display_text(std::string message, bool centered, int posX, int poxY, bool selected)
{
    SDL_Color white = {255, 255, 255, 255};
	SDL_Surface *surfaceText = TTF_RenderText_Blended(_font, message.c_str(), white);
	SDL_Texture *text = SDL_CreateTextureFromSurface(_renderer, surfaceText);
    SDL_Rect rect;
    if (centered == true) {
        rect.x = posX / 2 - 120;
        rect.y = poxY / 2 - 70;
        rect.w = message.length() * 14;
        rect.h = 32;
    }else {
        rect.x = posX + 25;
        rect.y = poxY;
        rect.w = message.length() * 14;
        rect.h = 32;
    }
    if (selected == true) {
        SDL_Rect cursor;
        cursor.h = 26;
        cursor.w = 26;
        cursor.x = posX / 2 - 165;
        cursor.y = poxY / 2 - 70;
        SDL_RenderCopy(_renderer, _cursor, NULL, &cursor);
    }
	SDL_RenderCopy(_renderer, text, NULL, &rect);
	SDL_DestroyTexture(text);
	SDL_FreeSurface(surfaceText);
}