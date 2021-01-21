#include "Coin.h"
#include "SingletonPicture.h"
#include "Macros.h"
//=============================================================
size_t Coin:: m_allCoins = 0;
size_t Coin:: m_currentCoins = 0;

//=============================================================
Coin::Coin():m_value(0)
{
}
//=============================================================
Coin::Coin(const sf::Vector2f &loc, const sf::Vector2f &size, int level) :
	StaticObjects(SingletonPicture::instance().getCoinTexture(), loc, size)
{
    m_value = level * COINVALUE;
	 m_allCoins++;
	 m_currentCoins++;
}
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
void Coin::resetObj()
{
	m_isOff = false;
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
void Coin::resetCoins()
{
	m_allCoins = 0;
	m_currentCoins = 0;
}
//=============================================================
bool Coin::isObjectIsStandable(Hero & obj) {
    return false;
}

//=============================================================

bool Coin::isObjectIsStandable(Enemy & obj) {
    return false;
}



//=============================================================
bool Coin::isObjectDigable(const sf::Time&) {
    return false;
}
//=============================================================
void Coin::CoinInitialization()
{
	m_currentCoins = m_allCoins;
}

int Coin::getValue() const {
    return m_value;
}
//=============================================================

