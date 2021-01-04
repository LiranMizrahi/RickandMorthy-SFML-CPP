#pragma once
#include "GameObj.h"
#include "Picture.h"
#include <SFML/Graphics.hpp>
#include "MovingObjects.h"
#include "Macros.h"


class Enemy : public MovingObjects {
public:
	const  float ENEMYSPEED = 300.f;

	Enemy(Picture&, const sf::Vector2f&, int);
	virtual void UpdateLocation(float time) {
		int RandomMov = std::rand() % 4;

		switch (RandomMov)
		{

		case LEFT:
			this->move(-ENEMYSPEED * time, 0);
			break;
		case RIGHT:
			this->move(ENEMYSPEED * time, 0);

			break;
		case UP:
			break;
		case DOWN:
			break;
		}
	};
	virtual void handleColision(GameObj& obj) override {};
	virtual void handleColision(Rope& Obj) override {};
	virtual void handleColision(Hero& Obj) override {};
	virtual void handleColision(Floor& obj)override {};
	virtual void handleColision(Ladder& obj) override {};
	virtual void handleColision(Coin&) override {};


private:

};