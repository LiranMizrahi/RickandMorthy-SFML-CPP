#include "Enemy.h"

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

void Enemy::handleColision(Rope& Obj)
{
	m_isUpAvail = false;

}

void Enemy::handleColision(Hero& obj)
{
	obj.handleColision(*this);
}

void Enemy::handleColision(Floor& obj)
{
	m_sprite.setPosition(m_LastPosition);
	m_isUpAvail = false;
}

void Enemy::handleColision(Ladder& obj)
{
	m_isUpAvail = true;

}




