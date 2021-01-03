#pragma once
#include "picture.h"

Picture::Picture()
{
	m_heroRick.loadFromFile("rick_left.png");
	m_heroJerry.loadFromFile("jerry_left.png");
	m_EnemyMeeseeks.loadFromFile("meeseeks_left.png");
	m_EnemyMonster.loadFromFile("monster_left.png");
	m_board.loadFromFile("level1.jpg");
	m_gun.loadFromFile("portalgun.png");
	m_ledder.loadFromFile("ladder.png");
	m_rope.loadFromFile("rope.png");
	m_floor.loadFromFile("brike.png");
	m_menu.loadFromFile("menu.png");
	//m_start.loadFromFile("start_button.png");
	m_HeroMenu1.loadFromFile("jerry_player.png");
	m_HeroMenu2.loadFromFile("rick_player.png");

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

sf::Texture* Picture::GetGunTexture()
{
	return &m_gun;
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