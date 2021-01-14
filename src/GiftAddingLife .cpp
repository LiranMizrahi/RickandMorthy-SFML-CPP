#include"GiftAddingLife.h"


GiftAddingLife::GiftAddingLife(const sf::Vector2f& loc, const sf::Vector2f& size) : Gift(loc, size)
{
}

void GiftAddingLife::handleColision(GameObj& obj)
{
    obj.handleColision(*this);
}

void GiftAddingLife::handleColision(Hero& Obj)
{
    if(!m_isOff)
        Obj.handleColision(*this);
    m_isOff = true;
}

