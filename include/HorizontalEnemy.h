#pragma once
#include"Enemy.h"

class HorizontalEnemy: public Enemy
{
public:
	HorizontalEnemy(const sf::Vector2f& loc, int EnemySelection);
	virtual void UpdateLocation(float);
	~HorizontalEnemy() override = default;

	/*virtual void handleColision(GameObj& obj) override {};
	virtual void handleColision(Rope& Obj) override {};
	virtual void handleColision(Hero& Obj) override {};*/
	virtual void handleColision(Floor& obj)override ;
	/*virtual void handleColision(Ladder& obj) override {};
	virtual void handleColision(Coin&) override {};*/

private:
	int m_directionMovement = 1;

};

