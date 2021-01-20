#include "Controller.h"
#include <string>
#include <iostream>
#include "SingletonFont.h"
#include "Coin.h"
#include "GiftAddingTime.h"
#include "GiftAddingEnemy.h"



Controller::Controller(): m_window(sf::VideoMode(WINDOWSIZEWIDTH, WINDOWSIZEHEIGHT), "RICK RUNNER"),m_level(1)
{
    m_gameOverSound.setBuffer(SingletonSound::instance().getMGameOver());
    m_levelUpSoundl.setBuffer(SingletonSound::instance().getMLevelUp());
    m_startGameSound.setBuffer(SingletonSound::instance().getMStartGame());
    m_window.setFramerateLimit(FRAMERATESPEED);
	board.setTexture(SingletonPicture::instance().getBoardTexture(m_level));

    //m_boardChar = openlevelfile(m_level);
    m_startGameState.openstate(m_window,m_herroSelect);

    newGame();

}
//=============================================================

void Controller::run()
{
    float deltaTime;
    m_time.restart();
    sf::Event event;

	while (m_window.isOpen())
	{
        while(m_window.pollEvent(event))
            if (sf::Keyboard::isKeyPressed(sf:: Keyboard::Escape)|| event.type == sf::Event::Closed)
            {
                m_window.close();
                break;
            }

        drawWindow();

        deltaTime = clock.restart().asSeconds();

        m_board.checkIfObjectFalling(deltaTime);
        m_board.checkCollisions(deltaTime);
        m_board.moveCharacters(deltaTime, m_boardChar);
        m_board.checkIfHeroDig(m_time.getElapsedTime());

        m_board.restroreGameObjects(m_time.getElapsedTime());
        //if player collect a gift that this or board class need to handle
        reedemGifts();
        //check if hero is dead and if he have more life
        checkIfHroalive();
        //If the player collect all coins the level is finish
        checkIfPlayerFinishLevel();
        //if the level is "on time level" this function check if the level finish
        checkIfTimeIsOver();

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

bool Controller::checkIfLevelDone() {
    return (Coin::getNowCoins() == 0);
}
//=============================================================
void Controller::ResetCoins()
{
    Coin::CoinInitialization();
}
//=============================================================

void Controller::upgradeLevel()
{
     m_levelUpState.openstate(m_window,m_herroSelect);
     m_boardChar = openlevelfile(m_level);

    int herolife = m_board.getHerolife();
    int heroscore = m_board.getHeroScore();
    m_board = Board(m_boardChar, m_herroSelect, m_level);
    m_board.setHeroScore(heroscore);
    m_board.setHeroLife(herolife);


}
//=============================================================

//void Controller::printStartGameScreen() {
//
//    auto soundmusic = sf::Sound(SingletonSound::instance().getOpenGame());
//    soundmusic.play();
//    sf::Sprite openpic(SingletonPicture::instance().getMStartGame());
//
//    while (m_window.isOpen())
//    {
//        if (auto event = sf::Event{}; m_window.waitEvent(event)) {}
//
//            m_window.clear();
//            m_window.draw(openpic);
//            m_window.display();
//
//            sf::sleep(sf::seconds(4));
//            return;
//
//    }
//}
//=============================================================

void Controller::gameOverHandler(bool isplyerwin)
{
    m_gameOverState.openstate(m_window,isplyerwin);
    m_level = 0;
    newGame();

}
//=============================================================
void Controller::checkIfTimeIsOver()
{
    if (m_isOnTime)
        if (m_playingTime.asSeconds() - m_time.getElapsedTime().asSeconds() <= 0)
        {
            m_board.setHeroLife((m_board.getHerolife()-1));
            ResetLevel();
        }
}
//=============================================================
void Controller::newGame()
{
    Coin::resetCoins();
    m_level = 1;
    m_boardChar = openlevelfile(m_level);
    m_herroSelect = m_menu.StartGame(m_window);
    m_board = Board(m_boardChar, m_herroSelect, m_level);
    m_board.setHeroLife(HEROSTARTLIFE);
    m_time.restart();

    
}
//=============================================================

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
//=============================================================
void Controller::checkIfHroalive() {

    if(m_board.checkIfHroalive())
        ResetLevel();

    if ( 0 >= m_board.getHerolife())
    {
        gameOverHandler(false);
    }
}
//=============================================================

void Controller::checkIfPlayerFinishLevel() {

    //check if there is no move available coins to get
    if(checkIfLevelDone()) {

        //check if there is move level to upgrade

        if (m_level == NUMBEROFLEVELS)
        {
            gameOverHandler(true);
            newGame();
        }
        else
        {
            m_level++;
            //if there is no more coins move to the next level
            upgradeLevel();
            board.setTexture(SingletonPicture::instance().getBoardTexture(m_level));

        }
    }
}
//=============================================================
void Controller::drawWindow() {

    m_window.clear();
    m_window.draw(board);
    m_board.draw(m_window);
    m_gameStatusBar.printGameStatus(m_window,m_level, m_playingTime, m_time, m_isOnTime,m_board.getHeroScore(),m_board.getHerolife());
    m_window.display();


}
