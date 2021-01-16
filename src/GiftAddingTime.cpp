#pragma once
#include "GiftAddingTime.h"


int GiftAddingTime::m_numberofgiftaddingtime = 0;

GiftAddingTime::GiftAddingTime(const sf::Vector2f& loc, const sf::Vector2f& size) : Gift(loc, size)
{

}

void GiftAddingTime::handleColision(GameObj& obj)
{
    obj.handleColision(*this);
}

void GiftAddingTime::handleColision(Hero& obj)
{
    m_numberofgiftaddingtime++;
    if(!m_isOff)
        obj.handleColision(*this);
    m_isOff = true;
    m_isreedem = true;
}

GiftAddingTime::~GiftAddingTime() {

}

int GiftAddingTime::getNumberofgiftaddingtime() {
    return m_numberofgiftaddingtime;
}

void GiftAddingTime::redeenGift() {
    m_numberofgiftaddingtime--;

}

