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

bool Floor::isObjectIsStandable(Enemy &enemy) {


    if((m_isOff &&this->getSprite().getPosition().y-enemy.getSprite().getPosition().y < 7) ||!m_isOff) {
            if((m_isOff)) {
                enemy.setIsingidedfloor(true);
                enemy.setDiggedfloortime(this->m_digtimestamp);
            }
        return true;
    }
    //if(!m_isOff &&this->getSprite().getPosition().y-enemy.getSprite().getPosition().y < 7)
   // enemy.getSprite().setPosition(enemy.getLocationbeforefalling());
   // if(this->getSprite().getPosition().y-enemy.getSprite().getPosition().y < 15)
    if(!m_isOff)return true;
    return false;
}
void Floor::resetObj()
{
    m_isOff = false;
}
bool Floor::isObjectIsStandable(Hero &) {
    if(m_isOff)return false;
    return true;
}

bool Floor::isObjectDigable(const sf::Time &time) {
    m_digtimestamp = time;
    return true;
}

void Floor::setIsOff(bool isoff) {
    m_isOff = isoff;

}

void Floor::restoreGameObj(const sf::Time &time, float cellheight) {
    if(time.asMilliseconds()-m_digtimestamp.asMilliseconds() >RESTOREFLOORTIME)
        m_isOff = false;
}

const sf::Time &Floor::getDigtimestamp() const {
    return m_digtimestamp;
}
