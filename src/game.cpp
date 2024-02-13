/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-lise-emmanuelle.christian
** File description:
** game
*/

#include "core/core.hpp"

void Core::displayPauseMenu()
{
    _currentLib->displayPauseMenu();
    _currentLib->display_text("Resume", true, 2100, 980, (_indexMenu == 0) ? true : false);
    _currentLib->display_text("Restart", true, 2100, 1080, (_indexMenu == 1) ? true : false);
    _currentLib->display_text("Exit", true, 2100, 1180, (_indexMenu == 2) ? true : false);
    
    switch (_input) {
        case UP_ARROW: (_indexMenu-- <= 0) ? _indexMenu = 2 : _indexMenu;
            break;
        case DOWN_ARROW: (_indexMenu++ >= 2) ? _indexMenu = 0 : _indexMenu;
            break;
    }
    if (_indexMenu == 0 && _input == ENTER)
        _menu = 0;
    if (_indexMenu == 1 && _input == ENTER)
        loadGame(_games.at(_previousGameIndex));
    else if (_indexMenu == 2 && _input == ENTER)
        _menu = 1;
}

void Core::displayGame()
{
    if (_input == ESCAPE)
        _menu = -1;
    _currentLib->displayGame();
    _currentLib->displaySprite(_currentGame->displayMap(), (1920 / 4) + 200, (1080 / 4) - 50, true);
    _currentGame->gameInput(_input);
    _currentLib->display_text("Player Name: ", false, (1920 / 4) + 370, (1080 / 4) - 150, false);
    _currentLib->display_text(_playerName, false, (1920 / 4) + 550, (1080 / 4) - 150, false);
    _currentLib->display_text("Score: " + std::to_string(_currentGame->getScore()), false, (1920 / 4) + 450, (1080 / 4) - 100, false);
    _map = _currentGame->getMap();
    for (int i = 0; i < _currentGame->getLimitX(); i++)
        for (int j = 0; j < _currentGame->getLimitY(); j++, _index++)
            if (_map[_index] != "none")
                _currentLib->displaySprite(_map[_index], (1920 / 4) + 200 + (35 * j), (1080 / 4) - 50 + (40 * i), false);
    _index = 0;
    if (_menu == -1)
        displayPauseMenu();
    else {
        _currentGame->gameUpdate(_input);
        if (_currentGame->checkGameOver()) {
            _score = _currentGame->getScore();
            _menu = 1;
        } 
    }
}