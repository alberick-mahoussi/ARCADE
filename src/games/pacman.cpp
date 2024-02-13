/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-alberick.mahoussi
** File description:
** pacman
*/

#include "../../include/games/Pacman.hpp"
#include <algorithm>

std::vector<std::vector<char>> Pacman::genmap(std::string file)
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
    map[10][13] = '>';
    map[8][12] = '&';
    map[8][13] = '&';
    map[8][14] = '&';
    this->_pacmanPos = {10, 13};
    ghost_pos.push_back({8, 12});
    ghost_pos.push_back({8, 13});
    ghost_pos.push_back({8, 14});
    return map;
}

Pacman::Pacman()
{
    _score = 0;
    _isGameOver = false;
    _direction = RIGHT_DIRECTION;
    map_generator();
    _speed = 0.7f;
    // for (int i = 0; i  < 22; i++)
    //     std::cout << _map[i] << std::endl;
}

void Pacman::reset()
{
    _score = 0;
    _isGameOver = false;
    _direction = RIGHT_DIRECTION;
    map_generator();
    _speed = 0.7f;   
}

void Pacman::map_generator()
{
    std::vector<std::vector<char>> genmaps = genmap("map/pacman.txt");
    std::vector<std::string> map;
    int i = 0;
    int j = 0;

    for (int i = 0; i < genmaps.size(); i++) {
        for (int j = 0; j < genmaps[i].size(); j++) {
            if (genmaps[i][j] == '#') {
                _mapPacman.push_back("#");
                _map.push_back("images/brick_block.png");
            } else if (genmaps[i][j] == '<' || genmaps[i][j] == '>' || genmaps[i][j] == '^' || genmaps[i][j] == 'v') {
                _mapPacman.push_back(">");
                _map.push_back("images/pacman.png");
            } else if (genmaps[i][j] == '*') {
                _mapPacman.push_back("*");
                _map.push_back("images/snake_fruit.png");
            } else if (genmaps[i][j] == '&') {
                _mapPacman.push_back("&");
                _map.push_back("images/ghost.png");
            } else {
                _mapPacman.push_back(" ");
                _map.push_back("none");
            }
        }
    }
}

std::vector<int> serch_pacman(std::vector<std::string>map)
{
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] == '<' || map[i][j] == '>' || map[i][j] == '^' || map[i][j] == 'v' ) {
                return {i, j};
            }
        }
    }
    std::cout << "Erreur: can't find pacman" << std::endl;
    return {-1, -1};
}

void Pacman::PacmanUp()
{
    _pacmanPos = serch_pacman(_mapPacman);
    int x = _pacmanPos[0];
    int y = _pacmanPos[1];
        if (_mapPacman[x - 1][y] == '*') {
            _mapPacman[x][y] = ' ';
            _mapPacman  [x-1][y] = '^';
            _speed -= 0.025;
            _score += 100;
        } else if (_mapPacman[x - 1][y] == '&') {
            if (life == 0)
                this->gameIsOver();
            else
                reset();
        } else if (_mapPacman[x - 1][y] == ' ') {
            _mapPacman[x][y] = ' ';
            _mapPacman[x-1][y] = '^';
        }
        x--;
}

std::vector<std::string> Pacman::getMap()
{
    return _map;
}

std::string Pacman::displayMap()
{
    return ("images/snake_background.png");
}

void Pacman::gameIsOver()
{
    std::cout << "gameover" << std::endl;
    _isGameOver = true;
}

void Pacman::moveSnake()
{
    switch (_direction)
    {
    case UP_DIRECTION: PacmanUp();
        break;
    case DOWN_DIRECTION: PacmanDown();
        break;
    case LEFT_DIRECTION: PacmanLeft();
        break;
    case RIGHT_DIRECTION: PacmanRight();
        break;
    }
}

void Pacman::gameUpdate(int input)
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

bool Pacman::checkGameOver()
{
    if (_isGameOver)
        return true;
    return false;
}

int Pacman::getScore()
{
    return _score;
}