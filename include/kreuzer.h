#ifndef KREUZER_H
#define KREUZER_H

#include "ship.h"


class kreuzer : public ship
{
    public:
        kreuzer();
        virtual ~kreuzer();

        std::string getType() const override;
        std::string getSpecial() const override;
        void specialAttack(int &enemyHP, int &shipSize) const override;

    protected:

    private:
};

#endif // KREUZER_H
