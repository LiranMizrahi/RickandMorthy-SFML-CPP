#include "Coin.h"
#include "SingletonPicture.h"
Coin::Coin()
{
}
//=============================================================
 Coin::Coin(const sf::Vector2f& loc, const sf::Vector2f& size) :
	StaticObjects(*SingletonPicture::instance().getCoinTexture(), loc, size)
{

}
//=============================================================

void Coin::handleColision(Hero&obj)
{


    if(!m_isOff)
	obj.handleColision(*this);
    m_isOff =true;
}
