#pragma once

#include "StaticObjects/StaticObjects.h"
#include <SFML/Graphics.hpp>
#include "MovingObject/Hero.h"
class SingletonPicture;


class Coin : public StaticObjects {

public:
	Coin() = default;
	Coin(const sf::Vector2f &loc, const sf::Vector2f &size, int level);
	virtual ~Coin() = default;
	//===================public function=================
	int getValue() const;
	void handleColision(Rope&) override {};
	void handleColision(Hero&) override;
	void handleColision(Floor&) override {};
	void handleColision(Ladder&) override {};
	void handleColision(GameObj&) override;
	void handleColision(Coin&) override {};
	void handleColision(Enemy&) override {};
	void handleColision(GiftAddingLife&) override {};
	void handleColision(GiftAddingScore&) override {};
	void handleColision(GiftAddingEnemy&) override {};
	void resetObj()override;
	bool isObjectIsStandable(Hero&)override;
	bool isObjectDigable(const sf::Time&) override;
	bool isObjectIsStandable(Enemy&)override;
	void handleColision(GiftAddingTime&) override {};
	//===================static function=================
	static size_t getNowCoins();
	static void CoinInitialization();
	static void incCoins();
	static void resetCoins();
private:
	//===================private members=================
	int m_value;
	//===================static members=================
	static size_t m_allCoins;
	static size_t m_currentCoins;
};