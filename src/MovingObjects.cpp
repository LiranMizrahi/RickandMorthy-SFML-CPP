#include "MovingObjects.h"

MovingObjects::MovingObjects()
{
}

MovingObjects::MovingObjects(const sf::Texture& tex, const sf::Vector2f& loc) :GameObj(tex, loc)
{
}

void MovingObjects::move(float xline,float yline)
{
	m_sprite.move(xline,yline);
}

//void MovingObjects::handleColision(Floor& obj)
//{
//	//
//}
