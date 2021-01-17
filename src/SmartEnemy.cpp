#include"SmartEnemy.h"

SmartEnemy::SmartEnemy(const sf::Vector2f &loc, int EnemySelection,
                       const sf::Vector2f boardsize) : Enemy(loc,
                                                             EnemySelection,boardsize)
{
}


void SmartEnemy::UpdateLocation(float time)
{

    int RandomMov = std::rand() % 2;

    switch (RandomMov)
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
