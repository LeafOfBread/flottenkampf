#ifndef ZERSTOERER_H
#define ZERSTOERER_H

#include "ship.h"


class zerstoerer : public ship
{
    public:
        zerstoerer();

        std::string getType() const override;
        std::string getSpecial() const override;
        void specialAttack (int &enemyHP, int &shipSize) const override;

    protected:

    private:
};

#endif // ZERSTOERER_H
