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
										
class Controller {
					

public:

	Controller();
	void run();
	static unsigned int getLevel();

private:

	//private members
	int m_choes;
	Board m_board;
	Menu m_menu;
	sf::RenderWindow m_window;
	sf::Sprite board;	
	sf::Clock clock;
	std::ifstream m_boardfile;
	sf::Sound m_startGameSound;
	sf::Sound m_gameOverSound;
    sf::Sound m_levelUpSoundl;


	static  int m_level;
	
	//private function
	std::ifstream openlevelfile(int);
    bool checkIfLevelDone();
	void upgradeLevel();
	void printStartGameScreen();
	void gameOverHandler(bool);


};				