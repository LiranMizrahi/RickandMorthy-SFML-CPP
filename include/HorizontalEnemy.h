#pragma once
#include"Enemy.h"

class HorizontalEnemy: public Enemy
{
public:
	HorizontalEnemy(const sf::Vector2f &loc,
                    int EnemySelection,
                    const sf::Vector2f &boardsize);
	virtual void UpdateLocation(float , sf::Vector2f, const  std::vector <std::vector<char>>&, Board&)override;
	~HorizontalEnemy() override = default;

	virtual void handleColision(Floor& obj)override ;
	virtual void move(float, float)override;

private:
	int m_directionMovement = 1;

};

