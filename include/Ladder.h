#pragma once
#include"Hero.h"
#include"Enemy.h"
#include "StaticObjects.h"
class SingletonPicture;
#include <SFML/Graphics.hpp>
class Ladder : public StaticObjects {

public:
	Ladder();
	Ladder(const sf::Vector2f& loc, const sf::Vector2f&);
    ~Ladder() override= default;

    virtual void handleColision(Rope& )override {};
    virtual void handleColision(Hero&)override;
	virtual void handleColision(Floor&) override {};
	virtual void handleColision(Ladder&) override {};
	virtual void handleColision(GameObj&)override;
	virtual void handleColision(Coin&) override {};
	virtual void handleColision(Enemy&) override;
	virtual void handleColision(GiftAddingLife&) override {};
	virtual void handleColision(GiftAddingScore&) override {};
	virtual void handleColision(GiftAddingEnemy&) override {};
	virtual void handleColision(GiftAddingTime&) override {};

    virtual bool isObjectIsStandable(GameObj&)override;
    virtual bool isObjectDigable()override;
};