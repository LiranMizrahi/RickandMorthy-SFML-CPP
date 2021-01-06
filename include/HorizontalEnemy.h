#pragma once
#include"Enemy.h"

class HorizontalEnemy: public Enemy
{
    ~HorizontalEnemy() override= default;
public:
	virtual void UpdateLocation(float);

private:

};

