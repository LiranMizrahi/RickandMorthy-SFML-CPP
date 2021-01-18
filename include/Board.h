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
	Board();
	Board(std::vector<std::vector<char>> file, int PlayerSelection,
          int level);
	void draw(sf::RenderWindow&)const;
	void moveCharacters(float, const  std::vector <std::vector<char>>& );
	int checkCollisions(float);
    bool checkIfObjectFalling(float);
    void andEnemyRandomly(int playerselect);
    size_t getWidth();
    size_t getHeight();
    StaticObjects* getStaticObjectsFromVector(int,int);
    MovingObjects* getSMovingObjectsFromVector(int);

	void checkIfHeroDig(const sf::Time&);
	void ResetMap();
    void restroreGameObjects(const sf::Time &time);
    int getHerolife();
    int getHeroScore();
    void setHeroScore(int);
    int getMovingObjecVectorSize();
    void setHeroLife(int);

private:
	//private members
    Hero* m_hero;
	std::vector <std::vector <std::unique_ptr <StaticObjects>>> m_staticObjects;
	std::vector <std::unique_ptr <MovingObjects>>m_movingObjects;

	size_t m_width, m_height;
    float m_cellHight,m_cellWidth;
public:
    float getCellHight() const;

    float getCellWidth() const;

private:

    //private function
    void createObject(char input, const sf::Vector2f &location,
                      int PlayerSelection, int i, int level);
	void createEnemysVector(const sf::Vector2f&, int);
	void addGiftToStaticVector(const sf::Vector2f&, sf::Vector2f, int);
	void handleCollisions(GameObj &obj);
    bool isObjectIsFalling(float, MovingObjects&);
	void
    readFile(const std::vector<std::vector<char>> &file, int PlayerSelection,
             int level);


};