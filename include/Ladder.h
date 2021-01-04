#pragma once
#include"Hero.h"
#include "StaticObjects.h"
class Picture;
#include <SFML/Graphics.hpp>
class Ladder : public StaticObjects {

public:
	Ladder();
	Ladder(Picture&, const sf::Vector2f& loc, const sf::Vector2f&);

	virtual void handleColision(Rope& )override {};

	virtual void handleColision(Hero&)override;
	virtual void handleColision(Floor&) override {};
	virtual void handleColision(Ladder&) override {};
	virtual void handleColision(GameObj&)override {};
	virtual void handleColision(Coin&) override {};


};