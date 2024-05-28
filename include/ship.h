#ifndef SHIP_H
#define SHIP_H
#include <string>
#include <time.h>
using namespace std;



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

        virtual std::string getType() const = 0;    //getter fuer typ namen
        virtual std::string getSpecial() const = 0; //getter fuer special attack namen
        bool isDestroyed(); //checkt ob schiff zerstoert ist
        virtual void specialAttack(int &enemyHP, int &shipSize) const = 0;  //special move

    protected:

    private:
};

#endif // SHIP_H
