#pragma once
#include"Enemy.h"

class SmartEnemy: public Enemy
{
public:
	SmartEnemy(const sf::Vector2f& loc, int EnemySelection);
	~SmartEnemy() override = default;
	virtual void UpdateLocation(float)override;

	//virtual void handleColision(GameObj& obj) override {};
	//virtual void handleColision(Rope& Obj) override {};
	//virtual void handleColision(Hero& Obj) override {};
	//virtual void handleColision(Floor& obj)override {};
	//virtual void handleColision(Ladder& obj) override {};
	//virtual void handleColision(Coin&) override {};
	//virtual void handleColision(Hero&) override {};

private:

};