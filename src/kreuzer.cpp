#include "../include/kreuzer.h"

kreuzer::kreuzer()
{
    hp = 250;
    shipSize = 8;
    damage = 50;
}

void kreuzer::specialAttack(int &enemyHP, int &shipSize) const
{
    if ((rand()%10+1)>=shipSize)    //wenn angreif erfolgreich -> callt die methode rekursiv erneut auf, bis der check failed
    {
        enemyHP = enemyHP - this->damage;
        this->specialAttack(enemyHP, shipSize);
    }
}


std::string kreuzer::getType() const
{
    return "Kreuzer";
}

std::string kreuzer::getSpecial() const
{
    return "Bombardement";
}

