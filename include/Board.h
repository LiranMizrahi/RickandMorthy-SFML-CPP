#pragma once

#include "vector"
#include <fstream>
#include "Hero.h"

class Picture;


class Board {

public:
	Board();
    Board(std::fstream ,Picture * pic);


private:
	//std::vector <Enemy> m_enemy;
	Hero m_hero;
	int m_width, m_height;


};