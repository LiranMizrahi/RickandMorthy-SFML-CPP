#include "Gift.h"
#include "SingletonPicture.h"
#include "Coin.h"


Gift::Gift(const sf::Vector2f& loc, const sf::Vector2f& size):
	StaticObjects(SingletonPicture::instance().getGiftTexture(), loc, size)
{

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

}

void Gift::handleColision(GameObj &obj) {
    obj.handleColision(*this);
}



