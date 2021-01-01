#include "Hero.h"


Hero::Hero() :m_life(0), m_score(0)
{

}


Hero::Hero( Picture & pic, const sf::Vector2f& loc) :MovingObjects(*pic.GetHeroTexture(),loc) ,m_life(3), m_score(0)
{

//	m_sprite.setTexture(*tex);
	//m_sprite.setPosition(loc);
//	
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
