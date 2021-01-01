#pragma once
#include "GameObj.h"
#include "Picture.h"
#include <SFML/Graphics.hpp>
#include "MovingObjects.h"
class Hero : public MovingObjects {



   public:
	   Hero();
	   Hero( Picture &, const sf::Vector2f&,  int );
	   int GetLife();
	   int GetScore();
	   void SetScore(int);
	   void SetLife(int);
	   void UpdateLocation(float,int);
private:
	int m_life, m_score;
	

};