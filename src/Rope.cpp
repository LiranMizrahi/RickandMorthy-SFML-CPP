#include "Rope.h"

Rope::Rope()
{
}
//=============================================================
Rope::Rope(Picture& pic, const sf::Vector2f& loc, const sf::Vector2f& size):StaticObjects(*pic.getRopeTexture(), loc, size)

{
}
//=============================================================

void Rope::handleColision(Hero& obj)
{
	obj.handleColision(*this);
}
