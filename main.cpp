#include <iostream>
#include "include/ship.h"
#include "include/jaeger.h"
#include "include/zerstoerer.h"
#include "include/kreuzer.h"
#include <vector>
#include <time.h>
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define WHITE   "\033[37m"

using namespace std;

void deleteFleet(std::vector<ship*>&fleet, std::vector<ship*>&enemyFleet, int fleetSize) //delete beide flotten um memory leak zu vermeiden
{
    for (int i = 0; i < fleetSize; i++) //geht durch beide flotten anhand der flottengroesse
    {
        delete fleet[i];
        delete enemyFleet[i];
    }
}

void showShips(std::vector<ship*>fleet, std::vector<ship*>enemyFleet, int fleetSize) //ausgabe der flotten inkl. ship information
{
    cout << BLUE << "__________________________________________________________\n";
    cout << WHITE << " Schiffstyp  Huelle  Groesse  Schaden  Spezial \n";
    for (int i = 0; i < fleetSize; i++)
    {
        if (fleet[i]->getType() == "Jaeger" && !fleet[i]->isDestroyed()) cout << GREEN << "| " << fleet[i]->getType() << "      " << fleet[i]->hp << "      " << fleet[i]->shipSize << "        " << fleet[i]->damage << "     " << fleet[i]->getSpecial() << " " << fleet[i]->specialAmount << "|\n";
        else if (fleet[i]->getType() == "Jaeger" && fleet[i]->isDestroyed()) cout << RED << "| " << fleet[i]->getType() << "      " << "0" << "      " << fleet[i]->shipSize << "        " << fleet[i]->damage << "     " << fleet[i]->getSpecial() << " " << fleet[i]->specialAmount << "|\n";
        if (fleet[i]->getType() == "Zerstoerer" && !fleet[i]->isDestroyed()) cout << GREEN << "| " << fleet[i]->getType() << "  " << fleet[i]->hp << "     " << fleet[i]->shipSize << "        " << fleet[i]->damage << "      " << fleet[i]->getSpecial() << " " << fleet[i]->specialAmount << "     |\n";
        else if (fleet[i]->getType() == "Zerstoerer" && fleet[i]->isDestroyed()) cout << RED << "| " << fleet[i]->getType() << "  " << "0" << "     " << fleet[i]->shipSize << "        " << fleet[i]->damage << "      " << fleet[i]->getSpecial() << " " << fleet[i]->specialAmount << "     |\n";
        if (fleet[i]->getType() == "Kreuzer" && !fleet[i]->isDestroyed()) cout << GREEN << "| " << fleet[i]->getType() << "     " << fleet[i]->hp << "     " << fleet[i]->shipSize << "        " << fleet[i]->damage << "      " << fleet[i]->getSpecial() << " " << fleet[i]->specialAmount << "    |\n";
        else if(fleet[i]->getType() == "Kreuzer" && fleet[i]->isDestroyed()) cout << RED << "| " << fleet[i]->getType() << "     " << "0" << "     " << fleet[i]->shipSize << "        " << fleet[i]->damage << "      " << fleet[i]->getSpecial() << " " << fleet[i]->specialAmount << "    |\n";
    }
    cout << BLUE<< "__________________________________________________________\n\n";
    cout << RED << "__________________________________________________________\n";
    cout << WHITE << "   E N E M Y  S H I P S\n";
    for (int i = 0; i < fleetSize; i++)
    {
        if (enemyFleet[i]->getType() == "Jaeger" && !enemyFleet[i]->isDestroyed()) cout << RED << "| " << enemyFleet[i]->getType() << "      " << enemyFleet[i]->hp << "      " << enemyFleet[i]->shipSize << "        " << enemyFleet[i]->damage << "     " << enemyFleet[i]->getSpecial() << " " << enemyFleet[i]->specialAmount << "|\n";
        else if (enemyFleet[i]->getType() == "Jaeger" && enemyFleet[i]->isDestroyed()) cout << WHITE << "| " << enemyFleet[i]->getType() << "      " << "0   " << "      " << enemyFleet[i]->shipSize << "        " << enemyFleet[i]->damage << "     " << enemyFleet[i]->getSpecial() << " " << enemyFleet[i]->specialAmount << "|\n";
        if (enemyFleet[i]->getType() == "Zerstoerer" && !enemyFleet[i]->isDestroyed()) cout << RED << "| " << enemyFleet[i]->getType() << "  " << enemyFleet[i]->hp << "     " << enemyFleet[i]->shipSize << "        " << enemyFleet[i]->damage << "      " << enemyFleet[i]->getSpecial() << " " << enemyFleet[i]->specialAmount << "     |\n";
        else if (enemyFleet[i]->getType() == "Zerstoerer" && enemyFleet[i]->isDestroyed()) cout << WHITE << "| " << enemyFleet[i]->getType() << "  " << "0  " << "     " << enemyFleet[i]->shipSize << "        " << enemyFleet[i]->damage << "      " << enemyFleet[i]->getSpecial() << " " << enemyFleet[i]->specialAmount << "     |\n";
        if (enemyFleet[i]->getType() == "Kreuzer" && !enemyFleet[i]->isDestroyed()) cout << RED << "| " << enemyFleet[i]->getType() << "     " << enemyFleet[i]->hp << "     " << enemyFleet[i]->shipSize << "        " << enemyFleet[i]->damage << "      " << enemyFleet[i]->getSpecial() << " " << enemyFleet[i]->specialAmount << "    |\n";
        else if (enemyFleet[i]->getType() == "Kreuzer" && enemyFleet[i]->isDestroyed()) cout << WHITE << "| " << enemyFleet[i]->getType() << "     " << "0" << "     " << enemyFleet[i]->shipSize << "        " << enemyFleet[i]->damage << "      " << enemyFleet[i]->getSpecial() << " " << enemyFleet[i]->specialAmount << "    |\n";
    }
    cout << "__________________________________________________________\n\n";
}

