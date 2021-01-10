#include "MovingObjects.h"
#include "Macros.h"
MovingObjects::MovingObjects()
{
}
//=============================================================

MovingObjects::MovingObjects(const sf::Texture& tex, const sf::Vector2f& loc, const sf::Vector2f& size) :GameObj(tex, loc,size)
{

}
//=============================================================

void MovingObjects::move(float xline,float yline)
{

    sf::Vector2f loc = this->m_LastPosition;
    m_LastPosition = m_sprite.getPosition();
	m_sprite.move(xline,yline);
	if (m_sprite.getPosition().x+(m_sprite.getGlobalBounds().width/2) > BOARDWIDTH ||
            m_sprite.getPosition().y+(m_sprite.getGlobalBounds().height/2) > BOARDHEIGHT
            ||m_sprite.getPosition().x -(m_sprite.getGlobalBounds().width/2) < 0
            ||m_sprite.getPosition().y-(m_sprite.getGlobalBounds().height/2) < 0)
	{

        m_sprite.setPosition(m_LastPosition);
       // m_LastPosition =loc;
    }
}
//=============================================================

sf::Vector2f MovingObjects::GetPosition() const
{
	return m_sprite.getPosition();
}
//=============================================================

void MovingObjects::SetPosition(const sf::Vector2f& pos)
{
	m_sprite.setPosition(pos);
}
//=============================================================

void MovingObjects::DrawLeftside()
{
	if(m_sprite.getScale().x <= 0)
	
	m_sprite.scale(-1.f, 1.f);

}
//=============================================================

void MovingObjects::DrawRightside()
{

	if (m_sprite.getScale().x > 0)

		m_sprite.scale(-1.f, 1.f);
}

const sf::Vector2f &MovingObjects::getLastPosition() const {
    return m_LastPosition;
}

bool MovingObjects::getIsfalling() const {
    return m_isfalling;
}
//=============================================================

void MovingObjects::setIsfalling(bool isfalling) {
    m_isfalling = isfalling;
}
//=============================================================
