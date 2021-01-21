 #pragma once
        
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameObj.h"
#include "Singletons/SingletonPicture.h"
#include "MenuState.h"
#include "Board.h"
#include "fstream"
#include "MenuState.h"
#include "Singletons/SingletonSound.h"
#include"StaticObjects/Coin.h"
#include "States/GameOverState.h"
#include "GameStatusBar.h"
#include "States/StartGameState.h"

#include "States/LevelUpState.h"

 class Controller {

public:
	Controller();
	//===================public function=================
	void run();

private:
	//===================Private members=================
	bool m_isOnTime;
	float m_timeTheLevel;
	int m_herroSelect;
    int m_level;

    std::vector<std::vector<char>> m_boardChar;
	Board m_board;
	sf::RenderWindow m_window;
	sf::Sprite m_background;
    sf::Time m_playingTime ;
    sf::Clock m_time;
	sf::Clock clock;
	sf::Sound m_startGameSound;
	sf::Sound m_gameOverSound;
    sf::Sound m_levelUpSoundl;
    std:: fstream m_file;

    MenuState m_menu;
    GameOverState m_gameOverState;
    StartGameState m_startGameState;
	GameStatusBar m_gameStatusBar;
	LevelUpState m_levelUpState;

	//===================Private function=================
	std::vector<std::vector<char>> readFromFile();
    bool checkIfLevelDone();
	void ResetCoins();
	void upgradeLevel();
	void reedemGifts();
	void checkIfTimeIsOver();
	void newGame();
	void ResetLevel();
	void checkIfHeroalive();
	void checkIfPlayerFinishLevel();
	void drawWindow();
	bool openlevelfile();
 };