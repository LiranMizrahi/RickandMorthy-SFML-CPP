#pragma once
#include "GameObj.h"


class MovingObjects : public GameObj
{
public:

	MovingObjects();
	~MovingObjects() override = default;
	MovingObjects(const sf::Texture& tex, const sf::Vector2f& loc, const sf::Vector2f&);
	void move(float,float);
	sf::Vector2f GetPosition()const;
	void SetPosition(const sf::Vector2f&);
	void DrawLeftside();
	void DrawRightside();


};