#pragma once
#include "picture.h"
#include <iostream>

Picture::Picture()
{
	if (!m_heroRick.loadFromFile("rick_left.png"))
	std::cout << "cant open picture";

	if(!m_heroJerry.loadFromFile("jerry_left.png"))
	std::cout << "cant open picture";

	if (!m_EnemyMeeseeks.loadFromFile("meeseeks_left.png"))
	std::cout << "cant open picture";

	if (!m_EnemyMonster.loadFromFile("monster_left.png"))	
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

	if(!m_HeroMenu1.loadFromFile("jerry_player.png"))
	std::cout << "cant open picture";

	if (!m_HeroMenu2.loadFromFile("rick_player.png"))
	std::cout << "cant open picture";


}

sf::Texture* Picture::GetHerojerryTexture()
{
	return &m_heroJerry;
}

sf::Texture* Picture::GetHeroRickTexture()
{
	return &m_heroRick;
}


sf::Texture* Picture::GetEnemyMeeseeksTexture()
{
	return &m_EnemyMeeseeks;
}

sf::Texture* Picture::GetEnemyMonsterTexture()
{
	return &m_EnemyMonster;
}

sf::Texture* Picture::GetCoinTexture()
{
	return &m_coin;
}

sf::Texture* Picture::GetBoardTexture()
{
	return &m_board;
}

sf::Texture* Picture::GetFloorTexture()
{
	return &m_floor;
}

sf::Texture* Picture::GetLedderTexture()
{
	return &m_ledder;
}

sf::Texture* Picture::GetRopeTexture()
{
	return &m_rope;
}

sf::Texture* Picture::GetMenuTexture()
{
	return &m_menu;
}

sf::Texture* Picture::GetStartTexture()
{
	return &m_start;
}

sf::Texture* Picture::GetHeroMenu1Texture()
{
	return &m_HeroMenu1;
}

sf::Texture* Picture::GetHeroMenu2Texture()
{
	return &m_HeroMenu2;
}