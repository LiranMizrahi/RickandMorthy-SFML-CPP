#pragma once
#include"Enemy.h"

class SmartEnemy: public Enemy
{
public:
	SmartEnemy(const sf::Vector2f& loc, int EnemySelection);
	~SmartEnemy() override = default;
	virtual void UpdateLocation(float)override;



private:

};