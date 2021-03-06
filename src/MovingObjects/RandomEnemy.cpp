#include "MovingObject/RandomEnemy.h"
#include "Macros.h"
#include <ctime>

//=========================constructor ======================================

RandomEnemy::RandomEnemy(const sf::Vector2f &loc,int EnemySelection,const sf::Vector2f &boardsize) : Enemy(
						 loc, EnemySelection, boardsize)
{

}
//=============================================================

void RandomEnemy::UpdateLocation(float timeGame, sf::Vector2f, const  std::vector <std::vector<char>>&, Board&)
{
    if(isIsingidedfloor())return;
    std::srand(std::time(0));

	auto RandomMov = std::rand() % 4;

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



