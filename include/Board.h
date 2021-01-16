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
	Board(std::vector <std::vector<char>>, int);
	void draw(sf::RenderWindow&)const;
	void moveCharacters(float);
	int checkCollisions(float);
    bool checkIfObjectFalling(float);
    void andEnemyRandomly(int playerselect);
    void printGameStatus(sf::RenderWindow &, int level, sf::Time , sf::Clock, bool);
	void checkIfHeroDig(const sf::Time &time);
    void ResetMap();
    void restroreGameObjects(const sf::Time &time);

        private:
	//private members
    Hero* m_hero;
	std::vector <std::vector <std::unique_ptr <StaticObjects>>> m_staticObjects;
	std::vector <std::unique_ptr <MovingObjects>>m_movingObjects;

	size_t m_width, m_height;
    float m_cellHight,m_cellWidth;

    sf::Text m_scoreText;
    sf::Text m_levelText;
    sf::Text m_lifeText;
	sf::Text m_timeTheLevel;

	//private function
    void createObject(char, const sf::Vector2f &, int, int );
	void createEnemysVector(const sf::Vector2f&, int);
	void addGiftToStaticVector(const sf::Vector2f&, sf::Vector2f, int);
	void handleCollisions(GameObj &obj);
    bool isObjectIsFalling(float, MovingObjects&);
	void readFile(std::vector <std::vector<char>> , int);
    void initGamestatusbar();



};