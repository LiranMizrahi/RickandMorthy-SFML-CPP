 #pragma once
        
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameObj.h"
#include "SingletonPicture.h"
#include "Menu.h"
#include "Board.h"
#include "fstream"
#include "Menu.h"
#include "SingletonSound.h"
#include"Coin.h"
#include "GameOverState.h"
										
class Controller {
					

public:

	Controller();
	void run();
	static unsigned int getLevel();

private:

	//private members
	int m_width, m_height;
	int m_timeTheLevel;
	int m_herroSelect;
	Board m_board;
	Menu m_menu;
	sf::RenderWindow m_window;
	sf::Sprite board;	
	sf::Clock clock;
	//std::ifstream m_boardfile;
	std::vector<std::vector<char>> m_boardChar;
	sf::Sound m_startGameSound;
	sf::Sound m_gameOverSound;
    sf::Sound m_levelUpSoundl;
    GameOverState m_gameOverState;
	sf::Time m_playingTime ;
	sf::Clock m_time;


	static  int m_level;
	
	//private function
	std::vector<std::vector<char>> openlevelfile(int);
    bool checkIfLevelDone();
	void upgradeLevel();
	void printStartGameScreen();
	void gameOverHandler(bool);


};				