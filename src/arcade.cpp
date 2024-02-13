/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-Core-lise-emmanuelle.christian
** File description:
** Core
*/

#include <stdlib.h>
#include <fstream>
#include <dirent.h>
#include "core/core.hpp"
#include "lib/ILib.hpp"
#include "games/IGame.hpp"

void Core::loadLib(std::string libName)
{
    if (_handle) {
        _currentLib.reset(nullptr);
        _library->closeLibrary(_handle);
        _handle = nullptr;
		_lib_entry = nullptr;
    }
    void *lib = _library->loadLibrary("./lib/" + libName);
    _handle = lib;
    _lib_entry = ((ILib *(*) (void)) _library->getFunction(lib, "createLib"));
    _currentLib = std::unique_ptr<ILib> (_lib_entry());
    _currentLib->createWindow();
}

void Core::loadGame(std::string libName)
{
    if (_handleGame) {
        _currentGame.reset(nullptr);
        _library->closeLibrary(_handleGame);
        _handleGame = nullptr;
		_game_entry = nullptr;
    }
    void *lib = _library->loadLibrary("./games/" + libName);
    _handleGame = lib;
    _game_entry = ((IGame *(*) (void)) _library->getFunction(lib, "createGame"));
    _currentGame = std::unique_ptr<IGame> (_game_entry());
}

std::vector<std::string> Core::openLibDir(std::string libraryPath)
{
	std::vector<std::string> *files = new std::vector<std::string>();
	DIR *directory = opendir(libraryPath.c_str());
	struct dirent *dp = readdir(directory);
	while (dp != nullptr) {
		auto _fileName = std::string(dp->d_name);
		if (_fileName != ".." && _fileName != "."
			&& _fileName.substr(_fileName.find_last_of('.') + 1) == "so")
			files->push_back(_fileName);
		dp = readdir(directory);
	}
	closedir(directory);
	return *files;
}

void Core::checkLib(std::string libName)
{
	_libraries = openLibDir("lib");
	_numberOfLib = -1;

	for (uint i = 0; i < _libraries.size(); i++) {
		std::string currentLibrary = _libraries.at(i);
		if (libName == currentLibrary)
			_numberOfLib = i;
	}
	if (_numberOfLib == -1)
		exit(84);
}

Core::Core(std::string filename)
{
	_numberOfLib = 0;
	_changeLib = 0;
	_exit = false;
	_indexMenu = 0;
	_playerName = "Player              ";
    _filename = filename;
    _library = std::make_unique<Library>();

	_handle = _library->loadLibrary(filename);
	_lib_entry = ((ILib *(*) (void)) _library->getFunction(_handle, "createLib"));
	_currentLib = std::unique_ptr<ILib> (_lib_entry());
    std::string libPath = getFilename().substr(getFilename().find_last_of("/\\") + 1);
    checkLib(libPath.substr(libPath.find_last_of("/\\") + 1));
	_games = openLibDir("games");
	if (_games.size() == 0)
		exit(84);
}

Core::~Core()
{
	if (_handle) {
        _currentLib = nullptr;
        _library->closeLibrary(_handle);
        _handle = nullptr;
		_lib_entry = nullptr;
    }
}

void print_help()
{
    std::cout << "./arcade ./lib/arcade_ + name of graphics library + .so" << std::endl;
    exit(84);
}

int main(int ac, char **av)
{
	if (ac != 2)
		print_help();

    std::string filename = std::string(av[1]);
    Core *terminal = new Core(filename);
	terminal->launch_game();
    return (0);
}