#pragma once
#include "SingletonPicture.h"
#include <iostream>




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

	if (!m_board.loadFromFile("level1.jpg"))
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

    if (!m_levelUp.loadFromFile("leveluppic.jpg"))
        std::cout << "cant open picture";
    if (!m_startGame.loadFromFile("openGamepic.jpg"))
        std::cout << "cant open picture";

    if (!m_heroIsdead.loadFromFile("rick_player.png"))
        std::cout << "cant open picture";

    if (!m_gameOver.loadFromFile("gameoverpic.jpg"))
        std::cout << "cant open picture";



}

const sf::Texture* SingletonPicture::getHerojerryTexture()
{
	return &m_heroJerry;
}

const sf::Texture*  SingletonPicture::getHeroRickTexture()
{
	return &m_heroRick;
}


const sf::Texture* SingletonPicture::getEnemyMeeseeksTexture()
{
	return &  m_enemyMeeseeks;
}

const sf::Texture * SingletonPicture::getEnemyMonsterTexture()
{
	return &m_enemyMonster;
}

const sf::Texture* SingletonPicture::getCoinTexture()
{
	return &m_coin;
}

const sf::Texture* SingletonPicture::getBoardTexture()
{
	return &m_board;
}

const sf::Texture* SingletonPicture::getFloorTexture()
{
	return &m_floor;
}

const sf::Texture* SingletonPicture::getLedderTexture()
{
	return &m_ledder;
}

const sf::Texture* SingletonPicture::getRopeTexture()
{
	return &m_rope;
}

const sf::Texture* SingletonPicture::getMenuTexture()
{
	return &m_menu;
}

const sf::Texture* SingletonPicture::getJerryTexture()
{
	return &m_heroMenu1;
}

const sf::Texture* SingletonPicture::getRickTexture()
{
	return &m_heroMenu2;
}

    SingletonPicture &SingletonPicture::instance() {
        static SingletonPicture inst;
        return inst;
    }

const sf::Texture* SingletonPicture::getMLevelUp()  {
    return &m_levelUp;
}

const sf::Texture* SingletonPicture::getMStartGame()  {
    return &m_startGame;
}

const sf::Texture* SingletonPicture::getMHeroIsdead()  {
    return &m_heroIsdead;
}

const sf::Texture* SingletonPicture::getMGameOver()  {
    return &m_gameOver;
}

