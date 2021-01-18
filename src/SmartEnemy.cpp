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
    std::vector<std::vector<bool>> visited;

    float pointposition = board.getCellHight();
    for (row = 0; pointposition <= this->getSprite().getPosition().y; ++row) {
        pointposition += board.getCellHight();
    }
    pointposition = board.getCellWidth();
    for (col = 0; pointposition <= this->getSprite().getPosition().x; col++) {
        pointposition += board.getCellWidth();
    }
    pointEnemy.x = col;
    pointEnemy.y = row;

    pointposition = board.getCellHight();
    for (row = 0; pointposition <= locHero.y; ++row) {
        pointposition += board.getCellHight();
    }
    pointposition = board.getCellWidth();
    for (col = 0; pointposition <= locHero.x; col++) {
        pointposition += board.getCellWidth();
    }

    pointHero.x = col;
    pointHero.y = row;


    Bfs EnemyD;
    EnemyD.m_col = pointEnemy.x;
    EnemyD.m_row = pointEnemy.y;
    EnemyD.m_direction = 0;

  /*  for (int i = 0; i < boardChar.size(); ++i)
    {
        std::vector<bool>row;
        for (int j = 0; j < boardChar[i].size(); ++j)
        {
            if (boardChar[i][j] == '#')
            {
                row.push_back(true);

            }
            else if((i < boardChar.size() &&(boardChar[i][j] == NULL && boardChar[i+ 1][j] == '#')))
            {
                row.push_back(false);
            }
            else if (i < boardChar.size() && boardChar[i][j] == NULL && boardChar[i + 1][j] == NULL)
            {
                row.push_back(true);
            }
            else
            {
                row.push_back(false);
            }
        }
        visited.push_back(row);
    }*/





    for (size_t i = 0; i < boardChar.size(); i++) {
        std::vector<bool>row;
        for (size_t j = 0; j < boardChar[i].size(); j++)
        {
            if ((boardChar[i][j] == '-' || boardChar[i][j] == 'H') ||
                (i + 1 < boardChar.size() && (boardChar[i + 1][j] == '#' || boardChar[i + 1][j] == 'H')))
               row.push_back(false);
            else
                row.push_back(true);
        }
        visited.push_back(row);
    }


  /*  for (int i = 0; i < boardChar.size(); ++i)
    {
        
        for (int j = 0; j < boardChar[i].size(); ++j)
        {
            std::cout << visited[i][j] << " ";
        }
        std::cout << std::endl;
    }*/


    //visited[pointHero.y][pointHero.x] = '@';

    std::queue< Bfs> q;
    std::queue< Bfs> start;
    Bfs p;
    q.push(EnemyD);
    //start.push(EnemyD);
    visited[EnemyD.m_row][EnemyD.m_col] = true;

    while (!q.empty())
    {
         p = q.front();
        q.pop();
        
        

        if (p.m_row == pointHero.y && p.m_col == pointHero.x)
        {
            //p = q.back();
            break;
        }
        //up
        if (p.m_row - 1 >= 0 && visited[p.m_row - 1][p.m_col] == false)
        {
            Bfs Item;
            Item.m_col;
            Item.m_row = p.m_row - 1;
            Item.m_direction = UP;
            q.push(Item);
            start.push(Item);
            visited[p.m_row - 1][p.m_col] = true;
        }
        //down
        if (p.m_row + 1 < board.getHeight() && visited[p.m_row + 1][p.m_col] == false)
        {
            Bfs Item;
            Item.m_col;
            Item.m_row= p.m_row + 1;
            Item.m_direction = DOWN;
            q.push(Item);
            start.push(Item);
            visited[p.m_row + 1][p.m_col] = true;
        }

        //left
        if (p.m_col - 1 >= 0  && visited[p.m_row][p.m_col - 1] == false)
        {
            Bfs Item;
            Item.m_col = p.m_col - 1;
            Item.m_row;
            Item.m_direction = LEFT;
            q.push(Item);
            start.push(Item);
            visited[p.m_row][p.m_col - 1] = true;
        }

        //right
        if (p.m_col + 1 < board.getWidth() && visited[p.m_row][p.m_col + 1] == false)
        {
            Bfs Item;
            Item.m_col = p.m_col + 1;
            Item.m_row;
            Item.m_direction = RIGHT;
            q.push(Item);
            start.push(Item);
            visited[p.m_row][p.m_col + 1] = true;
        }
    }
    
    
    switch (start.front().m_direction)
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
