#pragma once

#include "vector"
#include <fstream>
#include "Hero.h"

class Picture;


class Board {

public:
	Board();
    Board(std::fstream ,  Picture& pic);
	void draw(sf::RenderWindow&);

private:
	//std::vector <Enemy> m_enemy;
	std::vector <GameObj> staticobj;
	Hero m_hero;
	int m_width, m_height;


};