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
	   Hero(const sf::Vector2f &loc, int HeroSelection,
            sf::Vector2f boardsize);
	   static int getLife();
	   static int getScore();
	   void SetScore(int);
	   static void SetLife(int);
	   void UpdateLocation(float)override;
	   void digHole(std::vector<std::vector<std::unique_ptr<StaticObjects>>> &m_staticobj,
                float m_cellWidth, float m_cellHight, int m_height, int m_width,
                const sf::Time &time);

	   void resetTime();
	   void handleColision(GameObj&)override;
	   void handleColision(Rope&)override;
	   void handleColision(Hero&)override;
	   void handleColision(Floor&)override;
	   void handleColision(Ladder&)override;
	   void handleColision(Coin&) override;
	   void handleColision(Enemy&) override;
	   virtual void handleColision(GiftAddingLife&) override;
	   virtual void handleColision(GiftAddingScore&) override;
	   virtual void handleColision(GiftAddingEnemy&) override {};
	   virtual void handleColision(GiftAddingTime&) override {};
       virtual bool isObjectIsStandable(StaticObjects&)override;
	   virtual void resetObj()override;
	    

private:
		static int m_life, m_score;
		sf::Sound m_collectGiftSound;
        sf::Sound m_collectCoinSound;
        sf::Sound m_collectDeadSound;
        sf::Time m_lastdigtime;


        void playCollectGiftSound();
        void playCollectCoinSound();
        void playCollectDeadSound();


};