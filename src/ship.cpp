#include "../include/ship.h"
#include <iostream>


ship::ship()
{
    hp = 100;
    shipSize = 5;
    damage = 50;
    x = rand()%10;
    y = rand()%10;
}

ship::~ship()
{
    //dtor
}

bool ship::isDestroyed() const
{
    if (this->hp <= 0)  //wenn hp < 0, ist das schiff zerstoert
    {
        return true;
    }
    else return false;
}
