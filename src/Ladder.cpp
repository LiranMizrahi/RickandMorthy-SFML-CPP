#include "Ladder.h"
#include "SingletonPicture.h"

Ladder::Ladder()
{
}

Ladder::Ladder(const sf::Vector2f& loc , const sf::Vector2f& size): StaticObjects(*SingletonPicture::instance().getLedderTexture(), loc, size)
{

}

void Ladder::handleColision(Hero& obj)
{
	obj.handleColision(*this);
}
