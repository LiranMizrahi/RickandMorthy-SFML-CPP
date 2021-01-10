#pragma once
#include"Enemy.h"

class SmartEnemy: public Enemy
{
	~SmartEnemy() override = default;
public:
	virtual void UpdateLocation(float);

	virtual void handleColision(GameObj& obj) override {};
	virtual void handleColision(Rope& Obj) override {};
	virtual void handleColision(Hero& Obj) override {};
	virtual void handleColision(Floor& obj)override {};
	virtual void handleColision(Ladder& obj) override {};
	virtual void handleColision(Coin&) override {};
private:

};