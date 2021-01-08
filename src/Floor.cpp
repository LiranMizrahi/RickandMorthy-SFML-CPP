#include "Floor.h"
#include "SingletonPicture.h"
Floor::Floor()
{
}
Floor::Floor(const sf::Vector2f& loc, const sf::Vector2f& size): StaticObjects(*SingletonPicture::instance().getFloorTexture(), loc, size)
{

}

void Floor::handleColision(Hero&obj)
{
	obj.handleColision(*this);
}
