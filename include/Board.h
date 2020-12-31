#pragma once

#include "vector"
#include <fstream>
#include "Hero.h"
#include "Enemy.h"
#include "StaticObjects.h"
class Picture;


class Board {

public:
	Board();
    Board(std::ifstream& ,  Picture& pic);
	void draw(sf::RenderWindow&)const;

private:
	//private members
	Hero m_hero;
	std::vector <std::unique_ptr <StaticObjects>> m_staticObjects;
	std::vector <std::unique_ptr <Enemy>>m_enemys;
	int m_width, m_height;

	//private function
	void createObject( Picture& pic,char,const sf::Vector2f &);
	


};