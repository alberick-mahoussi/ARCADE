/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-lise-emmanuelle.christian
** File description:
** snake
*/

#include "../../include/games/snake.hpp"
#include <algorithm>

Snake::Snake()
{
    _score = 0;
    _isGameOver = false;
    _direction = UP_DIRECTION;
    map_generator();
    _speed = 0.7f;
    // for (int i = 0; i  < 22; i++)
    //     std::cout << _map[i] << std::endl;
}

Snake::~Snake()
{
}

void Snake::randomFruit()
{
    int i = 0;
    while (1) {
        i = rand() % (getLimitX() * getLimitY());
        if (_mapSnake[i] != "X" && _mapSnake[i] != "H" && _mapSnake[i] != "O") {
            _mapSnake[i] = "F";
            _map[i] = "images/snake_fruit.png";
            break;
        }
    }

    // std::cout << _snakePos[0] << " " << _snakePos[1] << " " << _snakePos[2] << " " << _snakePos[3] << " " << _mapSnake[_snakePos[0]] << " 1 " << _mapSnake[_snakePos[1]] << " 2 " << _mapSnake[_snakePos[2]] << " 3 " << _mapSnake[_snakePos[3]] << std::endl;
}

void Snake::map_generator()
{
    std::vector<std::string> map;
    int i = 0;
    int j = 0;

    while (i < 16) {
        while (j < 18) {
            if (i == 0 || i == 15 || j == 0 || j == 17) {
                _mapSnake.push_back("X");
                _map.push_back("images/brick_block.png");
            }
            else if ((i == 9 && j == 9) || (i == 10 && j == 9) || (i == 8 && j == 9)) {
                _mapSnake.push_back("O");
                _map.push_back("images/snake_body.png");
            } else if (i == 7 && j == 9) {
                _mapSnake.push_back("H");
                _map.push_back("images/snake_head.png");
            } else {
                _mapSnake.push_back(" ");
                _map.push_back("none");
            }
            j++;
        }
        j = 0;
        i++;
    }
    _snakePos.push_back(153);
    _snakePos.push_back(171);
    _snakePos.push_back(189);
    _snakePos.push_back(135);
    std::rotate(_snakePos.rbegin(), _snakePos.rbegin() + 1, _snakePos.rend());
    randomFruit();
}

std::vector<std::string> Snake::getMap()
{
    return _map;
}

std::string Snake::displayMap()
{
    return ("images/snake_background.png");
}

void Snake::gameIsOver()
{
    std::cout << "gameover" << std::endl;
    _isGameOver = true;
}

void Snake::snakeUp()
{
    for (int i = 1; i < getLimitX(); i++)
        for (int j = 1; j < getLimitY(); j++, _index++) {
            if (_mapSnake[_index] == "H" && (_mapSnake[_index - 18] == "X" || _mapSnake[_index - 18] == "O")) {
                gameIsOver();
            } else if (_mapSnake[_index] == "H" && _mapSnake[_index - 18] != "X") {
                if (_mapSnake[_index - 18] != "F") {
                    _snakePos.push_back(_index - 18);
                    std::rotate(_snakePos.rbegin(), _snakePos.rbegin() + 1, _snakePos.rend());
                    _mapSnake[_snakePos[_snakePos.size()-1]] = " ";
                    _map[_snakePos[_snakePos.size()-1]] = "none";
                    _snakePos.pop_back();
                } else {
                    _snakePos.push_back(_index - 18);
                    std::rotate(_snakePos.rbegin(), _snakePos.rbegin() + 1, _snakePos.rend());
                    _speed -= 0.025;
                    _score += 100;
                    randomFruit();
                }
                _map[_index] = "images/snake_body.png";
                _mapSnake[_index] = "O";
                _mapSnake[_index - 18] = "H";
                _map[_index - 18] = "images/snake_head.png";
            }
        }
    _index = 20;
}

