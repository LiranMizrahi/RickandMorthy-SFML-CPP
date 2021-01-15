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

bool Gift::isObjectDigable() {
    return false;
}


