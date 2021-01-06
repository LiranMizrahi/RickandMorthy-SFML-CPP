#include "StaticObjects.h"

StaticObjects::StaticObjects()
{
}
//=============================================================
StaticObjects::StaticObjects(sf::Texture& tex, const sf::Vector2f& loc, const sf::Vector2f& size) : GameObj(tex, loc,size)
{
}
