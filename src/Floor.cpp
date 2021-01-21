#include "Floor.h"
#include "SingletonPicture.h"
#include <cmath>


Floor::Floor(const sf::Vector2f& loc, const sf::Vector2f& size): StaticObjects(SingletonPicture::instance().getFloorTexture(), loc, size)
{
    m_isfull = false;
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


    if(((m_isOff &&this->getSprite().getPosition().y-enemy.getSprite().getPosition().y < 3)&&
            ( std::abs(this->getSprite().getPosition().x-enemy.getSprite().getPosition().x) < (this->getSprite().getGlobalBounds().width/2)))
    ||!m_isOff) {
            if((m_isOff)) {
                m_isfull =true;
                enemy.setIsingidedfloor(true);
                enemy.setDiggedfloortime(this->m_digtimestamp);
            }
        return true;
    }

    if(!m_isOff)return true;

    return false;
}
void Floor::resetObj()
{
    m_digtimestamp = sf::Time::Zero;
    m_isOff = false;
    m_isfull = false;
}
bool Floor::isObjectIsStandable(Hero &) {
    if(m_isOff && m_isfull)
          return true;
    else if(m_isOff)
        return false;

    return true;
}

bool Floor::isObjectDigable(const sf::Time &time) {
    m_digtimestamp = time;
    return true;
}

void Floor::setIsOff(bool isoff) {
    m_isOff = isoff;
    m_isfull = false;

}

bool Floor::restoreGameObj(const sf::Time &time, float cellheight)
{
    if(m_isOff)

        if (time.asMilliseconds() - m_digtimestamp.asMilliseconds() > RESTOREFLOORTIME)
         {
            m_isOff = false;
            m_isfull = false;
            return true;
          }

    return false;
}
