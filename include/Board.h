#pragma once
#include "vector"
#include <fstream>
#include "Hero.h"
#include "Enemy.h"
#include "StaticObjects.h"
#include "MovingObjects.h"

class SingletonPicture;
class SingletonSound;

class Board {

public:
	Board() = default;
    Board(std::ifstream& , int);
	void draw(sf::RenderWindow&)const;
	void moveCharacters(float);
	int checkCollisions(float);
    bool checkIfObjectFalling(float);
    void checkIfHeroDig();
    void printGameStatus(sf::RenderWindow &, int level);

private:
	//private members
    Hero* m_hero;
	std::vector <std::vector <std::unique_ptr <StaticObjects>>> m_staticObjects;
	std::vector <std::unique_ptr <MovingObjects>>m_movingObjects;

	int m_width, m_height;
    float m_cellHight,m_cellWidth;

    sf::Text m_scoreText;
    sf::Text m_levelText;
    sf::Text m_lifeText;

	//private function
    void createObject(char, const sf::Vector2f &, int, int );
	void createEnemysVector(const sf::Vector2f&, int);
	void addGiftToStaticVector(const sf::Vector2f&, sf::Vector2f, int);
	bool handleCollisions(GameObj &obj);

    bool isObjectIsFalling(float, MovingObjects&);

    void initGamestatusbar();



};