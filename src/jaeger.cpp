#include "../include/jaeger.h"

jaeger::jaeger()
{
    hp = 75;
    shipSize = 4;
    damage = 30;
}

void jaeger::specialAttack(int &enemyHP, int &shipSize) const
{
        if ((rand()%10+1)>=9)
        {
            enemyHP = enemyHP - (this->damage*2);   //doppelter schaden
        }

}

std::string jaeger::getType() const {
    return "Jaeger";
}

std::string jaeger::getSpecial() const
{
    return "Kritische Treffer";
}
