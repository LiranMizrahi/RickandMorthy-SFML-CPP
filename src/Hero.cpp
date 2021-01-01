#include "Hero.h"


Hero::Hero() :m_life(0), m_score(0)
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

void Hero::UpdateLocation(float time, int dir)
{
	switch (dir)
	{

	case 1://left
		this->move((-0.2f) * time ,0);
		break;

	case 2://right
		this->move((0.2f) * time, 0);
		break;

	case 3:

		break;

	case 4:

		break;

	}



}

void Hero::SetScore(int score)
{
	m_score = score;
}
