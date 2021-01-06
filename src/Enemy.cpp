#include "Enemy.h"

Enemy::Enemy(Picture& pic, const sf::Vector2f& loc, int EnemySelection)
{
	if (EnemySelection == 1)
	{
		auto hero = *pic.getEnemyMeeseeksTexture();
		m_sprite.setTexture(*pic.getEnemyMeeseeksTexture());
		m_sprite.setPosition(loc);
		m_sprite.setOrigin(sf::Vector2f(hero.getSize() / 2u));
	}
	else
	{
		auto hero = *pic.getEnemyMonsterTexture();
		m_sprite.setTexture(*pic.getEnemyMonsterTexture());
		m_sprite.setPosition(loc);
		m_sprite.setOrigin(sf::Vector2f(hero.getSize() / 2u));

	}
}

void Enemy::UpdateLocation(float time) {

    int RandomMov = std::rand() % 10;

    switch (RandomMov)
    {

        case LEFT:
            this->move(-ENEMYSPEED * time, 0);
            break;
        case RIGHT:
            this->move(ENEMYSPEED * time, 0);

            break;
        case UP:
            break;
        case DOWN:
            break;
    }

}
