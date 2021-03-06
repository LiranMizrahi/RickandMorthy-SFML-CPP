#include"MovingObject/SmartEnemy.h"
#include"Board.h"
#include <queue>
#include<StaticObjects/Rope.h>
#include<StaticObjects/Ladder.h>

#include <cmath>

//=========================constructor ======================================
SmartEnemy::SmartEnemy(const sf::Vector2f &loc, int EnemySelection,
                       const sf::Vector2f boardsize) :
    Enemy(loc, EnemySelection,boardsize), m_step (0), m_lastStep(0),  m_direction (false)

{
}
//====================================================
void SmartEnemy::UpdateLocation(float time, sf::Vector2f locHero, const  std::vector <std::vector<char>>& boardChar, Board& board)
{
    if (isIsingidedfloor())return;
    sf::Vector2f pointEnemy, pointHero;
    //index enemy in a board
    pointEnemy.x = std::round((this->getSprite().getPosition().x - board.getCellWidth() / 2u) / board.getCellWidth());
    pointEnemy.y = std::round((this->getSprite().getPosition().y - board.getCellHight() / 2u) / board.getCellHight());
    //index hero in a board
    pointHero.x = std::round((locHero.x - board.getCellWidth() / 2u) / board.getCellWidth());
    pointHero.y = std::round((locHero.y - board.getCellHight() / 2u) / board.getCellHight());

    // creat vector to the algoritem 
    auto  visited = creatingRunningVector(boardChar);
    // alguritem bfs for smart enemy 
    auto step = bfsAlgorithm(pointEnemy, pointHero, visited);
    // move enemy smart
    movEnemySmart(step, time);

}
//====================================================
void SmartEnemy::handleColision(Rope& Obj)
{   // If the hero wants to go right or left and his previous side was up
    if(m_lastStep == UP && (m_step == RIGHT || m_step == LEFT) )
    m_sprite.setPosition((m_sprite.getPosition().x), m_sprite.getPosition().y + m_sprite.getGlobalBounds().height / 4);
}
//====================================================
void SmartEnemy::handleColision(Ladder& Obj)
{
    m_isUpAvail = true;

    //Conditions when we are on a ladder
    //Whether you go up or down
    if(m_step == UP || m_step == DOWN)
    {
        m_sprite.setPosition((Obj.getSprite().getPosition().x + Obj.getSprite().getGlobalBounds().width / 4), m_sprite.getPosition().y);
    }
    //If you go right or left and also your previous side was up or down
    else if (((m_step == LEFT || m_step == RIGHT) && (m_lastStep == UP || m_lastStep == DOWN)))
    {   //if UP last step
        if (UP == m_lastStep)
            m_sprite.setPosition((m_sprite.getPosition().x), (m_sprite.getPosition().y - m_sprite.getGlobalBounds().height));
        else if (DOWN == m_lastStep && LEFT == m_step)
        {
            m_sprite.setPosition((m_sprite.getPosition().x - m_sprite.getGlobalBounds().width), (m_sprite.getPosition().y + Obj.getSprite().getGlobalBounds().height / 4));
        }
        else if (DOWN == m_lastStep && RIGHT == m_step)
        {
            m_sprite.setPosition((m_sprite.getPosition().x + m_sprite.getGlobalBounds().width), (m_sprite.getPosition().y + Obj.getSprite().getGlobalBounds().height / 4));
        }
    }
}
//====================================================
std::vector <std::vector<int>> SmartEnemy::creatingRunningVector(std::vector <std::vector<char>> boardChar)
{
    std::vector<std::vector<int>> visited;
    visited.resize(boardChar.size());
    //Creates the array
    for (size_t i = 0; i < visited.size(); ++i)
    {
        visited[i].resize(boardChar[0].size());
    }


    //Creates an order for the BFS
    if ((!boardChar.empty() && !boardChar[0].empty()))
    for (size_t i = 0; i < boardChar.size(); i++) {

        for (size_t j = 0; j < boardChar[0].size(); j++)
        {
            if (boardChar[i][j] == HERO || boardChar[i][j] == ENEMY)
            {
                if (ReturnsCellInVector(boardChar, i, j))
                visited[i][j] = 0;
            }
            else if ((boardChar[i][j] == ROPE || boardChar[i][j] == LADDER) ||
                (i + 1 < boardChar.size() && (boardChar[i + 1][j] == FLOOR || boardChar[i + 1][j] == LADDER))
                && (boardChar[i][j] == COIN || boardChar[i][j] == GIFT || boardChar[i][j] == ' '))
            {
                if (ReturnsCellInVector(boardChar, i, j))
                visited[i][j] = (size_t) 0;
            }
                
            else if (boardChar[i][j] != '#' && i != boardChar.size() - 1 && i != 0)
            {
                if (ReturnsCellInVector(boardChar, i, j))
                visited[i][j] = (size_t) 2;

            }
            else
            {
                if (ReturnsCellInVector(boardChar, i, j))
                visited[i][j] = (size_t) 1;

            }
        }
    }
    return visited;
}
//====================================================
int SmartEnemy::bfsAlgorithm(sf::Vector2f pointEnemy, sf::Vector2f pointHero, std::vector<std::vector<int>> visited)
{
    Bfs EnemyD(size_t(pointEnemy.y), size_t(pointEnemy.x), std::vector<int>());
    std::queue< Bfs> q;

    if ((!visited.empty() && !visited[0].empty()))
    {
        if ((EnemyD.m_row >= 0 && EnemyD.m_row < visited.size()) && (EnemyD.m_col >= 0 && EnemyD.m_col < visited[0].size()))
            visited[EnemyD.m_row][EnemyD.m_col] = 1;

        q.push(EnemyD);
        // bfs algoritem 
        while (!q.empty())
        {
            if (q.empty())
            {
                return -1;
            }
            Bfs p = q.front();
            q.pop();

            //If I came to the hero you will return the direction
            if (p.m_row == pointHero.y && p.m_col == pointHero.x)
            {
                if (!p.m_direction.empty())
                    return p.m_direction[0];
                else
                    return -1;
            }

            //UP
            //Checking if you need to go upstairs
            if (p.m_row - 1 >= 0 && visited[p.m_row - (size_t) 1][p.m_col] == 0)
            {
                p.m_direction.push_back(UP);
                q.push(Bfs(p.m_row - 1, p.m_col, std::vector <int>(p.m_direction)));
                if (!p.m_direction.empty())
                    p.m_direction.pop_back();
                visited[p.m_row - (size_t) 1][p.m_col] = 1;
            }
            //DOWN
            //Checking if you need to go downstairs
            if (p.m_row + (size_t) 1 < visited.size() && (visited[p.m_row + (size_t) 1][p.m_col] == 0 || visited[p.m_row + (size_t) 1][p.m_col] == 2))
            {

                p.m_direction.push_back(DOWN);
                q.push(Bfs(p.m_row + 1, p.m_col, std::vector <int>(p.m_direction)));
                if (!p.m_direction.empty())
                    p.m_direction.pop_back();
                visited[p.m_row + (size_t) 1][p.m_col] = 1;
            }

            //LEFT
            //Checking if you need to go left
            if (p.m_col - 1 >= 0 && (visited[p.m_row][p.m_col - (size_t) 1] == 0 || visited[p.m_row][p.m_col - (size_t)1] == 2))
            {

                p.m_direction.push_back(LEFT);
                q.push(Bfs(p.m_row, p.m_col - 1, std::vector <int>(p.m_direction)));
                if (!p.m_direction.empty())
                    p.m_direction.pop_back();
                visited[p.m_row][p.m_col - (size_t) 1] = 1;
            }

            //RIGHT
            //Checking if you need to go right
            if (p.m_col + (size_t)1 < visited[1].size() && (visited[p.m_row][p.m_col + (size_t) 1] == 0 || visited[p.m_row][p.m_col + (size_t) 1] == 2))
            {


                p.m_direction.push_back(RIGHT);
                q.push(Bfs(p.m_row, p.m_col + 1, std::vector <int>(p.m_direction)));
                if (!p.m_direction.empty())
                    p.m_direction.pop_back();
                visited[p.m_row][p.m_col + (size_t)1] = 1;
            }

        }
    }
    return -1;
}
//====================================================
void SmartEnemy::movEnemySmart(int step, float time)
{
    
    switch (step)
    {

    case LEFT:

        this->move(-ENEMYSPEED * time, 0);
        this->DrawLeftside();
        m_lastStep = m_step;
        m_step = LEFT;
        break;
    case  RIGHT:
        this->move(ENEMYSPEED * time, 0);
        this->DrawRightside();
        m_lastStep = m_step;
        m_step = RIGHT;
        break;
    case UP:
        if (m_isUpAvail)
        {
            this->move(0, -HEROSPEED * time);
            m_lastStep = m_step;
            m_step = UP;
        }
        break;
    case DOWN:
        this->move(0, HEROSPEED * time);
        m_lastStep = m_step;
        m_step = DOWN;
        break;
    case RANDOMLY:
        randomMovment(time);
    }
}
//====================================================
void SmartEnemy::randomMovment(float time)
{

    int RandomMov = std::rand() % 4;
    switch (RandomMov)
    {

    case LEFT:
        this->move(-ENEMYSPEED * time, 0);
        this->DrawLeftside();
        break;
    case  RIGHT:
        this->move(ENEMYSPEED * time, 0);
        this->DrawRightside();
        break;
    case UP:
        if (m_isUpAvail)
            this->move(0, -HEROSPEED * time);
        break;
    case DOWN:
        this->move(0, HEROSPEED * time);
        break;
    }
}
//====================================================
bool SmartEnemy::ReturnsCellInVector(const std::vector<std::vector<char>> &boardChar, size_t i, size_t j)
{
    if ((!boardChar.empty()&&  i < boardChar.size()) && (!boardChar[0].empty() && j < boardChar[0].size()))
    {
        return true;
    }
    return false;

}
 
