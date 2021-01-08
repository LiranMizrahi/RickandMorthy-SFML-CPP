#pragma once

#include "StaticObjects.h"
class SingletonPicture;
#include <SFML/Graphics.hpp>
#include<Hero.h>
class Rope : public StaticObjects {

public:
	Rope();
	Rope(const sf::Vector2f& loc, const sf::Vector2f&);
	~Rope () override = default;

	virtual void handleColision(Rope&) override {};
	virtual void handleColision(Hero&) override;
	virtual void handleColision(Floor&) override {};
	virtual void handleColision(Ladder&) override {};
	virtual void handleColision(GameObj&) override {};
	virtual void handleColision(Coin&) override {};



};