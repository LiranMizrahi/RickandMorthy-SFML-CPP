#include "RandomEnemy.h"
#include "Macros.h"

void RandomEnemy::UpdateLocation(float time)
{
	int RandomMov = std::rand() % 4;

	switch (RandomMov)
	{
		
	LEFT:
		this->move(-ENEMYSPEED * time, 0);
		break;
	RIGHT:
		this->move(ENEMYSPEED * time, 0);

		break;
	UP:
		break;
	DOWN:
		break;
	}
}
