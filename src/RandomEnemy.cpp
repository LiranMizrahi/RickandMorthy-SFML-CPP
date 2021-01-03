#include "RandomEnemy.h"
#include "Macros.h"

void RandomEnemy::UpdateLocation(float time)
{
	int RandomMov = std::rand() % 4;

	switch (RandomMov)
	{
		
	case LEFT:
		this->move(-ENEMYSPEED * time, 0);
		break;
	case  RIGHT:
		this->move(ENEMYSPEED * time, 0);

		break;
	case UP:
		break;
	case DOWN:
		break;
	}
}
