#include "../include/ship.h"
#include <iostream>

using namespace std;

ship::ship()
{
    //ctor
}

ship::~ship()
{
    //dtor
}

bool ship::isDestroyed()
{
    if (this->hp <= 0)  //wenn hp < 0, ist das schiff zerstoert
    {
        return true;
    }
    else return false;
}
