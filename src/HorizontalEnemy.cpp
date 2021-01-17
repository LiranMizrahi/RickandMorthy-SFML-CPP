#include"HorizontalEnemy.h"

HorizontalEnemy::HorizontalEnemy(const sf::Vector2f &loc,
                                 int EnemySelection,
                                 const sf::Vector2f &boardsize) : Enemy(
								 loc, EnemySelection, boardsize)
{

}

void HorizontalEnemy::UpdateLocation(float time)
{
	
	switch (m_directionMovement)
	{
	case LEFT:
		this->move(-ENEMYSPEED * time, 0);
		this->DrawLeftside();
		break;
	case  RIGHT:
		this->move(ENEMYSPEED * time, 0);
		this->DrawRightside();
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

void HorizontalEnemy::move(float xline, float yline)
{
	sf::Vector2f loc = this->m_LastPosition;
	m_LastPosition = m_sprite.getPosition();
	m_sprite.move(xline, yline);
	if (m_sprite.getPosition().x + (m_sprite.getGlobalBounds().width / 2) > BOARDWIDTH ||
		m_sprite.getPosition().y + (m_sprite.getGlobalBounds().height / 2) > BOARDHEIGHT
		|| m_sprite.getPosition().x - (m_sprite.getGlobalBounds().width / 2) < 0
		|| m_sprite.getPosition().y - (m_sprite.getGlobalBounds().height / 2) < 0)
	{

		m_sprite.setPosition(m_LastPosition);
		if (LEFT == m_directionMovement)
		{
			m_directionMovement = RIGHT;
		}
		else
		{
			m_directionMovement = LEFT;
		}
	}
}

