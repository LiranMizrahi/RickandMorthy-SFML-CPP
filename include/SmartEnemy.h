#pragma once
#include"Enemy.h"
struct Bfs
{
public:
	int m_row = 0;
	int m_col = 0;
	std::vector<int> m_direction = {0};

	Bfs(int row, int col, std::vector<int> direction) : m_row(row), m_col(col), m_direction{ direction }{}
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
	std::vector <std::vector<int>> creatingRunningVector(std::vector <std::vector<char>> );
	int bfsAlgorithm(sf::Vector2f, sf::Vector2f, std::vector<std::vector<int>>);
	void randomMovment(float);
	char m_node;
	int m_step = 0;
	int m_lastStep = 0;
	bool m_direction = false;
	
};