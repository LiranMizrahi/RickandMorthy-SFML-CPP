#pragma once
#include"MovingObject/Enemy.h"

class HorizontalEnemy: public Enemy
{
public:
	HorizontalEnemy() = default;
	HorizontalEnemy(const sf::Vector2f &loc, int EnemySelection, const sf::Vector2f &boardsize);
	~HorizontalEnemy() override = default;
	//=========public function ======================
	void UpdateLocation(float, sf::Vector2f, const  std::vector <std::vector<char>>&, Board&)override;
	void handleColision(Floor& obj)override ;
	void move(float, float)override;

private:
	int m_directionMovement = LEFT;

};

