#pragma once
#include"Enemy.h"
struct Bfs
{
	//Dfs(int row, int col, int direction) { m_row = row, m_col = col, m_direction = direction };

	int m_row = 0;
	int m_col = 0;
	int m_direction = 0;
};


class SmartEnemy: public Enemy
{
public:
	SmartEnemy(const sf::Vector2f &loc, int EnemySelection,
               const sf::Vector2f boardsize);
	
	~SmartEnemy() override = default;
	virtual void UpdateLocation(float , sf::Vector2f, const  std::vector <std::vector<char>>&, Board&)override;

private:
	
};