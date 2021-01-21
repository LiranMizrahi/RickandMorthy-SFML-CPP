#include "Singletons/SingletonSound.h"
#include <iostream>

//=========================constructor ======================================
SingletonSound::SingletonSound()
{
    bool isok =true;
	 if (!m_jerry.loadFromFile("jerrysound.wav"))
		std::cerr << "Can't open sound file jerrysound";

	if (!m_rick.loadFromFile("ricksound.wav"))
		std::cerr << "Can't open sound file ricksound";
	
	if (!m_startGame.loadFromFile("start.wav"))
		std::cerr << "Can't open sound file start";
	
	if (!m_gameOver.loadFromFile("gameover.wav"))
		std::cerr << "Can't open sound file gameover";

	if (!m_dead.loadFromFile("dead.wav"))
		std::cerr << "Can't open sound file dead";

	if (!m_levelUp.loadFromFile("levelup.wav"))
		std::cerr << "Can't open sound file levelup";

	if (!m_collectCoin.loadFromFile("collectcoin.wav"))
		std::cerr << "Can't open sound file collectcoin";


	if (!m_collectGift.loadFromFile("collectgift.wav"))
		std::cerr << "Can't open sound file collectgift";

    if (!m_openGame.loadFromFile("opengamenew.wav"))
        std::cerr << "Can't open sound file opengamenew";
}


SingletonSound &SingletonSound::instance() {

    static  SingletonSound inst;
    return inst;
}

const sf::SoundBuffer &SingletonSound::getMJerry() const {
    return m_jerry;
}

const sf::SoundBuffer &SingletonSound::getMRick() const {
    return m_rick;
}

const sf::SoundBuffer &SingletonSound::getMStartGame() const {
    return m_startGame;
}

const sf::SoundBuffer &SingletonSound::getMGameOver() const {
    return m_gameOver;
}

const sf::SoundBuffer &SingletonSound::getMDead() const {
    return m_dead;
}

const sf::SoundBuffer &SingletonSound::getMLevelUp() const {
    return m_levelUp;
}

const sf::SoundBuffer &SingletonSound::getMCollectGift()  {
    return m_collectGift;
}

const sf::SoundBuffer &SingletonSound::getMCollectCoin() const {
    return m_collectCoin;
}

const sf::SoundBuffer &SingletonSound::getOpenGame() const {
    return m_openGame;
}



