#pragma once
#include "picture.h"

Picture::Picture()
{
	m_hero.loadFromFile("jerry_front.png");
	m_enemy.loadFromFile("meeseeks_front.png");
	m_board.loadFromFile("level1.jpg");
	m_gun.loadFromFile("portalgun.png");
	m_ledder.loadFromFile("ladder.png");
	m_rope.loadFromFile("rope.png");
	m_floor.loadFromFile("brike.jpg");
	m_menu.loadFromFile("menu.png");
	m_start.loadFromFile("start_button.png");

}

sf::Texture* Picture::GetHeroTexture()
{
	return &m_hero;
}

sf::Texture* Picture::GetEnemyTexture()
{
	return &m_enemy;
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