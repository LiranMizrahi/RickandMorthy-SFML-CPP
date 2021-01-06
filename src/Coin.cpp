#include "Coin.h"
#include "Coin.h"
#include "Picture.h"
Coin::Coin():m_isTaken(false)
{
}
//=============================================================
 Coin::Coin(Picture& pic, const sf::Vector2f& loc, const sf::Vector2f& size) :
	StaticObjects(*pic.getCoinTexture(), loc, size)
{
	m_isTaken = false;
}
//=============================================================

void Coin::handleColision(Hero&obj)
{
    m_isTaken = true;
	obj.handleColision(*this);
}
