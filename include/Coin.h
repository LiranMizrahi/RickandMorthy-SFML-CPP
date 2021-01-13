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
	virtual void handleColision(GameObj&) override;
	virtual void handleColision(Coin&) override {};
	virtual void handleColision(Enemy&) override {};
	virtual void handleColision(GiftAddingLife&) override {};
	virtual void handleColision(GiftAddingScore&) override {};
	virtual void handleColision(GiftAddingEnemy&) override {};
    virtual bool isObjectIsStandable(GameObj&)override;
	static size_t getNowCoins();
	static void incCoins();
private:
	
	static size_t m_allCoins;
	static size_t m_currentCoins;
};