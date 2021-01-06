#include "MovingObjects.h"

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
	m_sprite.move(xline,yline);
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
//=============================================================
