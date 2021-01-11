#include"HorizontalEnemy.h"

HorizontalEnemy::HorizontalEnemy(const sf::Vector2f& loc, int EnemySelection):Enemy(loc, EnemySelection)
{

}

void HorizontalEnemy::UpdateLocation(float time)
{
	
	switch (m_directionMovement)
	{
	case LEFT:
		this->move(-ENEMYSPEED * time, 0);
		break;
	case  RIGHT:
		this->move(ENEMYSPEED * time, 0);
		break;
	}
}

void HorizontalEnemy::handleColision(Floor& obj)
{
	if ( LEFT == m_directionMovement)
	{
		m_directionMovement = RIGHT;
	}
	else
	{
		m_directionMovement = LEFT;
	}

	
}
