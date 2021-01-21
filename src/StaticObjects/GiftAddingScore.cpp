#include"StaticObjects/GiftAddingScore.h"
//=========================constructor ======================================
GiftAddingScore::GiftAddingScore(const sf::Vector2f& loc, const sf::Vector2f& size) : Gift(loc, size)
{

}
//=============================================================

void GiftAddingScore::handleColision(GameObj& obj)
{
    obj.handleColision(*this);
}
//=============================================================

void GiftAddingScore::handleColision(Hero& obj)
{
    if(!m_isOff)
        obj.handleColision(*this);
    m_isOff = true;
    m_isreedem = true;
}
//=============================================================


