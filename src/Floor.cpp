#include "Floor.h"
#include "SingletonPicture.h"
Floor::Floor()
{
}
Floor::Floor(const sf::Vector2f& loc, const sf::Vector2f& size): StaticObjects(SingletonPicture::instance().getFloorTexture(), loc, size)
{

}

void Floor::handleColision(Hero&obj)
{
	obj.handleColision(*this);
}

void Floor::handleColision(Enemy& obj)
{
	obj.handleColision(*this);

}

void Floor::handleColision(GameObj &obj) {
    obj.handleColision(*this);

}

bool Floor::isObjectIsStandable(GameObj &) {
    return true;
}

bool Floor::isObjectDigable(const sf::Time &time) {
    m_digtimestamp = time;
    return true;
}

void Floor::setIsOff(bool isoff) {
    m_isOff = isoff;

}
