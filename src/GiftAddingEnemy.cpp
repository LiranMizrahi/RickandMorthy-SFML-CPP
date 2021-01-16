#include"GiftAddingEnemy.h"

int GiftAddingEnemy::m_numberofgiftaddingenemy = 0;
GiftAddingEnemy::GiftAddingEnemy(const sf::Vector2f& loc, const sf::Vector2f& size) : Gift(loc, size)
{

}

void GiftAddingEnemy::handleColision(GameObj& obj)
{
    obj.handleColision(*this);
}

void GiftAddingEnemy::handleColision(Hero& Obj)
{
    m_numberofgiftaddingenemy++;
    if(m_isOff)
	Obj.handleColision(*this);
    m_isOff = true;
}

GiftAddingEnemy::~GiftAddingEnemy() {
    //m_numberofgiftaddingenemy--;

}

int GiftAddingEnemy::getNumberOfGiftAddingRnemy() {
    return m_numberofgiftaddingenemy;
}

void GiftAddingEnemy::redeemGift() {
    m_numberofgiftaddingenemy--;

}
