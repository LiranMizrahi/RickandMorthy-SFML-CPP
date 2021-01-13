#include"GiftAddingEnemy.h"

GiftAddingEnemy::GiftAddingEnemy(const sf::Vector2f& loc, const sf::Vector2f& size) : Gift(loc, size)
{
}

void GiftAddingEnemy::handleColision(Hero& Obj)
{
    if(m_isOff)
	Obj.handleColision(*this);
    m_isOff = true;
}
