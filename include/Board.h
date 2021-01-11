#pragma once

#include "vector"
#include <fstream>
#include "Hero.h"
#include "Enemy.h"
#include "StaticObjects.h"
class SingletonPicture;
class Sound;


class Board {

public:
	Board();
    Board(std::ifstream& , int);
	void draw(sf::RenderWindow&)const;
	void moveCharacters(float);
	int checkCollisions(float);
    bool isObjectIsfalling(float);
	void fallingGift(float);

private:
	//private members
	Hero m_hero;
	std::vector <std::vector <std::unique_ptr <StaticObjects>>> m_staticObjects;
	std::vector <std::unique_ptr <Enemy>>m_enemys;
	int m_width, m_height;

	//private function
    void createObject(char, const sf::Vector2f &, int, int );


    float cellhight,cellwidth;


};