#include "calculate.h"
#include "data.h"
#include <QMap>
#include <Qstring>
#include <iostream>
#include <sstream>
#include <string>

Calculate::Calculate()
{

}

int Calculate::Die(std::string dice)
{
   int Total = 0;
   int Roll = 0;
    int AmountOfDie = std::stoi(dice.substr(0,1).c_str());
   int ValueOfDice = std::stoi(dice.substr(2,3).c_str());
//getline in for loop is ook optie. (deze zorgt ook voor grotere die amount)
   for(int i = 0;i < AmountOfDie; i++){

       Roll = rand() % ValueOfDice + 1;
       Total = Total + Roll;
   }
    DieValue = Total;
    return Total;

}

int Calculate::modifier(std::string msg){




}
