#include "Controller.h"
#include <string>
#include <iostream>
#include "SingletonFont.h"
#include "Coin.h"
#include "GiftAddingTime.h"
#include "GiftAddingEnemy.h"

 int Controller::m_level = 1;

Controller::Controller(): m_window(sf::VideoMode(1600, 1080), "RICK RUNNER")
{
    m_gameOverSound.setBuffer(SingletonSound::instance().getMGameOver());
    m_levelUpSoundl.setBuffer(SingletonSound::instance().getMLevelUp());
    m_startGameSound.setBuffer(SingletonSound::instance().getMStartGame());

    m_window.setFramerateLimit(60);
	board.setTexture(SingletonPicture::instance().getBoardTexture());
	board.setPosition(0,0);
    printStartGameScreen();

    m_boardChar = openlevelfile(m_level);
   // m_time.restart();
    newGame();

}
//=============================================================

void Controller::run()
{
    
    m_time.restart();
    m_startGameSound.play();
	while (m_window.isOpen())
	{
        float deltaTime = clock.restart().asSeconds();
		m_window.clear();
		m_window.draw(board);
		m_board.draw(m_window);
        m_board.printGameStatus(m_window,m_level, m_playingTime, m_time, m_isOnTime);
        m_window.display();

//dsadas
		sf::Event event;
		while(m_window.pollEvent(event))
			if (sf::Keyboard::isKeyPressed(sf:: Keyboard::Escape)|| event.type == sf::Event::Closed)
			{
				m_window.close();
				break;
			}

        m_board.checkIfObjectFalling(deltaTime);
        if (m_board.checkCollisions(deltaTime))
            ResetLevel();
        
        m_board.moveCharacters(deltaTime);
        m_board.checkIfHeroDig();
        //m_board check if hero alive
        //m_board check if hero got gift
        //m_board check if hero took coin
        if ( 0 >= Hero::getLife())
        {
            gameOverHandler(false);
        }

        //check if there is no move available coins to get
        if(checkIfLevelDone()) {

            //check if there is move level to upgrade
            if (m_level == NUMBEROFLEVELS)
            {
                gameOverHandler(true);
                newGame();
            }
            else {
                m_level++;
                //if there is no more coins move to the next level
                upgradeLevel();
            }
        }

        CheckingTimes();
        
       

       
	}
}

//=============================================================

std::vector<std::vector<char>> Controller::openlevelfile(int level)
{
    std::vector<std::vector<char>> temp;
    int width, height;
    m_time.restart();
	std::string filename = "level";
		filename += std::to_string(level);
		filename += ".txt";
		std::ifstream file;
		file.open(filename);
		if(!file.is_open())
			std::cout << "Error while open level file";


        file >> width >> height >> m_timeTheLevel; // take size map
        file.get();

        if (-1 < m_timeTheLevel)
        {
            m_playingTime = sf::seconds(m_timeTheLevel);
            m_isOnTime = true;
            m_time.restart();
        }
        else
            m_isOnTime = false;

        for (int i = 0; i < height; ++i)
        {
            std::vector<char> row;

            for (int j = 0; j < width; ++j)
            { 
                row.push_back(file.get());
            }
            file.get();
            temp.push_back(row);
        }
        file.close();


        return temp;
}
//=============================================================

unsigned int Controller::getLevel() {
    return m_level;
}
//=============================================================

bool Controller::checkIfLevelDone() {
    return (Coin::getNowCoins() == 0);
}
//=============================================================
void Controller::ResetCoins()
{
    Coin::CoinInitialization();
}
//=============================================================

void Controller::upgradeLevel() {

    
        sf::Sprite uplevel;
       uplevel.setTexture(SingletonPicture::instance().getMLevelUp());
       uplevel.setPosition(0,0);
       m_window.clear();
       m_window.draw(uplevel);
       m_window.display();
       sf::sleep(sf::seconds(2));


     m_boardChar = openlevelfile(m_level);
     m_levelUpSoundl.play();
     m_board = Board(m_boardChar,m_herroSelect);

    

}
//=============================================================

void Controller::printStartGameScreen() {

 auto soundmusic = sf::Sound(SingletonSound::instance().getOpenGame());
    soundmusic.play();
    sf::Sprite openpic(SingletonPicture::instance().getMStartGame());

    while (m_window.isOpen())
    {
        if (auto event = sf::Event{}; m_window.waitEvent(event)) {}

            m_window.clear();
            m_window.draw(openpic);
            m_window.display();

            sf::sleep(sf::seconds(4));
            return;

    }
}
//=============================================================

void Controller::gameOverHandler(bool isplyerwin)
{
    m_gameOverState.openstate(m_window,isplyerwin);
    m_level = 0;
    newGame();

}
//=============================================================
void Controller::CheckingTimes()
{
    if (m_isOnTime)
        if (m_playingTime.asSeconds() - m_time.getElapsedTime().asSeconds() <= 0)
        {
            Hero::SetLife(Hero::getLife() - 1);
            ResetLevel();
        }
}
//=============================================================
void Controller::newGame()
{
    Hero::SetLife(3);
    m_herroSelect = m_menu.StartGame(m_window);
    m_board = Board(m_boardChar, m_herroSelect);
    m_time.restart();

}

void Controller::ResetLevel()
{

    m_time.restart();
    ResetCoins();
    m_board.ResetMap();
}
//=============================================================

void Controller::reedemGifts() {

    for (int i = 0; i < GiftAddingEnemy::getNumberOfGiftAddingRnemy(); ++i) {
        m_board.andEnemyRandomly(m_herroSelect);
        GiftAddingEnemy::redeemGift();
    }

    for (int i = 0; i < GiftAddingTime::getNumberofgiftaddingtime(); ++i) {

        m_playingTime += sf::seconds(ADDTIMEGIFTTIME);
        GiftAddingTime::redeenGift();
    }

}