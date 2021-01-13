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
	virtual void handleColision(Rope&) override {};
	virtual void handleColision(Hero&) override {};
	virtual void handleColision(Floor&) override {};
	virtual void handleColision(Ladder&) override {};
	virtual void handleColision(GameObj&) override {};
	virtual void handleColision(Coin&) override {};
	virtual void handleColision(Enemy&) override {};
	virtual void handleColision(GiftAddingLife&) override {};
	virtual void handleColision(GiftAddingScore&) override {};
	virtual void handleColision(GiftAddingEnemy&) override {};
    virtual bool isObjectIsStandable(GameObj&)override;

private:
	//void fallingGift(float);

};