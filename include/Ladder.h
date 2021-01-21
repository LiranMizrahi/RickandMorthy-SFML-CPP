#pragma once
#include"Hero.h"
#include"Enemy.h"
#include "StaticObjects.h"
class SingletonPicture;
#include <SFML/Graphics.hpp>
class Ladder : public StaticObjects {

public:
	Ladder() = default;
	Ladder(const sf::Vector2f& loc, const sf::Vector2f&);
    ~Ladder() override= default;
	//===================public function=================
    void handleColision(Rope& )override {};
    void handleColision(Hero&)override;
	void handleColision(Floor&) override {};
	void handleColision(Ladder&) override {};
	void handleColision(GameObj&)override;
	void handleColision(Coin&) override {};
	void handleColision(Enemy&) override;
	void handleColision(GiftAddingLife&) override {};
	void handleColision(GiftAddingScore&) override {};
	void handleColision(GiftAddingEnemy&) override {};
	void handleColision(GiftAddingTime&) override {};
    bool isObjectIsStandable(Enemy&)override;
    bool isObjectIsStandable(Hero&)override;
    bool isObjectDigable(const sf::Time &) override;
	void resetObj()override {};

};