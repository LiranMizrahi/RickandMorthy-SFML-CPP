#pragma once
#include "SingletonPicture.h"
#include <iostream>
#include "Macros.h"




SingletonPicture::SingletonPicture()
{
	if (!m_heroRick.loadFromFile("rick_left.png"))
	std::cout << "cant open picture";

	if(!m_heroJerry.loadFromFile("jerry_left.png"))
	std::cout << "cant open picture";

	if (!m_enemyMeeseeks.loadFromFile("meeseeks_left.png"))
	std::cout << "cant open picture";

	if (!m_enemyMonster.loadFromFile("monster_left.png"))
	std::cout << "cant open picture";

	if (!m_coin.loadFromFile("portalgun.png"))
	std::cout << "cant open picture";

	if (!m_ledder.loadFromFile("ladder.png"))
	std::cout << "cant open picture";

	if (!m_rope.loadFromFile("rope.png"))
	std::cout << "cant open picture";

	if (!m_floor.loadFromFile("brike.png"))
	std::cout << "cant open picture";

	if (!m_menu.loadFromFile("menu.png"))
	std::cout << "cant open picture";

	if(!m_heroMenu1.loadFromFile("jerry_player.png"))
	std::cout << "cant open picture";

	if (!m_heroMenu2.loadFromFile("rick_player.png"))
	std::cout << "cant open picture";

	if (!m_gift.loadFromFile("gift.png"))
		std::cout << "cant open picture";

    if (!m_levelUp.loadFromFile("leveluppic.jpg"))
        std::cout << "cant open picture";
    if (!m_startGame.loadFromFile("openGamepic.jpg"))
        std::cout << "cant open picture";

    if (!m_heroIsdead.loadFromFile("rick_player.png"))
        std::cout << "cant open picture";

    if (!m_gameOver.loadFromFile("gameoverpic.jpg"))
        std::cout << "cant open picture";

    std::string  filename = "level";
    std::string filetype = "jpg";

    for (int i = 1; i <= NUMBEROFLEVELBACKGROUD ; ++i) {

        std::string  filename = "level";
        std::string filetype = ".jpg";
        auto level = sf::Texture();
        level.loadFromFile(filename+= std::to_string(i)+filetype);
        m_levelbackgrounds.push_back(level);
    }

}



const sf::Texture & SingletonPicture::getHerojerryTexture()const
{
	return m_heroJerry;
}

const sf::Texture&  SingletonPicture::getHeroRickTexture()const
{
	return m_heroRick;
}


const sf::Texture& SingletonPicture::getEnemyMeeseeksTexture()const
{
	return m_enemyMeeseeks;
}

const sf::Texture& SingletonPicture::getEnemyMonsterTexture()const
{
	return m_enemyMonster;
}

const sf::Texture& SingletonPicture::getCoinTexture()const
{
	return m_coin;
}

const sf::Texture& SingletonPicture::getBoardTexture(int level)const
{
	return m_levelbackgrounds[(level-(size_t)1) %(int) m_levelbackgrounds.size()];
}

const sf::Texture& SingletonPicture::getFloorTexture()const
{
	return m_floor;
}

const sf::Texture& SingletonPicture::getLedderTexture()const
{
	return m_ledder;
}

const sf::Texture& SingletonPicture::getRopeTexture()const
{
	return m_rope;
}

const sf::Texture& SingletonPicture::getMenuTexture()const
{
	return m_menu;
}

const sf::Texture& SingletonPicture::getJerryTexture()const
{
	return m_heroMenu1;
}

const sf::Texture& SingletonPicture::getRickTexture()const
{
	return m_heroMenu2;
}

const sf::Texture& SingletonPicture::getGiftTexture()const
{
	return m_gift;
}

    SingletonPicture &SingletonPicture::instance() {
        static SingletonPicture inst;
        return inst;
    }

const sf::Texture& SingletonPicture::getMLevelUp() const
{
    return m_levelUp;
}

const sf::Texture& SingletonPicture::getMStartGame()const
{
    return m_startGame;
}

const sf::Texture& SingletonPicture::getMHeroIsdead() const
{
    return m_heroIsdead;
}

const sf::Texture& SingletonPicture::getMGameOver() const {
    return m_gameOver;
}

