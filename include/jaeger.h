#ifndef JAEGER_H
#define JAEGER_H

#include "ship.h"

#include <string>


class jaeger : public ship
{
    public:
        jaeger();
        std::string getType() const override;
        std::string getSpecial() const override;
        void specialAttack(int &enemyHP, int &shipSize) const override;
};

#endif // JAEGER_H
