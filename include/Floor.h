#pragma once
#include "StaticObjects.h"
class Picture;
#include <SFML/Graphics.hpp>
#include<Hero.h>
class Floor : public StaticObjects {

public:
	Floor() ;
	Floor(Picture&, const sf::Vector2f& loc, const sf::Vector2f&);
    virtual ~Floor() {};

	virtual void handleColision(Rope& )override  {};
	virtual void handleColision(Hero& )override ;
	virtual void handleColision(Floor& ) override {};
	virtual void handleColision(Ladder& ) override {};
	virtual void handleColision(GameObj& ) override {};
	virtual void handleColision(Coin&) override {};



};