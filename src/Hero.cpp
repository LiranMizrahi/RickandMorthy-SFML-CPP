#include "Hero.h"


Hero::Hero() :m_life(0), m_score(0), m_LastPosition(0, 0)
{

}


Hero::Hero(Picture& pic, const sf::Vector2f& loc, int HeroSelection) :m_life(3), m_score(0)
{


	if (HeroSelection == 1)
	{
		auto hero = *pic.GetHerojerryTexture();
		m_sprite.setTexture(*pic.GetHerojerryTexture());
		m_sprite.setPosition(loc);
		m_sprite.setOrigin(sf::Vector2f(hero.getSize() / 2u));
	}
	else
	{
		auto hero = *pic.GetHeroRickTexture();
		m_sprite.setTexture(*pic.GetHeroRickTexture());
		m_sprite.setPosition(loc);
		m_sprite.setOrigin(sf::Vector2f(hero.getSize() / 2u));

	}

	m_LastPosition = loc;
}

int Hero::GetLife()
{
	return m_life;
}

int Hero::GetScore()
{
	return m_score;
}

void Hero::SetLife(int life)
{
	m_life = life;
}

void Hero::UpdateLocation(float time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))

	{
		this->move(-HEROSPEED *time, 0);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))

	{
		this->move(HEROSPEED *time, 0);
	}


}

void Hero::SetScore(int score)
{
	m_score = score;
}
