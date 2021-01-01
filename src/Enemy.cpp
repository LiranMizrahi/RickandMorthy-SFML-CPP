#include "Enemy.h"

Enemy::Enemy(Picture& pic, const sf::Vector2f& loc, int EnemySelection)
{
	if (EnemySelection == 1)
	{
		auto hero = *pic.GetEnemyMeeseeksTexture();
		m_sprite.setTexture(*pic.GetEnemyMeeseeksTexture());
		m_sprite.setPosition(loc);
		m_sprite.setOrigin(sf::Vector2f(hero.getSize() / 2u));
	}
	else
	{
		auto hero = *pic.GetEnemyMonsterTexture();
		m_sprite.setTexture(*pic.GetEnemyMonsterTexture());
		m_sprite.setPosition(loc);
		m_sprite.setOrigin(sf::Vector2f(hero.getSize() / 2u));

	}
}
