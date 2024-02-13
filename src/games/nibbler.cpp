/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-alberick.mahoussi
** File description:
** Nibbler
*/

#include "../../include/games/Nibbler.hpp"
#include <algorithm>
#include <fstream>

const int ROWS = 16;
const int COLS = 18;

std::vector<std::vector<char>> genmap(std::string file)
{
    std::vector<std::vector<char>> map;
    std::ifstream ifs(file);
    std::string ligne;
    if (ifs) {
        while (std::getline(ifs, ligne))
        {
            std::vector<char> ligneCaracteres;
            for (int i = 0; i < ligne.size(); i++) {
                ligneCaracteres.push_back(ligne[i]);
            }
            map.push_back(ligneCaracteres);
        }
        ifs.close();
    } else {
        std::cout << "Erreur: can't open file"<< file << std::endl;
    }
    return map;
}

Nibbler::Nibbler()
{
    _score = 0;
    _isGameOver = false;
    _direction = RIGHT_DIRECTION;
    map_generator();
    _speed = 0.7f;
}

void Nibbler::map_generator()
{
    std::vector<std::vector<char>> genmaps = genmap("map/nibbler.txt");
    genmaps[ROWS/2][COLS/2] = '>';
    genmaps[ROWS/2][COLS/2-1] = 'o';
    genmaps[ROWS/2][COLS/2-2] = 'o';
    genmaps[ROWS/2][COLS/2-3] = 'o';
    std::vector<std::string> map;
    int i = 0;
    int j = 0;

    for (int i = 0; i < genmaps.size(); i++) {
        for (int j = 0; j < genmaps[i].size(); j++) {
            if (genmaps[i][j] == '#') {
                _mapNibbler.push_back("X");
                _map.push_back("images/brick_block.png");
            } else if (genmaps[i][j] == 'o') {
                _mapNibbler.push_back("O");
                _map.push_back("images/snake_body.png");
            } else if (genmaps[i][j] == '<' || genmaps[i][j] == '>' || genmaps[i][j] == '^' || genmaps[i][j] == 'v') {
                _mapNibbler.push_back("H");
                _map.push_back("images/snake_head.png");
            } else if (genmaps[i][j] == '*') {
                _mapNibbler.push_back("F");
                _map.push_back("images/snake_fruit.png");
            } else {
                _mapNibbler.push_back(" ");
                _map.push_back("none");
            }
        }
    }
    this->_NibblerPos.push_back((ROWS / 2) * COLS + (COLS / 2));
    this->_NibblerPos.push_back((ROWS / 2) * COLS + (COLS / 2 - 1));
    this->_NibblerPos.push_back((ROWS / 2) * COLS + (COLS / 2 - 2));
    this->_NibblerPos.push_back((ROWS / 2) * COLS + (COLS / 2 - 3));
}

std::vector<std::string> Nibbler::getMap()
{
    return _map;
}

std::string Nibbler::displayMap()
{
    return ("images/snake_background.png");
}

void Nibbler::gameIsOver()
{
    std::cout << "gameover" << std::endl;
    _isGameOver = true;
}

void Nibbler::moveSnake()
{
    switch (_direction)
    {
    case UP_DIRECTION: snakeUp();
        break;
    case DOWN_DIRECTION: snakeDown();
        break;
    case LEFT_DIRECTION: snakeLeft();
        break;
    case RIGHT_DIRECTION: snakeRight();
        break;
    }
}

void Nibbler::snakeUp()
{
    for (int i = 1; i < getLimitX(); i++)
        for (int j = 1; j < getLimitY(); j++, _index++) {
            if (_mapNibbler[_index] == "H" && (_mapNibbler[_index - 18] == "O")) {
                gameIsOver();
            } else if (_mapNibbler[_index] == "H" && _mapNibbler[_index - 18] != "X") {
                if (_mapNibbler[_index - 18] != "F") {
                    _NibblerPos.push_back(_index - 18);
                    std::rotate(_NibblerPos.rbegin(), _NibblerPos.rbegin() + 1, _NibblerPos.rend());
                    _mapNibbler[_NibblerPos[_NibblerPos.size()-1]] = " ";
                    _map[_NibblerPos[_NibblerPos.size()-1]] = "none";
                    _NibblerPos.pop_back();
                } else {
                    _NibblerPos.push_back(_index - 18);
                    std::rotate(_NibblerPos.rbegin(), _NibblerPos.rbegin() + 1, _NibblerPos.rend());
                    _speed -= 0.025;
                    _score += 100;
                }
                _map[_index] = "images/snake_body.png";
                _mapNibbler[_index] = "O";
                _mapNibbler[_index - 18] = "H";
                _map[_index - 18] = "images/snake_head.png";
            }
        }
    _index = 20;
}

