#ifndef DUEL_H
#define DUEL_H

#include "calculate.h"
#include "data.h"
#include <string>
#include <QString>
#include <QMap>

class Duel
{
public:
    Duel(data& playerDataInstance, Calculate& calculateInstance);  // Constructor that takes reference to an instance of data class

    std::string DuelFight(std::string msg);

    Calculate*calc;

private:
    data& playerDataInstance;
    Calculate& calculateInstance;
};

#endif // DUEL_H
