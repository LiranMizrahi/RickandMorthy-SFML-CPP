#include "StaticObjects/Coin.h"
#include "Singletons/SingletonPicture.h"
#include "Macros.h"
//============ Set Up static variables =======================
size_t Coin:: m_allCoins = 0;
size_t Coin:: m_currentCoins = 0;

//=========================constructor ======================================
Coin::Coin(const sf::Vector2f &loc, const sf::Vector2f &size, int level) :
	StaticObjects(SingletonPicture::instance().getCoinTexture(), loc, size)
{
    m_value = level * COINVALUE;
	 m_allCoins++;
	 m_currentCoins++;
}
//==================== Getters and Setters ========================================
int Coin::getValue() const {
    return m_value;
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
//===================== Public function ====================


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
//============== static function ====================
void Coin::resetCoins()
{
    m_allCoins = 0;
    m_currentCoins = 0;
}
//=============================================================

void Coin::incCoins()
{
    m_currentCoins--;
}