void Nibbler::snakeLeft()
{
    for (int i = 1; i < getLimitX(); i++)
        for (int j = 1; j < getLimitY(); j++, _index++) {
            if (_mapNibbler[_index] == "H" && (_mapNibbler[_index - 1] == "O")) {
                gameIsOver();
            } else if (_mapNibbler[_index] == "H" && _mapNibbler[_index - 1] != "X") {
                if (_mapNibbler[_index - 1] != "F") {
                    _NibblerPos.push_back(_index - 1);
                    std::rotate(_NibblerPos.rbegin(), _NibblerPos.rbegin() + 1, _NibblerPos.rend());
                    _mapNibbler[_NibblerPos[_NibblerPos.size()-1]] = " ";
                    _map[_NibblerPos[_NibblerPos.size()-1]] = "none";
                    _NibblerPos.pop_back();
                } else {
                    _NibblerPos.push_back(_index - 1);
                    std::rotate(_NibblerPos.rbegin(), _NibblerPos.rbegin() + 1, _NibblerPos.rend());
                    _speed -= 0.025;
                    _score += 100;
                }
                _map[_index] = "images/snake_body.png";
                _mapNibbler[_index] = "O";
                _mapNibbler[_index - 1] = "H";
                _map[_index - 1] = "images/snake_head.png";
            }
        }
    _index = 20;
}

void Nibbler::snakeRight()
{
    for (int i = 1; i < getLimitX(); i++)
        for (int j = 1; j < getLimitY(); j++, _index++) {
            if (_mapNibbler[_index] == "H" && (_mapNibbler[_index + 1] == "O")) {
                gameIsOver();
            } else if (_mapNibbler[_index] == "H" && _mapNibbler[_index + 1] != "X") {
                if (_mapNibbler[_index + 1] != "F") {
                    _NibblerPos.push_back(_index + 1);
                    std::rotate(_NibblerPos.rbegin(), _NibblerPos.rbegin() + 1, _NibblerPos.rend());
                    _mapNibbler[_NibblerPos[_NibblerPos.size()-1]] = " ";
                    _map[_NibblerPos[_NibblerPos.size()-1]] = "none";
                    _NibblerPos.pop_back();
                } else {
                    _NibblerPos.push_back(_index + 1);
                    std::rotate(_NibblerPos.rbegin(), _NibblerPos.rbegin() + 1, _NibblerPos.rend());
                    _speed -= 0.025;
                    _score += 100;
                }
                _map[_index] = "images/snake_body.png";
                _mapNibbler[_index] = "O";
                _mapNibbler[_index + 1] = "H";
                _map[_index + 1] = "images/snake_head.png";
                _index++;
                j++;
            }
        }
    _index = 20;
}

void Nibbler::snakeDown()
{
    for (int i = 1; i < getLimitX(); i++)
        for (int j = 1; j < getLimitY(); j++, _index++) {
            if (_mapNibbler[_index] == "H" && (_mapNibbler[_index + 18] == "O")) {
                gameIsOver();
            } else if (_mapNibbler[_index] == "H" && _mapNibbler[_index + 18] != "X") {
                if (_mapNibbler[_index + 18] != "F") {
                    _NibblerPos.push_back(_index + 18);
                    std::rotate(_NibblerPos.rbegin(), _NibblerPos.rbegin() + 1, _NibblerPos.rend());
                    _mapNibbler[_NibblerPos[_NibblerPos.size()-1]] = " ";
                    _map[_NibblerPos[_NibblerPos.size()-1]] = "none";
                    _NibblerPos.pop_back();
                } else {
                    _NibblerPos.push_back(_index + 18);
                    std::rotate(_NibblerPos.rbegin(), _NibblerPos.rbegin() + 1, _NibblerPos.rend());
                    _speed -= 0.025;
                    _score += 100;
                }
                _map[_index] = "images/snake_body.png";
                _mapNibbler[_index] = "O";
                _mapNibbler[_index + 18] = "H";
                _map[_index + 18] = "images/snake_head.png";
                _index += 18;
                i++;
            }
        }
    _index = 20;
}

void Nibbler::gameInput(int input)
{
    input--;
	if (input == LEFT_DIRECTION && _direction != RIGHT_DIRECTION)
		_direction = input;
	if (input == RIGHT_DIRECTION && _direction != LEFT_DIRECTION)
	    _direction = input;
	if (input == UP_DIRECTION && _direction != DOWN_DIRECTION)
	    _direction = input;
	if (input == DOWN_DIRECTION && _direction != UP_DIRECTION)
	    _direction = input;
}

void Nibbler::gameUpdate(int input)
{
    static clock_t t = clock();
	clock_t now = clock();
	float time = now - t;
	unsigned int p = 0;

	if (time / CLOCKS_PER_SEC > _speed) {
		t = clock();
		moveSnake();
	}
}

bool Nibbler::checkGameOver()
{
    if (_isGameOver)
        return true;
    return false;
}

int Nibbler::getScore()
{
    return _score;
}