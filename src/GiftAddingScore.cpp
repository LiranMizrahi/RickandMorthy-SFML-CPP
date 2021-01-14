#include"GiftAddingScore.h"

GiftAddingScore::GiftAddingScore(const sf::Vector2f& loc, const sf::Vector2f& size) : Gift(loc, size)
{
}

void GiftAddingScore::handleColision(GameObj& obj)
{
    obj.handleColision(*this);
}

void GiftAddingScore::handleColision(Hero& Obj)
{
    if(!m_isOff)
        Obj.handleColision(*this);
    m_isOff = true;
}


