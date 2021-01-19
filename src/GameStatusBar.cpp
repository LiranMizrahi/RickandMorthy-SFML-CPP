//
// Created by Liran Mizrahi on 17/01/2021.

#include "SingletonFont.h"
#include "GameStatusBar.h"
#include "Macros.h"
#include <iomanip>

GameStatusBar::GameStatusBar() {

    m_scoreText.setFont(SingletonFont::instance().getMBoardstatus());
    m_levelText.setFont(SingletonFont::instance().getMBoardstatus());
    m_lifeText.setFont(SingletonFont::instance().getMBoardstatus());
    m_timeTheLevel.setFont(SingletonFont::instance().getMBoardstatus());

    m_lifeText.setCharacterSize(50);
    m_scoreText.setCharacterSize(50);
    m_levelText.setCharacterSize(50);
    m_timeTheLevel.setCharacterSize(50);

}

void GameStatusBar::printGameStatus(sf::RenderWindow & window, int levelnum ,const  sf::Time & timeLevel,
                                    const sf::Clock& time, bool m_isOnTime ,
                                    int score, int life) {

    char buf[4];


    std::string scorestr = "000000";
    if(score>=1000000)
        scorestr+="0";

    scorestr.replace(scorestr.size()-std::to_string(score).size(),
                     std::to_string(score).size(),std::to_string(score));
    m_scoreText.setString("Score:"+scorestr);
    m_levelText.setString("Level:000" + std::to_string(levelnum));
    m_lifeText.setString("Life:000"+std::to_string(life));

    if (m_isOnTime)
    {
        m_timeTheLevel.setString("Time:" + std::to_string(timeLevel.asSeconds() - time.getElapsedTime().asSeconds()));
    }
    else
    {
        m_timeTheLevel.setString("Time: 9999");
    }


    m_lifeText.setOutlineColor(sf::Color::White);
    m_scoreText.setPosition(30,BOARDHEIGHT);
    m_levelText.setPosition(m_scoreText.getPosition().x+m_scoreText.getGlobalBounds().width +30,BOARDHEIGHT);
    m_lifeText.setPosition(m_levelText.getPosition().x+m_levelText.getGlobalBounds().width+30,BOARDHEIGHT);
    m_timeTheLevel.setPosition(m_lifeText.getPosition().x + m_lifeText.getGlobalBounds().width + 30, BOARDHEIGHT);

    window.draw(m_lifeText);
    window.draw(m_scoreText);
    window.draw(m_levelText);
    window.draw(m_timeTheLevel);

}
