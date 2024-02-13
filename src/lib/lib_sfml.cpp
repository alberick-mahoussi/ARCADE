/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** sfml
*/


#include "../../include/lib/lib_sfml.hpp"

sfml::sfml()
{
}

sfml::~sfml()
{
}

void sfml::createWindow()
{
    _font.loadFromFile("sprites/font.ttf");
    _window.create(sf::VideoMode(1920, 1080), "SFML works!", sf::Style::Resize | sf::Style::Close);
    _backgroundT.loadFromFile("sprites/arcade_menu.png");
    _backgroundS.setTexture(_backgroundT);
    sf::Vector2u windowSize = _window.getSize();
    _backgroundS.setScale(windowSize.x / _backgroundS.getLocalBounds().width, 
                          windowSize.y / _backgroundS.getLocalBounds().height);
    _cursorT.loadFromFile("sprites/cursor.png");
    _cursorS.setTexture(_cursorT);
    _pauseT.loadFromFile("sprites/pause.png");
    _pauseS.setTexture(_pauseT);
    _pauseS.setScale(4, 3);
}


void sfml::destroyWindow()
{
    _window.close();
}

int sfml::manage_events()
{
    sf::Event event;
    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            _window.close();
            return (0);
        }
        if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Left:
                return 2;
            case sf::Keyboard::Right:
                return 3;
            case sf::Keyboard::Up:
                return 4;
            case sf::Keyboard::Down:
                return 5;
            case sf::Keyboard::Escape:
                return 6;
            case sf::Keyboard::Space:
                return 7;
            case sf::Keyboard::Return:
                return 8;
            case sf::Keyboard::BackSpace:
                return 9;
            case sf::Keyboard::A:
                return 10;
            case sf::Keyboard::B:
                return 11;
            case sf::Keyboard::C:
                return 12;
            case sf::Keyboard::D:
                return 13;
            case sf::Keyboard::E:
                return 14;
            case sf::Keyboard::F:
                return 15;
            case sf::Keyboard::G:
                return 16;
            case sf::Keyboard::H:
                return 17;
            case sf::Keyboard::I:
                return 18;
            case sf::Keyboard::J:
                return 19;
            case sf::Keyboard::K:
                return 20;
            case sf::Keyboard::L:
                return 21;
            case sf::Keyboard::M:
                return 22;
            case sf::Keyboard::N:
                return 23;
            case sf::Keyboard::O:
                return 24;
            case sf::Keyboard::P:
                return 25;
            case sf::Keyboard::Q:
                return 26;
            case sf::Keyboard::R:
                return 27;
            case sf::Keyboard::S:
                return 28;
            case sf::Keyboard::T:
                return 29;
            case sf::Keyboard::U:
                return 30;
            case sf::Keyboard::V:
                return 31;
            case sf::Keyboard::W:
                return 32;
            case sf::Keyboard::X:
                return 33;
            case sf::Keyboard::Y:
                return 34;
            case sf::Keyboard::Z:
                return 35;
            case sf::Keyboard::F1 :
                return 36;
            case sf::Keyboard::F2 :
                return 37;
            case sf::Keyboard::F3 :
                return 38;
            case sf::Keyboard::F4 :
                return 39;
            case sf::Keyboard::F5 :
                return 40;
            case sf::Keyboard::F6 :
                return 41;
            case sf::Keyboard::F7 :
                return 42;
            }
        }
    }
    return (-1);
}

void sfml::displaySprite(std::string path, float x, float y, bool background)
{
    sf::Texture texture;
    texture.loadFromFile(path);
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    _window.draw(sprite);
}


void sfml::displayGame()
{
    _window.clear();
}

void sfml::displayPauseMenu()
{
    _pauseS.setColor(sf::Color(180, 180, 180, 128)); 
    _window.draw(_pauseS);
}

void sfml::clearWindow()
{
    _window.clear();
    _window.draw(_backgroundS);
}

void sfml::display()
{
    _window.display();
}

void sfml::display_text(std::string message, bool centered, int posX, int posY, bool selected)
{
    sf::Text msgDisplayed(message, _font);
    if (centered == true) {
        msgDisplayed.setPosition((posX/2.0f) - 140, (posY/2.0f) - 80);
    } else {
        msgDisplayed.setPosition(posX, posY);
    }
    msgDisplayed.setCharacterSize(35);
    msgDisplayed.setFillColor(sf::Color::White);
    _window.draw(msgDisplayed);
    if (selected == true) {
        _cursorS.setPosition((posX/2.0f) -165, (posY/2.0f) -70);
        _window.draw(_cursorS);
    }
}