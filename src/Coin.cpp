#include "Coin.h"
#include "Picture.h"
Coin::Coin()
{
}

Coin::Coin(Picture& pic, const sf::Vector2f& loc, const sf::Vector2f& size) : 
	StaticObjects(*pic.GetCoinTexture(), loc, size)
{
	m_isTaken = false;

}