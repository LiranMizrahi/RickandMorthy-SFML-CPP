#pragma once
#include "picture.h"
#include <iostream>

Picture::Picture()
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


}

sf::Texture* Picture::getHerojerryTexture()
{
	return &m_heroJerry;
}

sf::Texture* Picture::getHeroRickTexture()
{
	return &m_heroRick;
}


sf::Texture* Picture::getEnemyMeeseeksTexture()
{
	return &m_enemyMeeseeks;
}

sf::Texture* Picture::getEnemyMonsterTexture()
{
	return &m_enemyMonster;
}

sf::Texture* Picture::getCoinTexture()
{
	return &m_coin;
}

sf::Texture* Picture::getBoardTexture()
{
	return &m_board;
}

sf::Texture* Picture::getFloorTexture()
{
	return &m_floor;
}

sf::Texture* Picture::getLedderTexture()
{
	return &m_ledder;
}

sf::Texture* Picture::getRopeTexture()
{
	return &m_rope;
}

sf::Texture* Picture::getMenuTexture()
{
	return &m_menu;
}

sf::Texture* Picture::getJerryTexture()
{
	return &m_heroMenu1;
}

sf::Texture* Picture::getRickTexture()
{
	return &m_heroMenu2;
}