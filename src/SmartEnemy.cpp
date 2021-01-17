#include"SmartEnemy.h"

SmartEnemy::SmartEnemy(const sf::Vector2f &loc, int EnemySelection,
                       const sf::Vector2f boardsize) : Enemy(loc,
                                                             EnemySelection,boardsize)
{
}


void SmartEnemy::UpdateLocation(float time)
{
    
   

    switch (5)
    {

        case LEFT:
            this->move(-ENEMYSPEED * time, 0);
            break;
        case  RIGHT:
            this->move(ENEMYSPEED * time, 0);

            break;
        case UP:
            break;
        case DOWN:
            break;
    }
}
