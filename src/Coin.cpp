#include "Coin.h"
#include "SingletonPicture.h"
//=============================================================

size_t Coin:: m_allCoins = 0;
size_t Coin:: m_currentCoins = 0;

//=============================================================


Coin::Coin()
{
}
//=============================================================
 Coin::Coin(const sf::Vector2f& loc, const sf::Vector2f& size) :
	StaticObjects(SingletonPicture::instance().getCoinTexture(), loc, size)
{
	 m_allCoins++;
	 m_currentCoins++;
}
 //Coin::~Coin()
 //{
	// m_allCoins = 0;
	// m_currentCoins = 0;
 //}
//=============================================================

void Coin::handleColision(Hero&obj)
{

    if(!m_isOff) {
        obj.handleColision(*this);
        m_currentCoins--;
    }
    m_isOff =true;
}
//=============================================================

void Coin::handleColision(GameObj &obj) {
   // if(&obj == this)return;
    obj.handleColision(*this);
}
//=============================================================

size_t Coin::getNowCoins() 
{
	if (0 == m_currentCoins)
	{
		m_allCoins = 0;
	}
	return m_currentCoins;
}
//=============================================================

void Coin::incCoins()
{
	m_currentCoins--;
}

bool Coin::isObjectIsStandable(GameObj & obj) {
    return false;
}

bool Coin::isObjectDigable() {
    return false;
}
//=============================================================

