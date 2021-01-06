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


	m_jerrySound.setBuffer(m_jerry);
	m_rickSound.setBuffer(m_rick);
	m_startGameSound.setBuffer(m_startGame);
	m_gameOverSound.setBuffer(m_gameOver);
	m_deadSound.setBuffer(m_dead);
	m_levelUpSound.setBuffer(m_levelUp);
	m_collectCoinSound.setBuffer(m_collectCoin);
	m_collectGiftSound.setBuffer(m_collectGift);



}

void Sound::playJerrySound()
{
	m_jerrySound.play();
}

void Sound::playRickSound()
{
	m_rickSound.play();
}

void Sound::playStartGameSound()
{	
	m_startGameSound.play();
}

void Sound::playGameOverSound()
{
	m_gameOverSound.play();
}

void Sound::playDeadSozund()
{
	m_deadSound.play();
}

void Sound::playLevelUpSound()
{
	m_levelUpSound.play();
}

void Sound::playCollectCoinSound()
{
	m_collectCoinSound.play();
}

void Sound::playCollectGiftSound()
{
	m_collectGiftSound.play();
}

