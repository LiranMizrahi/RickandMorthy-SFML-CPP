#include "RandomEnemy.h"
#include "Macros.h"
#include <time.h>


RandomEnemy::RandomEnemy(const sf::Vector2f& loc, int EnemySelection) :Enemy(loc, EnemySelection)
{
}

void RandomEnemy::UpdateLocation(float time1)
{
	srand((unsigned int)time(NULL));

	int RandomMov = std::rand() % 4;

	switch (RandomMov)
	{
		
	case LEFT:
		this->move(-ENEMYSPEED * time1, 0);
		break;
	case  RIGHT:
		this->move(ENEMYSPEED * time1, 0);

		break;
	case UP:
		break;
	case DOWN:
		break;
	}
}



