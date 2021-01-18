#pragma once

#include "StaticObjects.h"
#include <SFML/Graphics.hpp>
#include "Hero.h"
class SingletonPicture;


class Coin : public StaticObjects {

public:
	Coin();
	Coin(const sf::Vector2f &loc, const sf::Vector2f &size, int level);
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
	virtual void resetObj()override;

    virtual bool isObjectIsStandable(Hero&)override;

    virtual bool isObjectIsStandable(Enemy&)override;
	virtual void handleColision(GiftAddingTime&) override {};
	static size_t getNowCoins();
    virtual bool isObjectDigable(const sf::Time&) override;
	static void CoinInitialization();

    static void incCoins();
	static void resetCoins();
private:
    int m_value;
public:
    int getValue() const;

private:
    static size_t m_allCoins;
	static size_t m_currentCoins;
};