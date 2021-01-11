#pragma once

#include "SingletonPicture.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "MovingObjects.h"
#include"GameObj.h"
#include"Coin.h"

class Hero : public MovingObjects {

   public:
	   Hero() = default;
	   ~Hero()override = default;
	   Hero(const sf::Vector2f&, int );
	   int getLife();
	   int getScore();
	   void SetScore(int);
	   void SetLife(int);
	   virtual void UpdateLocation(float)override;

	   virtual void handleColision(GameObj&)override;
	   virtual void handleColision(Rope&)override;
	   virtual void handleColision(Hero&)override {};
	   virtual void handleColision(Floor&)override;
	   virtual void handleColision(Ladder&)override;
	   virtual void handleColision(Coin&) override;
	   virtual void handleColision(Enemy&) override;


private:
		int m_life, m_score;
		sf::Sound m_collectGiftSound;
        sf::Sound m_collectCoinSound;
        sf::Sound m_collectDeadSound;


        void playCollectGiftSound();
        void playCollectCoinSound();
        void playCollectDeadSound();


};