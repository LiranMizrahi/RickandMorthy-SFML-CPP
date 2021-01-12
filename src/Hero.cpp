#include "Hero.h"
#include "Macros.h"
#include "Floor.h"
#include "Controller.h"
#include "Enemy.h"

Hero::Hero(const sf::Vector2f& loc, int HeroSelection) : m_life(3), m_score(123)
{


	if (HeroSelection == 1)
	{
		auto hero = *SingletonPicture::instance().getHerojerryTexture();
		m_sprite.setTexture(*SingletonPicture::instance().getHerojerryTexture());
		m_sprite.setPosition(loc);
		m_sprite.setOrigin(sf::Vector2f(hero.getSize() / 2u));
	}
	else
	{
		auto hero = *SingletonPicture::instance().getHeroRickTexture();
		m_sprite.setTexture(*SingletonPicture::instance().getHeroRickTexture());
		m_sprite.setPosition(loc);
		m_sprite.setOrigin(sf::Vector2f(hero.getSize() / 2u));
		
	}

	m_collectCoinSound.setBuffer(Sound::instance().getMCollectCoin());
    m_collectGiftSound.setBuffer(Sound::instance().getMCollectGift());
    m_collectDeadSound.setBuffer(Sound::instance().getMDead());

    m_LastPosition = loc;
}
//====================================================

int Hero::getLife()
{
	return m_life;
}
//====================================================

int Hero::getScore()
{
	return m_score;
}
//====================================================

void Hero::SetLife(int life)
{
	m_life = life;
}

//====================================================
void Hero::UpdateLocation(float time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
	    if(m_isUpAvail)
		this->move( 0,-HEROSPEED * time);
	}
	else
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
	    //    if (m_isDownAvail)
		            this->move(0,HEROSPEED * time);
	}
	else
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))

	{
		this->move(-HEROSPEED *time, 0);
		this->DrawLeftside();
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))

	{
		this->move(HEROSPEED *time, 0);
		this->DrawRightside();
	}


}
//====================================================
void Hero::handleColision(GameObj& obj)
{
	obj.handleColision(*this);
}
//====================================================
void Hero::handleColision(Rope& Obj) 
{
    m_isUpAvail =false;

}
//====================================================
void Hero::handleColision(Floor& obj)
{
    m_sprite.setPosition(m_LastPosition);
    m_isUpAvail =false;
   // this->m_sprite.setRotation(0.f);
}
//====================================================
void Hero::handleColision(Ladder& obj)
{
    m_isUpAvail =true;

}
//====================================================
void Hero::handleColision(Coin&obj)
{
	Coin::incCoins();
    m_isUpAvail =false;

	m_score+=50*Controller::getLevel();
	playCollectGiftSound();
	//obj.handleColision(*this);
}

void Hero::handleColision(Enemy& obj )
{
	m_life--;
}

//====================================================
void Hero::SetScore(int score)
{
	m_score = score;
}
//====================================================
void Hero::playCollectGiftSound() {
    m_collectGiftSound.play();

}
//====================================================
void Hero::playCollectCoinSound() {

    m_collectCoinSound.play();

}
//====================================================

void Hero::playCollectDeadSound() {

    m_collectDeadSound.play();

}
//====================================================

void Hero::handleColision(Hero &) {

}
//====================================================
