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

	 void handleColision(Rope&) override=0;
	 void handleColision(Hero&) override=0;
	 void handleColision(Floor&) override=0;
	 void handleColision(Ladder&) override=0;
	 void handleColision(GameObj&) override=0;
	 void handleColision(Coin&) override=0;
	 void handleColision(Enemy&) override=0;
	 void handleColision(GiftAddingLife&) override=0;
	 void handleColision(GiftAddingScore&) override=0;
	 void handleColision(GiftAddingEnemy&) override=0 ;
	 void handleColision(GiftAddingTime&) override {};

	 bool isObjectIsStandable(Hero&)override;
     bool isObjectIsStandable(Enemy&)override;

     bool isObjectDigable(const sf::Time &) override;
     bool restoreGameObj(const sf::Time &, float cellheight) override;
	 void resetObj()override {};


protected:
    bool m_isreedem = false;
    sf::Time m_showTime;

};