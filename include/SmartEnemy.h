#pragma once
#include"Enemy.h"

class SmartEnemy: public Enemy
{
public:
	SmartEnemy(const sf::Vector2f &loc, int EnemySelection,
               const sf::Vector2f boardsize);
	~SmartEnemy() override = default;
	virtual void UpdateLocation(float)override;



private:

};