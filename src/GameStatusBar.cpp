//
// Created by Liran Mizrahi on 17/01/2021.

#include "SingletonFont.h"
#include "GameStatusBar.h"
#include "Macros.h"
#include <iomanip>

const int MARKTEXTTIME = 2;
const int LASTCALLTIME = 10;
const int MAXCORETOSHOW = 1000000;
const int CHARRACTERSIZE = 50;
const float SPACESSIZR = 30;
//====================================================

GameStatusBar::GameStatusBar() :m_score(0),m_life(HEROSTARTLIFE) {

    m_scoreText.setFont(SingletonFont::instance().getMBoardstatus());
    m_levelText.setFont(SingletonFont::instance().getMBoardstatus());
    m_lifeText.setFont(SingletonFont::instance().getMBoardstatus());
    m_timeTheLevel.setFont(SingletonFont::instance().getMBoardstatus());

    m_lifeText.setCharacterSize(CHARRACTERSIZE);
    m_scoreText.setCharacterSize(CHARRACTERSIZE);
    m_levelText.setCharacterSize(CHARRACTERSIZE);
    m_timeTheLevel.setCharacterSize(CHARRACTERSIZE);

}
//====================================================
void GameStatusBar::printGameStatus(sf::RenderWindow & window, int levelnum ,const  sf::Time & timeLevel,
                                    const sf::Clock& time, bool m_isOnTime ,int score, int life) {


    printChangeColor(life, time, timeLevel, score);

   float lefttime= timeLevel.asSeconds() - time.getElapsedTime().asSeconds() ;

    std::string scorestr = "000000";

    if(score>=MAXCORETOSHOW)
        scorestr+="0";

    scorestr.replace(scorestr.size()-std::to_string(score).size(),
                     std::to_string(score).size(),std::to_string(score));
    m_scoreText.setString("Score:"+scorestr);
    m_levelText.setString("Level:000" + std::to_string(levelnum));
    m_lifeText.setString("Life:000"+std::to_string(life));


    if (m_isOnTime)
    {
        if(lefttime < LASTCALLTIME)
            m_timeTheLevel.setColor(sf::Color::Red);
        else
            m_timeTheLevel.setColor(sf::Color::White);

        m_timeTheLevel.setString("Time:" + std::to_string(lefttime));
    }
    else
    {
        m_timeTheLevel.setString("Time: 9999");
    }

    m_scoreText.setPosition(SPACESSIZR,BOARDHEIGHT);
    m_levelText.setPosition(m_scoreText.getPosition().x+m_scoreText.getGlobalBounds().width +SPACESSIZR,BOARDHEIGHT);
    m_lifeText.setPosition(m_levelText.getPosition().x+m_levelText.getGlobalBounds().width+SPACESSIZR,BOARDHEIGHT);
    m_timeTheLevel.setPosition(m_lifeText.getPosition().x + m_lifeText.getGlobalBounds().width + SPACESSIZR , BOARDHEIGHT);

   printboard(window);

}
//====================================================

void GameStatusBar::printboard(sf::RenderWindow &window) {
    window.draw(m_lifeText);
    window.draw(m_scoreText);
    window.draw(m_levelText);
    window.draw(m_timeTheLevel);

}
//====================================================
void GameStatusBar::printChangeColor(int life, const sf::Clock &clock,
                                     const sf::Time &time, int score) {
    if (score > m_score)
    {
        m_scoreText.setColor(sf::Color::Green);
        m_scorechange = clock.getElapsedTime();
    }

    if(life < m_life)
    {
        m_lifeText.setColor(sf::Color::Red);
        m_lifechange = clock.getElapsedTime();

    }
    if(life > m_life)
    {
        m_lifeText.setColor(sf::Color::Green);
        m_lifechange = clock.getElapsedTime();
    }

    if(time > m_time)
    {
        m_timeTheLevel.setColor(sf::Color::Green);
        m_timechange = clock.getElapsedTime();
    }
    m_life = life;
    m_time = time;
    m_score = score;

    if(clock.getElapsedTime().asSeconds() > m_scorechange.asSeconds() + MARKTEXTTIME)
        m_scoreText.setColor(sf::Color::White);

    if(clock.getElapsedTime().asSeconds() > m_timechange.asSeconds() + MARKTEXTTIME)
            m_timeTheLevel.setColor(sf::Color::White);

    if(clock.getElapsedTime().asSeconds()  > m_lifechange.asSeconds() + MARKTEXTTIME)
        m_lifeText.setColor(sf::Color::White);

}
//====================================================