void playerTurn(std::vector<ship*>fleet, std::vector<ship*>enemyFleet, int fleetSize)
{
    int playerShip, enemyShip, attackType;
    srand(time(0));

inputAgain:;    //goto stelle fuer falsche inputs
    cout << WHITE << "Choose Your Ship: ";
    cin >> playerShip;
    cout << "\n\nAttack Ship: ";
    cin >> enemyShip;
    cout << "\n\nNormal Attack or Special Attack? ( 1 = Normal  2 = Special): ";
    cin >> attackType;

    if (playerShip < 1 || playerShip > fleetSize || enemyShip < 1 || enemyShip > fleetSize) //falls nicht existierendes schiff targeted wird
    {
        cout << "Input is Out of Bounds!\n"; //error
        goto inputAgain;    //go back to input
    }
    if (enemyFleet[enemyShip-1]->isDestroyed() || fleet[playerShip-1]->isDestroyed())   //falls zerstoertes schiff targeted wird
    {
        cout << "Ships is Destroyed! Try another Ship.\n"; //error
        goto inputAgain;    //go back to input
    }

    if (attackType == 1 && (rand()%10+1)>=enemyFleet[enemyShip-1]->shipSize && !fleet[playerShip-1]->isDestroyed()) //wenn normaler angriff, treffercheck stimmt und das angregriffene schiff nicht zerstoert ist -> ziehe HP vom gegner schiff ab
    {
        enemyFleet[enemyShip-1]->hp = enemyFleet[enemyShip-1]->hp - fleet[playerShip-1]->damage;    //zieht hp vom ziel ab
    }
    else if (attackType == 2 && !fleet[playerShip-1]->isDestroyed() && fleet[playerShip-1]->specialAmount > 0)  //special attacke, kann nur 3 mal pro schiff eingesetzt werden
    {
        fleet[playerShip-1]->specialAttack(enemyFleet[enemyShip-1]->hp, enemyFleet[enemyShip-1]->shipSize);
        fleet[playerShip-1]->specialAmount--;
    }
    else if (attackType == 2 && fleet[playerShip-1]->specialAmount == 0)   //falls special move versucht wird, aber kein special move mehr verfuegbar ist
    {
        cout << "\nNo More Special Moves!\n";
        goto inputAgain;    //go back to input
    }
}

void enemyTurn(std::vector<ship*>fleet, std::vector<ship*>enemyFleet, int fleetSize)
{
    srand(time(0));
    int playerShip, enemyShip, attackType;

    while (true)    //solange keine nicht zerstoerten schiffe randomized werden, randomize again
    {
        playerShip = rand() % fleetSize;    //such random zahl anhand der groesse der flotten
        enemyShip = rand() % fleetSize;
        if (!enemyFleet[enemyShip]->isDestroyed() && !fleet[playerShip]->isDestroyed())
        {
            break;  //wenn beide schiffe nicht zerstoert sind, breche den loop
        }
    }
    if (enemyFleet[enemyShip]->specialAmount > 0) attackType = rand() %2+1; //wenn special moves vom schiff noch verfuegbar sind, random 1 oder 2
    else attackType = 1;    //ansonsten nur normale attacke

    if (attackType == 1 && (rand()%10+1)>=fleet[playerShip]->shipSize)
    {
        fleet[playerShip]->hp = fleet[playerShip]->hp - enemyFleet[enemyShip]->damage;
    }
    else if (attackType == 2)
    {
        enemyFleet[enemyShip]->specialAttack(fleet[playerShip]->hp, fleet[playerShip]->shipSize);
        enemyFleet[enemyShip]->specialAmount--;
    }
}

