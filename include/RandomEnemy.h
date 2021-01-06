#pragma once

#include"Enemy.h"

class RandomEnemy : public Enemy
{
public:
    ~RandomEnemy()override = default;
	virtual void UpdateLocation(float);

private:

};

