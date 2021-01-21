#pragma once

#include "StaticObjects.h"
#include <SFML/Graphics.hpp>
#include "Hero.h"
class SingletonPicture;


enum GiftTypes{
    AddLife =0,AddScore,AddEnemy,AddTime
};

class Gift : public StaticObjects {

public:
	Gift() =default;
	Gift(const sf::Vector2f& loc, const sf::Vector2f&);
	virtual ~Gift()= default;
    //=========public function======================
	 bool isObjectIsStandable(Hero&)override;
     bool isObjectIsStandable(Enemy&)override;

     bool isObjectDigable(const sf::Time &) override;
     bool restoreGameObj(const sf::Time &, float cellheight) override;
	 void resetObj()override {};


protected:
    //=========private protected======================
    bool m_isreedem = false;
    sf::Time m_showTime;

};