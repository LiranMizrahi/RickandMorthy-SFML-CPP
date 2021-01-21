#pragma once

#include "StaticObjects.h"
#include <SFML/Graphics.hpp>
#include<Hero.h>
#include<Enemy.h>

class SingletonPicture;

class Rope : public StaticObjects {

public:
	Rope() = default;
	Rope(const sf::Vector2f& loc, const sf::Vector2f&);
	~Rope () override = default;
	//===================public function=================
	void handleColision(Rope&) override {};
	void handleColision(Hero&) override;
	void handleColision(Floor&) override {};
	void handleColision(Ladder&) override {};
	void handleColision(GameObj&) override;
	void handleColision(Coin&) override {};
	void handleColision(Enemy& )override;
	void handleColision(GiftAddingLife&) override {};
	void handleColision(GiftAddingScore&) override {};
	void handleColision(GiftAddingEnemy&) override {};
	void handleColision(GiftAddingTime&) override {};
    bool isObjectIsStandable(Enemy&)override;
    bool isObjectIsStandable(Hero&)override;
    bool isObjectDigable(const sf::Time &) override;
	void resetObj()override {};

};