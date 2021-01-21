#include"GiftAddingLife.h"

//=========================constructor ======================================
GiftAddingLife::GiftAddingLife(const sf::Vector2f& loc, const sf::Vector2f& size) : Gift(loc, size)
{
}
//=============================================================

void GiftAddingLife::handleColision(GameObj& obj)
{
    obj.handleColision(*this);
}
//=============================================================
void GiftAddingLife::handleColision(Hero& obj)
{
    if(!m_isOff)
        obj.handleColision(*this);
    m_isOff = true;
    m_isreedem = true;
}

