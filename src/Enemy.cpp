#include "Enemy.h"
#include "Macros.h"
Enemy::Enemy( const sf::Vector2f& loc, int EnemySelection)
{
	if (EnemySelection == HEROASJERRY)
	{
		auto hero = SingletonPicture::instance().getEnemyMeeseeksTexture();
		m_sprite.setTexture(SingletonPicture::instance().getEnemyMeeseeksTexture());
		m_sprite.setPosition(loc);
		m_sprite.setOrigin(sf::Vector2f(hero.getSize() / 2u));
	}
	else if (EnemySelection == HEROASRICK)
	{
		auto hero = SingletonPicture::instance().getEnemyMonsterTexture();
		m_sprite.setTexture(SingletonPicture::instance().getEnemyMonsterTexture());
		m_sprite.setPosition(loc);
		m_sprite.setOrigin(sf::Vector2f(hero.getSize() / 2u));

	}
	m_firstPosition = loc;

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

void Enemy::handleColision(GameObj &obj) {

    obj.handleColision(*this);

}

bool Enemy::isObjectIsStandable(StaticObjects &stas) {
    return stas.isObjectIsStandable(*this);
}

void Enemy::resetObj()
{
	this->SetPosition(m_firstPosition);
}

const sf::Vector2f &Enemy::getLocationbeforefalling() const {
    return m_locationbeforefalling;
}

void
Enemy::setLocationbeforefalling(const sf::Vector2f &mLocationbeforefalling) {
    m_locationbeforefalling = mLocationbeforefalling;
}



