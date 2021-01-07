#include "Coin.h"
#include "Coin.h"
#include "Picture.h"
Coin::Coin()
{
}
//=============================================================
 Coin::Coin(Picture& pic, const sf::Vector2f& loc, const sf::Vector2f& size) :
	StaticObjects(*pic.getCoinTexture(), loc, size)
{

}
//=============================================================

void Coin::handleColision(Hero&obj)
{
    m_isOff =true;
	obj.handleColision(*this);
}
