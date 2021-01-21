#pragma once

#include "SingletonPicture.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "MovingObjects.h"
#include"GameObj.h"
#include"Coin.h"
#include<iostream>
class Hero : public MovingObjects {

   public:
	   Hero() = default;
	   ~Hero()override = default;
	   Hero(const sf::Vector2f &loc, int HeroSelection,sf::Vector2f boardsize);
	   int getLife();
	   int getScore();
	   void addScore(int);
	   void setLife(int);
	    void UpdateLocation(float , sf::Vector2f, const  std::vector <std::vector<char>>&, Board&)override;
	    void digHole(Board & board,const sf::Time &time);

	    void handleColision(GameObj&)override;
	    void handleColision(Rope&)override;
	    void handleColision(Hero&)override;
	    void handleColision(Floor&)override;
	    void handleColision(Ladder&)override;
	    void handleColision(Coin&) override;
	    void handleColision(Enemy&) override;
        void handleColision(GiftAddingLife&) override;
        void handleColision(GiftAddingScore&) override;
        void handleColision(GiftAddingEnemy&) override;
        void handleColision(GiftAddingTime&) override;


        bool isObjectIsStandable(StaticObjects&)override;
        void resetObj()override;
        void resetTime();

//=========private members ======================
private:
		int m_life, m_score;
		sf::Sound m_collectGiftSound;
        sf::Sound m_collectCoinSound;
        sf::Sound m_collectDeadSound;
        sf::Time m_lastdigtime;

//=========private function ======================
        void playCollectGiftSound();
        void playCollectCoinSound();
        void playCollectDeadSound();


};