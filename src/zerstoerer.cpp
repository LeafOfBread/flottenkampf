#include "../include/zerstoerer.h"
#include <time.h>

zerstoerer::zerstoerer()
{
    hp = 150;
    shipSize = 6;
    damage = 60;
}

void zerstoerer::specialAttack(int &enemyHP, int &shipSize) const
{
    srand(time(0));
    if ((rand()%10+1)>=shipSize-2)  //einfacherer treffercheck
    {
        enemyHP = enemyHP - this->damage;
    }
}

std::string zerstoerer::getType() const
{
    return "Zerstoerer";
}

std::string zerstoerer::getSpecial() const
{
    return "Zielsuchend";
}


