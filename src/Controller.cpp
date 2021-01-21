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
	m_background.setTexture(SingletonPicture::instance().getBoardTexture(m_level));
    m_background.setScale(m_background.getTexture()->getSize().x/(float)BOARDWIDTH,m_background.getTexture()->getSize().y/(float)BOARDHEIGHT);
    m_startGameState.openstate(m_window,m_herroSelect);

    std::srand(std::time(nullptr));
    newGame();

}
/*=============================================================
The main function of the game
 throw the Board object move all the moving object handle all game logic
=============================================================*/

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



        deltaTime = clock.restart().asSeconds();

        drawWindow();
        m_board.checkIfObjectFalling(deltaTime);
        m_board.checkCollisions(deltaTime);
        m_board.moveCharacters(deltaTime, m_boardChar);
        m_board.checkIfHeroDig(m_time.getElapsedTime());
        //Check if a game object need an handle after time
        m_board.restroreGameObjects(m_time.getElapsedTime());
        //if player collect a gift that this or m_background class need to handle
        reedemGifts();
        //check if hero is dead and if he have more life
        checkIfHeroalive();
        //If the player collect all coins the level is finish
        checkIfPlayerFinishLevel();
        //if the level is "on time level" this function check if the level finish
        checkIfTimeIsOver();

	}
}

//=============================================================

std::vector<std::vector<char>> Controller::readFromFile()
{
    std::vector<std::vector<char>> temp;
    int width, height;
    //m_time.restart();

        m_file >> width >> height >> m_timeTheLevel; // take size map
        m_file.get();

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
                row.push_back(m_file.get());
            }
            m_file.get();
            temp.push_back(row);
        }
        m_file.close();

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
    //If opening the next level file failed the game over otherwise move to the next level
    if(!openlevelfile()) {
        m_gameOverState.openstate(m_window,true);
        m_herroSelect = m_menu.StartGame(m_window);
        newGame();
        return;
    }
    else
        m_levelUpState.openstate(m_window,m_herroSelect);

    //save all hero data and restore after the board build the new level
    m_boardChar = readFromFile();
    int herolife = m_board.getHerolife();
    int heroscore = m_board.getHeroScore();
    m_board = Board(m_boardChar, m_herroSelect, m_level);
    m_board.addHeroScore(heroscore);
    m_board.setHeroLife(herolife);

}

//=============================================================

void Controller::gameOverHandler(bool isplyerwin)
{
//    m_gameOverState.openstate(m_window,isplyerwin);
//    m_level = 1;
//    m_board.setHeroLife(3);
//    //openlevelfile();


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
/*=============================================================
This function reset the game and start the game from level 1
 =============================================================*/
void Controller::newGame()
{
    Coin::resetCoins();
    m_level = 4;
    openlevelfile();
    m_boardChar = readFromFile();
    m_herroSelect = m_menu.StartGame(m_window);
    m_board = Board(m_boardChar, m_herroSelect, m_level);
    m_board.setHeroLife(HEROSTARTLIFE);
    m_time.restart();

}
//=============================================================
//Reset the level all the moving abjects return to their first position
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
void Controller::checkIfHeroalive() {

    //if the hero is dead reset the level
    if(m_board.checkIfHroalive())
        ResetLevel();
    //if there is no more life for the hero the gameover
    if ( 0 >= m_board.getHerolife())
    {
        //gameOverHandler(false);
        m_gameOverState.openstate(m_window,false);
        newGame();
    }
}
/*=============================================================
Check if there is no move available coins to get
If the player collect all the coin the level is finish
=============================================================*/
 void Controller::checkIfPlayerFinishLevel() {

    if(checkIfLevelDone())
    {
            m_board.addHeroScore(LEVELUPADDSCORE);
            m_level++;
            upgradeLevel();
            m_background.setTexture(SingletonPicture::instance().getBoardTexture(m_level));
    }
}
//=============================================================
void Controller::drawWindow() {

    m_window.clear();
    m_window.draw(m_background);
    m_board.draw(m_window);
    m_gameStatusBar.printGameStatus(m_window,m_level, m_playingTime, m_time, m_isOnTime,m_board.getHeroScore(),m_board.getHerolife());
    m_window.display();


}
//=============================================================
bool Controller::openlevelfile() {
    std::string filename = "level";
    filename += std::to_string(m_level);
    filename += ".txt";

    m_file.open(filename);
    if(!m_file.is_open())
    {
        return false;
    }
    return true;
}
//=============================================================
