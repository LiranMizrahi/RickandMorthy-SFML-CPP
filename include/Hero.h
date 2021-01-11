#pragma once

#include "SingletonPicture.h"
#include <SFML/Graphics.hpp>
#include "MovingObjects.h"
#include"GameObj.h"
#include"Coin.h"

class Hero : public MovingObjects {

   public:
	   Hero() = default;
	   ~Hero()override = default;
	   Hero(const sf::Vector2f&, int );
	   int getLife();
	   int getScore();
	   void SetScore(int);
	   void SetLife(int);
	   void setLastPosition(sf::Vector2f);
	   void UpdateLocation(float);

	   virtual void handleColision(GameObj&)override;
	   virtual void handleColision(Rope&)override;
	   virtual void handleColision(Hero&)override {};
	   virtual void handleColision(Floor&)override;
	   virtual void handleColision(Ladder&)override;
	   virtual void handleColision(Coin&) override;


private:
		int m_life, m_score;

};