#pragma once

#include "StaticObjects.h"
#include <SFML/Graphics.hpp>
#include "Hero.h"
class SingletonPicture;


class Coin : public StaticObjects {

public:
	Coin();
	Coin(const sf::Vector2f &loc, const sf::Vector2f &size, int level);
     virtual ~Coin() = default;

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

     bool isObjectIsStandable(Enemy&)override;
	 void handleColision(GiftAddingTime&) override {};
	static size_t getNowCoins();
     bool isObjectDigable(const sf::Time&) override;
     static void CoinInitialization();

	static void incCoins();
	static void resetCoins();
private:
    int m_value;
    static size_t m_allCoins;
	static size_t m_currentCoins;
};