void Snake::snakeDown()
{
    for (int i = 1; i < getLimitX(); i++)
        for (int j = 1; j < getLimitY(); j++, _index++) {
            if (_mapSnake[_index] == "H" && (_mapSnake[_index + 18] == "X" || _mapSnake[_index + 18] == "O")) {
                gameIsOver();
            } else if (_mapSnake[_index] == "H" && _mapSnake[_index + 18] != "X") {
                if (_mapSnake[_index + 18] != "F") {
                    _snakePos.push_back(_index + 18);
                    std::rotate(_snakePos.rbegin(), _snakePos.rbegin() + 1, _snakePos.rend());
                    _mapSnake[_snakePos[_snakePos.size()-1]] = " ";
                    _map[_snakePos[_snakePos.size()-1]] = "none";
                    _snakePos.pop_back();
                } else {
                    _snakePos.push_back(_index + 18);
                    std::rotate(_snakePos.rbegin(), _snakePos.rbegin() + 1, _snakePos.rend());
                    _speed -= 0.025;
                    _score += 100;
                    randomFruit();
                }
                _map[_index] = "images/snake_body.png";
                _mapSnake[_index] = "O";
                _mapSnake[_index + 18] = "H";
                _map[_index + 18] = "images/snake_head.png";
                _index += 18;
                i++;
            }
        }
    _index = 20;
}


void Snake::snakeLeft()
{
    for (int i = 1; i < getLimitX(); i++)
        for (int j = 1; j < getLimitY(); j++, _index++) {
            if (_mapSnake[_index] == "H" && (_mapSnake[_index - 1] == "X" || _mapSnake[_index - 1] == "O")) {
                gameIsOver();
            } else if (_mapSnake[_index] == "H" && _mapSnake[_index - 1] != "X") {
                if (_mapSnake[_index - 1] != "F") {
                    _snakePos.push_back(_index - 1);
                    std::rotate(_snakePos.rbegin(), _snakePos.rbegin() + 1, _snakePos.rend());
                    _mapSnake[_snakePos[_snakePos.size()-1]] = " ";
                    _map[_snakePos[_snakePos.size()-1]] = "none";
                    _snakePos.pop_back();
                } else {
                    _snakePos.push_back(_index - 1);
                    std::rotate(_snakePos.rbegin(), _snakePos.rbegin() + 1, _snakePos.rend());
                    _speed -= 0.025;
                    _score += 100;
                    randomFruit();
                }
                _map[_index] = "images/snake_body.png";
                _mapSnake[_index] = "O";
                _mapSnake[_index - 1] = "H";
                _map[_index - 1] = "images/snake_head.png";
            }
        }
    _index = 20;
}


void Snake::snakeRight()
{
    for (int i = 1; i < getLimitX(); i++)
        for (int j = 1; j < getLimitY(); j++, _index++) {
            if (_mapSnake[_index] == "H" && (_mapSnake[_index + 1] == "X" || _mapSnake[_index + 1] == "O")) {
                gameIsOver();
            } else if (_mapSnake[_index] == "H" && _mapSnake[_index + 1] != "X") {
                if (_mapSnake[_index + 1] != "F") {
                    _snakePos.push_back(_index + 1);
                    std::rotate(_snakePos.rbegin(), _snakePos.rbegin() + 1, _snakePos.rend());
                    _mapSnake[_snakePos[_snakePos.size()-1]] = " ";
                    _map[_snakePos[_snakePos.size()-1]] = "none";
                    _snakePos.pop_back();
                } else {
                    _snakePos.push_back(_index + 1);
                    std::rotate(_snakePos.rbegin(), _snakePos.rbegin() + 1, _snakePos.rend());
                    _speed -= 0.025;
                    _score += 100;
                    randomFruit();
                }
                _map[_index] = "images/snake_body.png";
                _mapSnake[_index] = "O";
                _mapSnake[_index + 1] = "H";
                _map[_index + 1] = "images/snake_head.png";
                _index++;
                j++;
            }
        }
    _index = 20;
}

void Snake::moveSnake()
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

void Snake::gameInput(int input)
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

void Snake::gameUpdate(int input)
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

bool Snake::checkGameOver()
{
    if (_isGameOver)
        return true;
    return false;
}

int Snake::getScore()
{
    return _score;
}