#include "Enemy.h"
#include "Macros.h"
Enemy::Enemy(const sf::Vector2f &loc, int EnemySelection,sf::Vector2f boardsize)
{
	if (EnemySelection == HEROASJERRY)
	{
        m_sprite.setTexture(SingletonPicture::instance().getEnemyMeeseeksTexture());
    }
	else if (EnemySelection == HEROASRICK)
	{
        m_sprite.setTexture(SingletonPicture::instance().getEnemyMonsterTexture());
    }

    m_sprite.setScale(sf::Vector2f(boardsize.x/(m_sprite.getTexture()->getSize().x+25) ,(boardsize.y/(m_sprite.getTexture()->getSize().y+25))));

    m_sprite.setPosition(loc);
    m_sprite.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize() / 2u));

	m_firstPosition = loc;
    m_diggedfloortime =sf::Time::Zero;
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

const sf::Time &Enemy::getDiggedfloortime() const {
    return m_diggedfloortime;
}

void Enemy::setDiggedfloortime(const sf::Time &diggedfloortime) {
    Enemy::m_diggedfloortime = diggedfloortime;
}

void Enemy::restoreGameObj(const sf::Time &time, float cellheight) {
    if(m_isingidedfloor)
    if(time.asMilliseconds()-m_diggedfloortime.asMilliseconds() >RESTOREFLOORTIME)
        this->move(0,-cellheight);

    m_isingidedfloor =false;
}

void Enemy::setIsingidedfloor(bool isingidedfloor) {
    m_isingidedfloor = isingidedfloor;
}

bool Enemy::isIsingidedfloor() const {
    return m_isingidedfloor;
}





