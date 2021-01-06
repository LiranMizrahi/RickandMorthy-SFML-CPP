#include "Floor.h"
#include "Picture.h"
Floor::Floor()
{
}
Floor::Floor( Picture& pic, const sf::Vector2f& loc, const sf::Vector2f& size):StaticObjects(*pic.getFloorTexture(), loc, size)
{

}

void Floor::handleColision(Hero&obj)
{
	obj.handleColision(*this);
}
