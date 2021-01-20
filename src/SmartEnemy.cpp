#include"SmartEnemy.h"
#include"Board.h"
#include <queue>
#include<Rope.h>
#include<Ladder.h>
 


SmartEnemy::SmartEnemy(const sf::Vector2f &loc, int EnemySelection,
                       const sf::Vector2f boardsize) : Enemy(loc,
                                                             EnemySelection,boardsize)
{
}




void SmartEnemy::UpdateLocation(float time, sf::Vector2f locHero, const  std::vector <std::vector<char>>& boardChar, Board& board)
{

    sf::Vector2f pointEnemy, pointHero;
    std::vector<std::vector<int>> visited;
    visited.resize(board.getHeight());


    for (int i = 0; i < visited.size(); ++i)
    {
        visited[i].resize(board.getWidth());
    }




    pointEnemy.x = std::round((this->getSprite().getPosition().x - board.getCellWidth() / 2u) / board.getCellWidth());
    pointEnemy.y = std::round((this->getSprite().getPosition().y - board.getCellHight() / 2u) / board.getCellHight());

  
    pointHero.x = std::round((locHero.x - board.getCellWidth() / 2u) / board.getCellWidth());
    pointHero.y = std::round((locHero.y - board.getCellHight() / 2u) / board.getCellHight());

 

    std::vector<int> a;
    std::vector<char> b;
    a.clear();

    Bfs EnemyD(pointEnemy.y, pointEnemy.x, a, b);



    for (size_t i = 0; i < board.getHeight(); i++) {
        

        for (size_t j = 0; j < board.getWidth(); j++)
        {
            if (boardChar[i][j] == HERO || boardChar[i][j] == ENEMY)
            {
                visited[i][j] = 0;
            }
            else if ((boardChar[i][j] == ROPE || boardChar[i][j] == LADDER) ||
                (i + 1 < board.getHeight() && (boardChar[i + 1][j] == FLOOR || boardChar[i + 1][j] == LADDER))
                && (boardChar[i][j] == COIN || boardChar[i][j] == GIFT || boardChar[i][j] == ' '))
                visited[i][j]=0;
            else if (boardChar[i][j] != '#' && i != boardChar.size() - 1 && i != 0)
                visited[i][j] = 2;
            else
                visited[i][j] = 1;

        }
        
    }



    //for (int i = 0; i < visited.size(); ++i)
    //{
    //    for (int j = 0; j < visited[0].size(); ++j)
    //    {
    //        std::cout << visited[i][j];
    //    }
    //    std::cout << std::endl;
    //}


    std::queue< Bfs> q;
   

    if((EnemyD.m_row >= 0 && EnemyD.m_row < visited.size()) && (EnemyD.m_col >= 0 && EnemyD.m_col < visited[0].size()))
    visited[EnemyD.m_row][EnemyD.m_col] = 1;
    q.push(EnemyD);
    Bfs step;
    
    while (!q.empty())
    {
        Bfs p = q.front();
        q.pop();
        
        

        if (p.m_row == pointHero.y && p.m_col == pointHero.x)
        {   
            step.m_direction[0] = p.m_direction[0];
            step.m_node[0] = p.m_node[0];
            //move = p.m_direction[0];
            break;
        }

        //up
        if (p.m_row - 1 >= 0 && visited[p.m_row - 1][p.m_col] == 0)
        {
            p.m_direction.push_back(UP); 
            p.m_node.push_back(boardChar[p.m_row - 1][p.m_col]);
            q.push(Bfs(p.m_row - 1, p.m_col, std::vector <int>(p.m_direction), std::vector <char> (p.m_node)));
            p.m_direction.pop_back();
            p.m_node.pop_back();
            visited[p.m_row - 1][p.m_col] = 1;
        }
        //down
        if (p.m_row + 1 < visited.size() && (visited[p.m_row + 1][p.m_col] == 0 || visited[p.m_row + 1][p.m_col] == 2))
        {
         
            p.m_direction.push_back(DOWN);
            p.m_node.push_back(boardChar[p.m_row + 1][p.m_col]);
            Bfs temp(p.m_row + 1, p.m_col, std::vector <int>(p.m_direction), std::vector <char>(p.m_node));
            q.push(temp);
            p.m_direction.pop_back();
            p.m_node.pop_back();
            visited[p.m_row + 1][p.m_col] = 1;
        }

        //left
        if (p.m_col - 1 >= 0  && (visited[p.m_row][p.m_col - 1] == 0 || visited[p.m_row][p.m_col - 1] == 2))
        {

            p.m_direction.push_back(LEFT);
            p.m_node.push_back(boardChar[p.m_row][p.m_col - 1]);
            Bfs temp(p.m_row, p.m_col - 1, std::vector <int>(p.m_direction), std::vector <char> (p.m_node));
            q.push(temp);
            p.m_direction.pop_back();
            p.m_node.pop_back();
            visited[p.m_row][p.m_col - 1] = 1;
        }

        //right
        if (p.m_col + 1 < visited[1].size() && (visited[p.m_row][p.m_col + 1] == 0 || visited[p.m_row][p.m_col + 1] == 2))
        {
           

            p.m_direction.push_back(RIGHT);
            p.m_node.push_back(boardChar[p.m_row][p.m_col + 1]);
            Bfs temp(p.m_row, p.m_col + 1, std::vector <int>(p.m_direction), std::vector <char>(p.m_node));
            q.push(temp);
            p.m_direction.pop_back();
            p.m_node.pop_back();
            visited[p.m_row][p.m_col + 1] = 1;
        }
    }
    
    
    switch (step.m_direction[0])
    {

        case LEFT:
            m_direction = false;
            this->move(-ENEMYSPEED * time, 0);
            this->DrawLeftside();
            /*m_lastStep = m_step;*/
            m_node = step.m_node[0];
            m_step = LEFT;
            break;
        case  RIGHT:
            m_direction = true;
            this->move(ENEMYSPEED * time, 0);
            this->DrawRightside();
            //m_lastStep = m_step;
            m_node = step.m_node[0];
            m_step = RIGHT;
            break;
        case UP:
            if (m_isUpAvail)
            {
                //m_direction = true;
                this->move(0, -HEROSPEED * time);
                //m_lastStep = m_step;
                m_node = step.m_node[0];
                m_step = UP;
            }
            break;
        case DOWN:
            //m_direction = true;
            this->move(0, HEROSPEED * time);
            //m_lastStep = m_step;
            m_node = step.m_node[0];
            m_step = DOWN;
            break;
        default:
            int i = 0;

    }
}

