#include"GiftAddingEnemy.h"

int GiftAddingEnemy::m_numberofgiftaddingenemy = 0;
GiftAddingEnemy::GiftAddingEnemy(const sf::Vector2f& loc, const sf::Vector2f& size) : Gift(loc, size)
{

}

void GiftAddingEnemy::handleColision(GameObj& obj)
{
    obj.handleColision(*this);
}

void GiftAddingEnemy::handleColision(Hero& obj)
{
    m_numberofgiftaddingenemy++;
    if(!m_isOff)
        obj.handleColision(*this);
    m_isOff = true;
    m_isreedem = true;
}


int GiftAddingEnemy::getNumberOfGiftAddingRnemy() {
    return m_numberofgiftaddingenemy;
}

void GiftAddingEnemy::redeemGift() {
    m_numberofgiftaddingenemy--;

}
