#pragma once
#include"Enemy.h"
struct Bfs
{
public:
	

	int m_row = 0;
	int m_col = 0;
	std::vector<int> m_direction = {0};
	std::vector<char> m_node = {0};
	Bfs(int row, int col, std::vector<int> direction, std::vector<char> node) : m_row(row), m_col(col), m_direction{ direction }, m_node(node) {}
	Bfs() = default;
};





class SmartEnemy: public Enemy
{
public:
	SmartEnemy(const sf::Vector2f &loc, int EnemySelection,
               const sf::Vector2f boardsize);
	
	~SmartEnemy() override = default;
	virtual void UpdateLocation(float , sf::Vector2f, const  std::vector <std::vector<char>>&, Board&)override;
	void handleColision(Rope& Obj) override;
	void handleColision(Ladder& Obj) override;

private:
	char m_node;
	int m_step = 0;
	//int m_lastStep = 0;
	bool m_direction = false;
	
};