#pragma once

#include"Gift.h"

class GiftAddingTime : public Gift
{

public:
    GiftAddingTime() = default;
    GiftAddingTime(const sf::Vector2f& loc, const sf::Vector2f&);
    virtual ~GiftAddingTime();

   //===================public function=================
    void handleColision(GameObj& obj) override ;
    void handleColision(Rope& Obj) override {};
    void handleColision(Hero& Obj) override ;
    void handleColision(Floor& obj)override {};
    void handleColision(Ladder& obj) override {};
    void handleColision(Coin&) override {};
    void handleColision(Enemy&) override {};
    void handleColision(GiftAddingLife&) override {};
    void handleColision(GiftAddingScore&) override {};
    void handleColision(GiftAddingEnemy&) override {};
    void handleColision(GiftAddingTime&) override {};
    //===================static function=================
    static int getNumberofgiftaddingtime();
    static void redeenGift();

private:
    //=========static members======================
    static int m_numberofgiftaddingtime;
};