void SmartEnemy::handleColision(Rope& Obj)
{  
    /*if ((RIGHT == m_step || LEFT == m_step) && DOWN == m_lastStep )
    {
        this->m_sprite.setPosition(this->getSprite().getPosition().x, Obj.getSprite().getPosition().y);
    }
    else if((RIGHT == m_step || LEFT == m_step) && DOWN == m_lastStep)
    {
        this->m_sprite.setPosition(this->getSprite().getPosition().x, Obj.getSprite().getPosition().y);
    }*/
    /*m_isUpAvail = false;
    if (m_direction == false)
    {
        this->m_sprite.setPosition(this->getSprite().getPosition().x, Obj.getSprite().getPosition().y);
        m_direction = true;
    }*/
}

void SmartEnemy::handleColision(Ladder& Obj)
{
    m_isUpAvail = true;


   /* if (m_step == UP && m_node == LADDER)
    {
        this->m_sprite.setPosition(this->getSprite().getPosition().x + 1, this->getSprite().getPosition().y);
    }
    else if (m_step == RIGHT && m_node == SPACE)
    {
        this->m_sprite.setPosition(this->getSprite().getPosition().x, this->getSprite().getPosition().y +5);
    }*/
    /*if ( floorf(m_LastPosition.y) == floorf(this->m_sprite.getPosition().y) || floorf(m_LastPosition.x) == floorf(this->m_sprite.getPosition().x))
    {
        if (((UP == m_step && UP == m_lastStep) || (DOWN == m_step && DOWN == m_lastStep)) && m_direction)
        {
            this->m_sprite.setPosition(this->getSprite().getPosition().x +1, this->getSprite().getPosition().y);

        }
        if (((LEFT == m_step && LEFT == m_lastStep) || (LEFT == m_step &&  UP == m_lastStep)) && !m_direction)
        {
            this->m_sprite.setPosition(this->getSprite().getPosition().x , this->getSprite().getPosition().y - 1);

        }
        if (((RIGHT == m_step && RIGHT == m_lastStep) || (RIGHT == m_step && UP == m_lastStep)) && m_direction)
        {
            this->m_sprite.setPosition(this->getSprite().getPosition().x, this->getSprite().getPosition().y - 12);
        }

    }*/
  
   
   


    //m_sprite.setPosition(m_LastPosition);
    //m_isUpAvail = true;
    //if (m_direction)
    //{
    //    this->m_sprite.setPosition( Obj.getSprite().getPosition().x, this->getSprite().getPosition().y);
    //    //this->SetPosition(Obj.getSprite().getPosition());
    //    m_direction = false;
    //   
    //}
}
 
