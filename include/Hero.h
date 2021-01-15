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
	   Hero(const sf::Vector2f&, int);
	   int getLife();
	   int getScore();
	   void SetScore(int);
	   void SetLife(int);
	    void UpdateLocation(float)override;

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

private:
		static int m_life, m_score;
		sf::Sound m_collectGiftSound;
        sf::Sound m_collectCoinSound;
        sf::Sound m_collectDeadSound;


        void playCollectGiftSound();
        void playCollectCoinSound();
        void playCollectDeadSound();


};