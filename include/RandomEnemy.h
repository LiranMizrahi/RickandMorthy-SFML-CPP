#pragma once

#include"Enemy.h"

class RandomEnemy : public Enemy
{
public:
	RandomEnemy(const sf::Vector2f &loc, int EnemySelection,
                const sf::Vector2f &boardsize);
    ~RandomEnemy()override = default;
	virtual void UpdateLocation(float , sf::Vector2f, const  std::vector <std::vector<char>>&, Board&)override;

private:

};

