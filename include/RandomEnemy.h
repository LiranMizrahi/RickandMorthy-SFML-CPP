#pragma once

#include"Enemy.h"

class RandomEnemy : public Enemy
{
public:
	RandomEnemy(const sf::Vector2f& loc, int EnemySelection);
    ~RandomEnemy()override = default;
	virtual void UpdateLocation(float);

	/*virtual void handleColision(GameObj& obj) override {};
	virtual void handleColision(Rope& Obj) override {};
	virtual void handleColision(Hero& Obj) override {};
	virtual void handleColision(Floor& obj)override {};
	virtual void handleColision(Ladder& obj) override {};
	virtual void handleColision(Coin&) override {};*/
private:

};

