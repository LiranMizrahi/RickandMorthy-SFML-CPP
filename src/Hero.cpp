#include "Hero.h"


Hero::Hero() :m_life(0), m_score(0)
{

}


Hero::Hero(const sf::Texture* tex, const sf::Vector2f& loc) :m_life(3), m_score(0)
{
	m_sprite.setTexture(*tex);
	m_sprite.setPosition(loc);
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

void Hero::SetScore(int score)
{
	m_score = score;
}
