#pragma once
#include "GameObj.h"
#include "Picture.h"
#include <SFML/Graphics.hpp>
#include "MovingObjects.h"

const  float HEROSPEED = 700.f ;

class Hero : public MovingObjects {

	

   public:
	   Hero();
	   Hero( Picture &, const sf::Vector2f&,  int );
	   int GetLife();
	   int GetScore();
	   void SetScore(int);
	   void SetLife(int);
	   void UpdateLocation(float);
private:
		int m_life, m_score;
	

};