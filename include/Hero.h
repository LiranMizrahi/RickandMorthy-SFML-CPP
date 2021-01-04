#pragma once
#include "Picture.h"
#include <SFML/Graphics.hpp>
#include "MovingObjects.h"
#include"GameObj.h"


const  float HEROSPEED = 700.f ;

class Hero : public MovingObjects {

	

   public:
	   Hero();
	   Hero( Picture &, const sf::Vector2f&,  int );
	   int GetLife();
	   int GetScore();
	   void SetScore(int);
	   void SetLife(int);
	   void setLastPosition(sf::Vector2f);
	   void UpdateLocation(float);

	   virtual void handleColision(GameObj& obj) ;
	   virtual void handleColision(Rope& Obj) ;
	   virtual void handleColision(Hero& Obj)  {};
	   virtual void handleColision(Floor& obj);
	   virtual void handleColision(Ladder& obj);

private:
		int m_life, m_score;
		sf::Vector2f m_LastPosition;
		sf::Vector2f m_oldPosition;

};