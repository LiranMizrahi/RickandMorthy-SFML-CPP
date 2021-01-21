#pragma once
#include"MovingObject/Enemy.h"
struct Bfs
{
public:
	//=========public members======================
	int m_row = 0;
	int m_col = 0;
	std::vector<int> m_direction = {0};
	//===================public function=================
	Bfs(int row, int col, std::vector<int> direction) : m_row(row), m_col(col), m_direction{ direction }{}
	Bfs() = default;
};



class SmartEnemy: public Enemy
{
public:
	SmartEnemy() = default;
	SmartEnemy(const sf::Vector2f &loc, int EnemySelection,
               const sf::Vector2f boardsize);
	~SmartEnemy() override = default;

	//===================public function=================
	void UpdateLocation(float , sf::Vector2f, const  std::vector <std::vector<char>>&, Board&)override;
	void handleColision(Rope& Obj) override;
	void handleColision(Ladder& Obj) override;

private:
	//===================private function=================
	std::vector <std::vector<int>> creatingRunningVector(std::vector <std::vector<char>> );
	int bfsAlgorithm(sf::Vector2f, sf::Vector2f, std::vector<std::vector<int>>);
	void movEnemySmart(int, float);
	void randomMovment(float);
	bool ReturnsCellInVector(const std::vector<std::vector<char>> &, size_t, size_t);
	//=========private members======================
	int m_step;
	int m_lastStep;
	bool m_direction;
	
};