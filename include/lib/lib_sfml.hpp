/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** lib_sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "ILib.hpp"

class sfml : public ILib
{
public:
    sfml();
    ~sfml();
    void sfml_entry();
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
    sf::RenderWindow _window;
    sf::Texture _backgroundT;
    sf::Sprite _backgroundS;
    sf::Texture _cursorT;
    sf::Sprite _cursorS;
    sf::Texture _pauseT;
    sf::Sprite _pauseS;
    sf::Font _font;
};

extern "C"
{
    ILib *createLib()
    {
        return new sfml();
    }
    void destroy_object(sfml *object)
    {
        delete object;
    }
}

#endif /* !SFML_HPP_ */
