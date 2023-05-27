#ifndef DATA_H
#define DATA_H

#include "calculate.h"
#include <string>
#include <QString>
#include <QMap>

class data
{
public:
    data();
    data(Calculate*calc);
    std::string names(std::string msg);
    std::string modifier(std::string msg);
    std::string DMSavingthrow(std::string sav,int DieCalc);

    std::string Savingthrow = "0";
    QMap<QString, QString> playerData;
    Calculate*calc;
};

#endif // DATA_H
