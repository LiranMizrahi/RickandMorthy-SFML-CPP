#include "RandomEnemy.h"
#include "Macros.h"
#include <ctime>


RandomEnemy::RandomEnemy(const sf::Vector2f &loc,
					     int EnemySelection,
                         const sf::Vector2f &boardsize) : Enemy(
						 loc, EnemySelection, boardsize)
{

}

void RandomEnemy::UpdateLocation(float timeGame)
{
	std::srand(std::time(nullptr));

	int RandomMov = std::rand() % 4;
	std::cout << RandomMov << "";
	switch (RandomMov)
	{
		
	case LEFT:
		this->move(-ENEMYSPEED * timeGame, 0);
		this->DrawLeftside();
		break;
	case  RIGHT:
		this->move(ENEMYSPEED * timeGame, 0);
		this->DrawRightside();
		break;
	case UP:
		if (m_isUpAvail)
			this->move(0, -HEROSPEED * timeGame);
		break;
	case DOWN:
		this->move(0, HEROSPEED * timeGame);
		break;
	}
}



