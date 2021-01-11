#pragma once
#include "GameObj.h"
#include "SingletonPicture.h"
#include <SFML/Graphics.hpp>
#include "MovingObjects.h"
#include "Macros.h"
#include"Hero.h"


class Enemy : public MovingObjects {
public:


	  Enemy(const sf::Vector2f&, int);
     ~Enemy() override = default;

	 virtual void UpdateLocation(float time) {};
	virtual void handleColision(GameObj& obj) override {};
	virtual void handleColision(Rope& Obj) override;
	virtual void handleColision(Hero& Obj) override ;
	virtual void handleColision(Floor& obj)override;
	virtual void handleColision(Ladder& obj) override ;
	virtual void handleColision(Coin&) override {};
	virtual void handleColision(Enemy& Obj) override {};


private:
	
};