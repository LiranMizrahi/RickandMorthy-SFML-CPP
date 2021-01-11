#include "Present.h"
#include "SingletonPicture.h"
#include "Coin.h"


Present::Present(const sf::Vector2f& loc, const sf::Vector2f& size):
	StaticObjects(*SingletonPicture::instance().getCoinTexture(), loc, size)
{

}


