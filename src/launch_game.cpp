/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-lise-emmanuelle.christian
** File description:
** launch_game
*/

#include "core/core.hpp"

void Core::chooseGame()
{
    uint i = 0;
    for (i = 0; i != _games.size(); i++) {
        std::string tmp = _games.at(i).substr(_games.at(i).find_last_of("/\\") + 1);
        _currentLib->display_text(tmp, true, 1920, 980 + (i * 100), (_indexMenu == (int)i) ? true : false);
        if (i >= 6)
            break;
    }
    _currentLib->display_text("back", true, 1920, 980 +(i * 100), (_indexMenu == (int)i) ? true : false);
}

void Core::chooseMenu()
{
    _currentLib->display_text("Choose your game", true, 1920, 980, (_indexMenu == 0) ? true : false);
    _currentLib->display_text("Choose your library", true, 1920, 1080, (_indexMenu == 1) ? true : false);
    _currentLib->display_text("Exit", true, 1920, 1180, (_indexMenu == 2) ? true : false);
}

void Core::chooseLib()
{
    uint i = 0;
    for (i = 0; i != _libraries.size(); i++) {
        std::string tmp = _libraries.at(i).substr(_libraries.at(i).find_last_of("/\\") + 1);
        _currentLib->display_text(tmp, true, 1920, 980 + (i * 100), (_indexMenu == (int)i) ? true : false);
        if (i >= 6)
            break;
    }
    _currentLib->display_text("back", true, 1920, 980 +(i * 100), (_indexMenu == (int)i) ? true : false);
}

void Core::getMenuOptionEvent()
{
    switch (_input) {
        case EXIT: _exit = true;
            break;
        case ESCAPE: _exit = true;
            break;
        case UP_ARROW: (_indexMenu-- <= 0) ? _indexMenu = 2 : _indexMenu;
            break;
        case DOWN_ARROW: (_indexMenu++ >= 2) ? _indexMenu = 0 : _indexMenu;
            break;
    }
    if (_indexMenu == 2 && _input == ENTER)
    _exit = true;
    if (_indexMenu == 0 && _input == ENTER)
        _menu = 2;
    else if (_indexMenu == 1 && _input == ENTER)
        _menu = 3;
    if (_input >= A_KEY && _input <= Z_KEY
    && _playerName.length() < 18)
        _playerName += static_cast<char>(_input + 55);
    if (_input == BACKSPACE && !_playerName.empty())
        _playerName = _playerName.substr(0, _playerName.size() - 1);
    if (_input == SPACE)
        _playerName.clear();
}

void Core::getSubMenuOptEvent(int max, std::string parameter)
{
    switch (_input) {
        case UP_ARROW: (_indexMenu-- <= 0) ? _indexMenu = max : _indexMenu;
            break;
        case DOWN_ARROW: (_indexMenu++ >= max) ? _indexMenu = 0 : _indexMenu;
            break;
    }
    
    if (_indexMenu == max && _input == ENTER)
        _menu = 1;
    else if (_input == ENTER && parameter == "library") {
        _currentLib->destroyWindow();
        _menu = 1;
        loadLib(_libraries.at(_indexMenu));
        _indexMenu = 0;
    }
    else if (_input == ENTER && parameter == "game") {
        std::cout << "Launch game" << std::endl;
        _menu = 0;
        loadGame(_games.at(_indexMenu));
        _previousGameIndex = _indexMenu;
        _indexMenu = 0;
    }
}

void Core::displayMenu()
{
    if (_menu == 2) {
        getSubMenuOptEvent(_games.size(), "game");
        chooseGame();
    } else if (_menu == 3) {
        getSubMenuOptEvent(_libraries.size(), "library");
        chooseLib();
    } else {
        getMenuOptionEvent();
        chooseMenu();
    }
    _currentLib->display_text("Player Name: ", false, 200, 100, false);
    _currentLib->display_text(_playerName, false, 380, 100, false);
    _currentLib->display_text("Score: " + std::to_string(_score), false, 200, 150, false);
}

void Core::getKeyEvent()
{
    switch (_input)
    {
    case F1_KEY: _exit = true;
        break;
    case F2_KEY: _menu = 1;
        break;
    case F3_KEY: if (_games.size() > 0) {loadGame(_games.at(_previousGameIndex));};
        break;
    case F4_KEY: _menu = 1; _currentLib->destroyWindow(); (_numberOfLib++ < (int)_libraries.size() - 1) ? loadLib(_libraries.at(_numberOfLib)) : loadLib(_libraries.at(_numberOfLib = 0));
        break;
    case F5_KEY: _menu = 1; _currentLib->destroyWindow(); (_numberOfLib-- > 0) ? loadLib(_libraries.at(_numberOfLib)) : loadLib(_libraries.at(_numberOfLib = (_libraries.size() - 1)));
        break;
    case F6_KEY: (_previousGameIndex++ < (int)_games.size() - 1) ? loadGame(_games.at(_previousGameIndex)) : loadGame(_games.at(_previousGameIndex = 0));
        break;
    case F7_KEY: (_previousGameIndex-- > 0) ? loadGame(_games.at(_previousGameIndex)) : loadGame(_games.at(_previousGameIndex =  (_games.size() - 1)));
        break;
    }
}

void Core::launch_game()
{
    _currentLib->createWindow();
    while (_exit != true) {
        _input = _currentLib->manage_events();
        getKeyEvent();
        if (_input == EXIT)
            _exit = true;
        if (_menu > 0) {
            _currentLib->clearWindow();
            displayMenu();
        }
        if (_menu <= 0)
            displayGame();
        _currentLib->display();
    }
    _currentLib->destroyWindow();
}