bool playerFleetDefeated(std::vector<ship*>fleet, int fleetSize)
{
    int destroyedShips = 0;
    for (int i = 0; i < fleetSize; i++) //wenn menge and zerstoerten schiffen mit flottengroesse uebereinstimmt, sind ALLE schiffe zerstoert
    {
        if (fleet[i]->isDestroyed()) destroyedShips++;
    }
    return destroyedShips == fleetSize; //return true oder false ob diese aussage stimmt
}

bool enemyFleetDefeated(std::vector<ship*>enemyFleet, int fleetSize)    //funktioniert gleich wie playerFleetDefeated function
{
    int destroyedShips = 0;
    for (int i = 0; i < fleetSize; i++)
    {
        if (enemyFleet[i]->isDestroyed() == true) destroyedShips++;
    }
    return destroyedShips == fleetSize;
}

void clearScreen()  //formatting
{
    std::cout << "\033[2J\033[H";
}

int main()
{
    int fleetSize;  //flottengroesse

    cout << GREEN << "Welcome to Flottenkamp!\n\n";
    system("pause");
    clearScreen();

    cout << "How many ships do you want per fleet? (Maximum 9)\n";
    cin >> fleetSize;
    if (fleetSize > 9) fleetSize = 9; //falls groesser als 9, ist die flotte 9 schiffe gross
    clearScreen();
    std::vector<ship*> fleet(fleetSize);  //vector bestehend aus ship pointern mit der groesse der fleetSize
    std::vector<ship*> enemyFleet(fleetSize);

    for (int i = 0; i < fleetSize; i++)
    {
        int input;
        cout << "Choose Ship Type for Ship Number " << (i +1) << "\n1 = Jaeger, 2 = Zerstoerer, 3 = Kreuzer\n";
        cin >> input;
        clearScreen();

        switch(input)   //assigned jedem schiff seinen typen
        {
        case 1:
            fleet[i] = new jaeger();
            break;
        case 2:
            fleet[i] = new zerstoerer();
            break;
        case 3:
            fleet[i] = new kreuzer();
            break;
        }
    }
    srand(time(0));
    for(int i = 0; i < fleetSize; i++)  //gegnerische flotte ist genauso gross wie die vom spieler, die zusammensetzung ist aber random
    {
        int randomShip = rand() % 3 + 1;
        switch(randomShip)
        {
        case 1:
            enemyFleet[i] = new jaeger();
            break;
        case 2:
            enemyFleet[i] = new zerstoerer();
            break;
        case 3:
            enemyFleet[i] = new kreuzer();
            break;
        }
    }

    while (!playerFleetDefeated(fleet, fleetSize) && !enemyFleetDefeated(enemyFleet, fleetSize))    //solange nicht einer der flotten besiegt ist, geht das spiel weiter
    {
        clearScreen();
        showShips(fleet, enemyFleet, fleetSize);    //anzeige der schiffe
        playerTurn(fleet, enemyFleet, fleetSize);   //spieler turn
        if (!enemyFleetDefeated(enemyFleet, fleetSize)) enemyTurn(fleet, enemyFleet, fleetSize); //falls der spieler nach seinem turn den gegner nicht besiegt hat -> enemy turn (ansonsten kommt es zur endlosschleife ohne dem check wenn der gegner besiegt wird
    }

    if (playerFleetDefeated(fleet, fleetSize))  //falls spieler verliert
    {
        clearScreen();
        cout << RED << "You Have Been Defeated.\n";
    }

    else if (enemyFleetDefeated(enemyFleet, fleetSize)) //falls gegner verliert
    {
        clearScreen();
        cout << GREEN << "You Have Defeated The Enemy!\n";
    }

    deleteFleet(fleet, enemyFleet, fleetSize);  //loescht beide vektoren wieder aus dem speicher
    return 0;
}