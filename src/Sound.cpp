#include "Sound.h"
#include <iostream>


Sound::Sound()
{
	if (!m_jerry.loadFromFile("jerrysound.wav"))
		std::cerr << "Can't open sound file mf";
		
	if (!m_rick.loadFromFile("ricksound.wav"))
		std::cerr << "Can't open sound file mf";
	
	if (!m_startGame.loadFromFile("start.wav"))
		std::cerr << "Can't open sound file mf";
	
	if (!m_gameOver.loadFromFile("gameover.wav"))
		std::cerr << "Can't open sound file mf";

	if (!m_dead.loadFromFile("dead.wav"))
		std::cerr << "Can't open sound file mf";

	if (!m_levelUp.loadFromFile("levelup.wav"))
		std::cerr << "Can't open sound file mf";


	if (!m_collectCoin.loadFromFile("collectcoin.wav"))
		std::cerr << "Can't open sound file mf";


	if (!m_collectGift.loadFromFile("collectgift.wav"))
		std::cerr << "Can't open sound file mf";


}


Sound &Sound::instance() {

    static  Sound inst;
    return inst;
}

const sf::SoundBuffer &Sound::getMJerry() const {
    return m_jerry;
}

const sf::SoundBuffer &Sound::getMRick() const {
    return m_rick;
}

const sf::SoundBuffer &Sound::getMStartGame() const {
    return m_startGame;
}

const sf::SoundBuffer &Sound::getMGameOver() const {
    return m_gameOver;
}

const sf::SoundBuffer &Sound::getMDead() const {
    return m_dead;
}

const sf::SoundBuffer &Sound::getMLevelUp() const {
    return m_levelUp;
}

const sf::SoundBuffer &Sound::getMCollectGift()  {
    return m_collectGift;
}

const sf::SoundBuffer &Sound::getMCollectCoin() const {
    return m_collectCoin;
}



