#pragma once
#include "GameObj.h"
#include <SFML/Graphics.hpp>
#include "MovingObjects.h"
class Hero : public MovingObjects {



   public:
	   Hero();
	   Hero(const sf::Texture*, const sf::Vector2f&);
	   int GetLife();
	   int GetScore();
	   void SetScore(int);
	   void SetLife(int);
private:
	int m_life, m_score;
	

};