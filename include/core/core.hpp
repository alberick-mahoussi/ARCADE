/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-lise-emmanuelle.christian
** File description:
** core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <iostream>
#include <dlfcn.h>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include "../lib/IMusic.hpp"
#include "../lib/ILib.hpp"
#include "../games/IGame.hpp"

class Library{
	public:
		Library();
		~Library();

		void *loadLibrary(std::string libraryPath);
		void *getFunction(void *handle, std::string functionName);
		void closeLibrary(void *handle);
};

class Core
{
    private:
		void *_handle;
		void *_handleGame;
        std::unique_ptr<Library> _library;
		std::vector<std::string> _libraries;
		std::vector<std::string> _map;
		std::vector<std::string> _games;
        std::string _filename;
		std::unique_ptr<ILib> _currentLib;
		std::unique_ptr<IGame> _currentGame;
		ILib *(*_lib_entry)(void);
		IGame *(*_game_entry)(void);
		int _numberOfLib;
		int _changeLib;
		bool _exit;
		int _indexMenu;
		int _input;
		std::string _playerName;
		int _score = 0;
		int _menu = 1;
		int _index = 0;
		int _previousGameIndex = 0;
    public:
		Core(std::string);
        ~Core();
        std::string getFilename() {
            return _filename;
        };
		int getValue(int value) {
			return value;
		};
        void checkLib(std::string libName);
        std::vector<std::string> openLibDir(std::string libraryPath);
		void loadLib(std::string libName);
		void loadGame(std::string libName);
		void getMenuOptionEvent();
		void load_lib(const char *);
        void launch_game();
		void chooseMenu();
		void chooseLib();
		void chooseGame();
		void displayMenu();
		void getSubMenuOptEvent(int max, std::string parameter);
		void displayGame();
		void displayPauseMenu();
		void getKeyEvent();
};

enum KeyPress {
	NO_INPUT = -1,
	LEFT_ARROW = 2,
	RIGHT_ARROW = 3,
	UP_ARROW = 4,
	DOWN_ARROW = 5,
	ESCAPE = 6,
	SPACE = 7,
	ENTER = 8,
	BACKSPACE = 9,
	EXIT = 0,
	A_KEY = 10,
	B_KEY = 11,
	C_KEY = 12,
	D_KEY = 13,
	E_KEY = 14,
	F_KEY = 15,
	G_KEY = 16,
	H_KEY = 17,
	I_KEY = 18,
	J_KEY = 19,
	K_KEY = 20,
	L_KEY = 21,
	M_KEY = 22,
	N_KEY = 23,
	O_KEY = 24,
	P_KEY = 25,
	Q_KEY = 26,
	R_KEY = 27,
	S_KEY = 28,
	T_KEY = 29,
	U_KEY = 30,
	V_KEY = 31,
	W_KEY = 32,
	X_KEY = 33,
	Y_KEY = 34,
	Z_KEY = 35,
	F1_KEY = 36,
	F2_KEY = 37,
	F3_KEY = 38,
	F4_KEY = 39,
	F5_KEY = 40,
	F6_KEY = 41,
	F7_KEY = 42,
};

#endif /* !CORE_HPP_ */