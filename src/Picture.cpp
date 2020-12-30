#pragma once
#include "picture.h"

Picture::Picture()
{
	m_hero.loadFromFile("digger12.png");
	m_enemy.loadFromFile("enemy.png");
	m_board.loadFromFile("boardbig2.jpg");
	m_gun.loadFromFile("portalgun.png");
	m_ledder.loadFromFile("ladder.png");
	m_rope.loadFromFile("rope.png");
	m_floor.loadFromFile("brike.jpg");
	m_clear.loadFromFile("clear.png");
	m_save.loadFromFile("save1.png");
	m_delete.loadFromFile("delete.png");
	m_background.loadFromFile("background.png");
	m_insertScreen.loadFromFile("insetimage.jpg");

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

sf::Texture* Picture::GetClearTexture()
{
	return &m_clear;
}

sf::Texture* Picture::GetFloorTexture()
{
	return &m_floor;
}

sf::Texture* Picture::GetDeleteTexture()
{
	return &m_delete;
}

sf::Texture* Picture::GetLedderTexture()
{
	return &m_ledder;
}

sf::Texture* Picture::GetSaveTexture()
{
	return &m_save;
}

sf::Texture* Picture::GetRopeTexture()
{
	return &m_rope;
}

sf::Texture* Picture::GetbackgroundTexture()
{
	return &m_background;
}

sf::Texture* Picture::GetInsertScreenTexture()
{
	return &m_insertScreen;
}
