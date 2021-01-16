#include "Gift.h"
#include "SingletonPicture.h"
#include "Coin.h"
#include "Macros.h"

Gift::Gift(const sf::Vector2f& loc, const sf::Vector2f& size):
	StaticObjects(SingletonPicture::instance().getGiftTexture(), loc, size)
{
    m_isOff = true;
    m_showTime = sf::milliseconds(rand()% GIFTSHOWTIME + 1000 );
}

bool Gift::isObjectIsStandable(GameObj &) {
    return false;
}

bool Gift::isObjectDigable(const sf::Time &) {
    return false;
}


void Gift::handleColision(Hero &obj) {
    if(!m_isOff)
        obj.handleColision(*this);
    m_isOff = true;
    m_isreedem = true;

}

void Gift::handleColision(GameObj &obj) {
    obj.handleColision(*this);
}


void Gift::restoreGameObj(const sf::Time & time) {
    if(!m_isreedem)
    if(time.asMilliseconds()-m_showTime.asMilliseconds()>0)
        m_isOff = false;
}
