#include "Enemy.h"
#include <time.h>

Enemy::Enemy( const sf::Vector2f& loc, int EnemySelection)
{
	if (EnemySelection == 1)
	{
		auto hero = *SingletonPicture::instance().getEnemyMeeseeksTexture();
		m_sprite.setTexture(*SingletonPicture::instance().getEnemyMeeseeksTexture());
		m_sprite.setPosition(loc);
		m_sprite.setOrigin(sf::Vector2f(hero.getSize() / 2u));
	}
	else
	{
		auto hero = *SingletonPicture::instance().getEnemyMonsterTexture();
		m_sprite.setTexture(*SingletonPicture::instance().getEnemyMonsterTexture());
		m_sprite.setPosition(loc);
		m_sprite.setOrigin(sf::Vector2f(hero.getSize() / 2u));

	}
}

void Enemy::UpdateLocation(float time1) {
	srand((unsigned int)time(NULL));
	int RandomMov = std::rand() % 3;


	switch (RandomMov)
	{

	case LEFT:
		this->move(-ENEMYSPEED * time1, 0);
		break;
	case RIGHT:
		this->move(ENEMYSPEED * time1, 0);

		break;
	case UP:
		break;
	case DOWN:
		break;
	}

}




