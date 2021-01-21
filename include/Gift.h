#pragma once

#include "StaticObjects.h"
#include <SFML/Graphics.hpp>
#include "Hero.h"
class SingletonPicture;
const int TYPESOFGIFS =4;

enum GiftTypes  {
    AddLife =0,AddScore,AddEnemy,AddTime
};

class Gift : public StaticObjects {

public:
	Gift() =default;
	Gift(const sf::Vector2f& loc, const sf::Vector2f&);
	virtual ~Gift()= default;
	virtual void handleColision(Rope&) override=0;
	virtual void handleColision(Hero&) override=0;
	virtual void handleColision(Floor&) override=0;
	virtual void handleColision(Ladder&) override=0;
	virtual void handleColision(GameObj&) override=0;
	virtual void handleColision(Coin&) override=0;
	virtual void handleColision(Enemy&) override=0;
	virtual void handleColision(GiftAddingLife&) override=0;
	virtual void handleColision(GiftAddingScore&) override=0;
	virtual void handleColision(GiftAddingEnemy&) override=0 ;
	virtual void handleColision(GiftAddingTime&) override {};

    virtual bool isObjectIsStandable(Hero&)override;
    virtual bool isObjectIsStandable(Enemy&)override;

    virtual bool isObjectDigable(const sf::Time &) override;
    virtual bool restoreGameObj(const sf::Time &, float cellheight) override;
	virtual void resetObj()override {};


protected:
    bool m_isreedem = false;
    sf::Time m_showTime;

};