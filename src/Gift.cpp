#include "Gift.h"
#include "SingletonPicture.h"
#include "Coin.h"
#include "Macros.h"
//=========================constructor ======================================
Gift::Gift(const sf::Vector2f& loc, const sf::Vector2f& size):
	StaticObjects(SingletonPicture::instance().getGiftTexture(), loc, size)
{
    m_isOff = true;
    m_showTime = sf::milliseconds(rand()% GIFTSHOWTIME + 1000 );
}
//=============================================================

bool Gift::isObjectIsStandable(Hero &) {
    return false;
}
//=============================================================

bool Gift::isObjectIsStandable(Enemy &) {
    return false;
}
//=============================================================

bool Gift::isObjectDigable(const sf::Time &) {
    return false;
}

//=============================================================

//void Gift::handleColision(Hero &obj) {
//    if(!m_isOff)
//        obj.handleColision(*this);
//    m_isOff = true;
//    m_isreedem = true;
//
//}
////=============================================================
//
//void Gift::handleColision(GameObj &obj) {
//    obj.handleColision(*this);
//}
//=============================================================


bool Gift::restoreGameObj(const sf::Time &time, float cellheight) {
    if(!m_isreedem)
    if(time.asMilliseconds()-m_showTime.asMilliseconds()>0)
        m_isOff = false;
    return false;
}
//=============================================================
