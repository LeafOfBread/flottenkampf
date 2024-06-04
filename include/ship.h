#ifndef SHIP_H
#define SHIP_H

#include <string>

class ship
{
public:
    ship();
    virtual ~ship();

    int hp;
    int shipSize;
    int damage;
    int specialAmount = 3;
    int x;
    int y;

    virtual std::string getType() const = 0;    // Getter for type name
    virtual std::string getSpecial() const = 0; // Getter for special attack name
    bool isDestroyed() const;                   // Checks if ship is destroyed
    virtual void specialAttack(int &enemyHP, int &shipSize) const = 0; // Special move

protected:

private:
};

#endif // SHIP_H
