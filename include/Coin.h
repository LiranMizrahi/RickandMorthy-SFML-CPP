#pragma once

#include "StaticObjects.h"
#include <SFML/Graphics.hpp>
#include "Hero.h"
class SingletonPicture;


class Coin : public StaticObjects {

public:
	Coin();
	Coin(const sf::Vector2f& loc, const sf::Vector2f&);
     ~Coin() override = default;
    virtual void handleColision(Rope&) override {};
	virtual void handleColision(Hero&) override;
	virtual void handleColision(Floor&) override {};
	virtual void handleColision(Ladder&) override {};
	virtual void handleColision(GameObj&) override{};
	virtual void handleColision(Coin&) override {};

private:
	;

};