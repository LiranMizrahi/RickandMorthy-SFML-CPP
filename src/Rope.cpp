#include "Rope.h"

Rope::Rope()
{
}
//=============================================================
Rope::Rope(const sf::Vector2f& loc, const sf::Vector2f& size): StaticObjects(*SingletonPicture::instance().getRopeTexture(), loc, size)

{
}
//=============================================================

void Rope::handleColision(Hero& obj)
{
	obj.handleColision(*this);
}

void Rope::handleColision(Enemy& obj)
{
	obj.handleColision(*this);

}


