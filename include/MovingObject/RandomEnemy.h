#pragma once

#include"MovingObject/Enemy.h"

class RandomEnemy : public Enemy
{
public:
	RandomEnemy() = default;
	RandomEnemy(const sf::Vector2f &loc, int EnemySelection,
                const sf::Vector2f &boardsize);
    ~RandomEnemy()override = default;
	//===================public function=================
	void UpdateLocation(float , sf::Vector2f, const  std::vector <std::vector<char>>&, Board&)override;

private:

};

