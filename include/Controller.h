 #pragma once
        
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameObj.h"
#include "SingletonPicture.h"
#include "MenuState.h"
#include "Board.h"
#include "fstream"
#include "MenuState.h"
#include "SingletonSound.h"
#include"Coin.h"
#include "GameOverState.h"
#include "GameStatusBar.h"
#include "StartGameState.h"

#include "LevelUpState.h"

 class Controller {
					

public:

	Controller();
	void run();


private:

	//private member
	bool m_isOnTime;
	float m_timeTheLevel;
	int m_herroSelect;
    int m_level;

    std::vector<std::vector<char>> m_boardChar;
	Board m_board;
	sf::RenderWindow m_window;
	sf::Sprite board;
    sf::Time m_playingTime ;
    sf::Clock m_time;
	sf::Clock clock;
	sf::Sound m_startGameSound;
	sf::Sound m_gameOverSound;
    sf::Sound m_levelUpSoundl;

    MenuState m_menu;
    GameOverState m_gameOverState;
    StartGameState m_startGameState;
	GameStatusBar m_gameStatusBar;
	LevelUpState m_levelUpState;

	//private function
	std::vector<std::vector<char>> openlevelfile(int);
    bool checkIfLevelDone();
	void ResetCoins();
	void upgradeLevel();
	void printStartGameScreen();
	void gameOverHandler(bool isplayerwin);
	void reedemGifts();
	void CheckingTimes();
	void newGame();
	void ResetLevel();

};				