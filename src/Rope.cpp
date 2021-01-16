#include "Rope.h"

Rope::Rope()
{
}
//=============================================================
Rope::Rope(const sf::Vector2f& loc, const sf::Vector2f& size): StaticObjects(SingletonPicture::instance().getRopeTexture(), loc, size)
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

void Rope::handleColision(GameObj &obj) {
    obj.handleColision(*this);
}

bool Rope::isObjectIsStandable(Hero & ) {
   return true ;//(movingobject.getSprite().getPosition().y-this->getSprite().getPosition().y > 15);

}
bool Rope::isObjectIsStandable(Enemy & ) {
    return true ;//(movingobject.getSprite().getPosition().y-this->getSprite().getPosition().y > 15);

}


bool Rope::isObjectDigable(const sf::Time &) {
    return false;
}



