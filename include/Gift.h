#pragma once

#include "StaticObjects.h"
#include <SFML/Graphics.hpp>
#include "Hero.h"
class SingletonPicture;
const int TYPESOFGIFS =3;

enum GiftTypes  {
    AddLife =0,AddScore,AddEnemy
};

class Gift : public StaticObjects {

public:
	Gift() {};
	Gift(const sf::Vector2f& loc, const sf::Vector2f&);
	~Gift() override = default;
	virtual void handleColision(Rope&) override = 0;
	virtual void handleColision(Hero&) override = 0;
	virtual void handleColision(Floor&) override  = 0;
	virtual void handleColision(Ladder&) override  = 0;
	virtual void handleColision(GameObj&) override  = 0;
	virtual void handleColision(Coin&) override  = 0;
	virtual void handleColision(Enemy&) override  = 0;
	virtual void handleColision(GiftAddingLife&) override  = 0;
	virtual void handleColision(GiftAddingScore&) override  = 0;
	virtual void handleColision(GiftAddingEnemy&) override  = 0;
    virtual bool isObjectIsStandable(GameObj&)override;

private:
	//void fallingGift(float);

};