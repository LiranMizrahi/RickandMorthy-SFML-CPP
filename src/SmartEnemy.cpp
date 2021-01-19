#include"SmartEnemy.h"
#include"Board.h"
#include <queue>
 


SmartEnemy::SmartEnemy(const sf::Vector2f &loc, int EnemySelection,
                       const sf::Vector2f boardsize) : Enemy(loc,
                                                             EnemySelection,boardsize)
{
}




void SmartEnemy::UpdateLocation(float time, sf::Vector2f locHero, const  std::vector <std::vector<char>>& boardChar, Board& board)
{

    sf::Vector2f pointEnemy, pointHero;
    float row, col;
    std::vector<std::vector<int>> visited;

    float pointposition = board.getCellHight();
    for (row = 0; pointposition <= this->getSprite().getPosition().y; ++row) {
        pointposition += board.getCellHight();
    }
    pointposition = board.getCellWidth();
    for (col = 1; pointposition <= this->getSprite().getPosition().x; col++) {
        pointposition += board.getCellWidth();
    }
    pointEnemy.x = col;
    pointEnemy.y = row;

    pointposition = board.getCellHight();
    for (row = 0; pointposition <= locHero.y; ++row) {
        pointposition += board.getCellHight();
    }
    pointposition = board.getCellWidth();
    for (col = 1; pointposition <= locHero.x; col++) {
        pointposition += board.getCellWidth();
    }

    pointHero.x = col;
    pointHero.y = row;


    Bfs EnemyD;
    EnemyD.m_col = pointEnemy.x;
    EnemyD.m_row = pointEnemy.y;
    EnemyD.m_direction.push_back(0);



    for (size_t i = 0; i < board.getHeight(); i++) {
        std::vector<int>row;

        for (size_t j = 0; j < board.getWidth(); j++)
        {
            if ((boardChar[i][j] == '-' || boardChar[i][j] == 'H') ||
                (i + 1 < boardChar.size() && (boardChar[i + 1][j] == '#' || boardChar[i + 1][j] == 'H')))
                row.push_back(0);
            else if (boardChar[i][j] != '#' && i != boardChar.size() - 1 && i != 0)
                row.push_back(2);
            else
                row.push_back(1);
        }
        visited.push_back(row);
    }



    std::queue< Bfs> q;
    //std::queue<int> start;
    Bfs p;
    //start.push(EnemyD);
    if((EnemyD.m_row >= 0 && EnemyD.m_row < visited.size()) && (EnemyD.m_col >= 0 && EnemyD.m_col < visited[1].size()))
    visited[EnemyD.m_row][EnemyD.m_col] = 1;
    q.push(EnemyD);
    int move = 6;
    /*while (!q.empty())
    {
        p = q.front();
        q.pop();*/
        
        

        //if (p.m_row == pointHero.y && p.m_col == pointHero.x)
        //{
        //    move = p.m_direction.back();
        //    break;
        //}

        ////up
        //if (p.m_row - 1 >= 0 && visited[p.m_row - 1][p.m_col] == 0)
        //{
        //    Bfs temp;
        //    temp.m_col;
        //    temp.m_row  = p.m_row - 1;
        //    temp.m_direction.push_back(UP);

        //    p.m_direction.push_back(UP);
        //    q.push(temp);
        //    //start.push(UP);
        //    visited[p.m_row - 1][p.m_col] = 1;
        //}
        ////down
        //if (p.m_row + 1 < visited.size() && (visited[p.m_row + 1][p.m_col] == 0 || visited[p.m_row + 1][p.m_col] == 2))
        //{
        //    
        //    Bfs temp;
        //    temp.m_col;
        //    temp.m_row = p.m_row + 1;
        //    temp.m_direction.push_back(DOWN);


        //  
        //    p.m_direction.push_back(DOWN);
        //    q.push(temp);
        //    //start.push(DOWN);
        //    visited[p.m_row + 1][p.m_col] = 1;
        //}

        ////left
        //if (p.m_col - 1 >= 0  && visited[p.m_row][p.m_col - 1] == 0)
        //{

        //    Bfs temp;
        //    temp.m_col = p.m_col - 1;
        //    temp.m_row;
        //    temp.m_direction.push_back(LEFT);

        //    p.m_direction.push_back(LEFT);
        //    q.push(temp);
        //    //start.push(LEFT);
        //    visited[p.m_row][p.m_col - 1] = 1;
        //}

        ////right
        //if (p.m_col + 1 < visited[1].size() && visited[p.m_row][p.m_col + 1] == 0)
        //{
        //   
        //    Bfs temp;
        //    temp.m_col = p.m_col + 1;
        //    temp.m_row;
        //    temp.m_direction.push_back(RIGHT);

        // 
        //    p.m_direction.push_back ( RIGHT);
        //    q.push(temp);
        //    //start.push(RIGHT);
        //    visited[p.m_row][p.m_col + 1] = 1;
        //}
    /*}*/
    
    
    switch (move)
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
        default:
            int i = 0;

    }
}
