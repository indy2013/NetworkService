#include "duel.h"
#include "data.h"
#include "calculate.h"
#include <QList>
#include <QMap>
#include <Qstring>
#include <iostream>
#include <sstream>
#include <string>

Duel::Duel(data& playerDataInstanceRef, Calculate& calculateInstanceRef)
    : playerDataInstance(playerDataInstanceRef),
      calculateInstance(calculateInstanceRef)
{

}
std::string Duel::DuelFight(std::string msg) {

    std::cout<< "entered DuelFight" << std::endl;

    QList<QString> List = QString::fromStdString(msg).split('>');

 std::cout<< List[4].toStdString() << std::endl;
 std::cout<< List[2].toStdString() << std::endl;
 std::cout<< List[3].toStdString() << std::endl;

    int diceResult1 = calculateInstance.Die(List[4].toStdString());
    int diceResult2 = calculateInstance.Die(List[4].toStdString());
    QList<QString> mods1 = playerDataInstance.playerData[List[2]].split(',');
    QString prof1 = playerDataInstance.playerProf[List[2]];

    QList<QString> mods2 = playerDataInstance.playerData[List[3]].split(',');
    QString prof2 = playerDataInstance.playerProf[List[3]];

std::cout<< "Qlist done" << std::endl;
if (List[5] == "str") {
    diceResult1 = diceResult1 + mods1[0].toInt();
}else if (List[5] == "dex") {
    diceResult1 = diceResult1 + mods1[1].toInt();
}else if (List[5] == "con") {
    diceResult1 = diceResult1 + mods1[2].toInt();
}else if (List[5] == "int") {
    diceResult1 = diceResult1 + mods1[3].toInt();
}else if (List[5] == "wis") {
    diceResult1 = diceResult1 + mods1[4].toInt();
}else if (List[5] == "cha") {
    diceResult1 = diceResult1 + mods1[5].toInt();
}else if (List[5] == "str+") {
    diceResult1 = diceResult1 + mods1[0].toInt() + prof1.toInt();
}else if (List[5] == "dex+") {
    diceResult1 = diceResult1 + mods1[1].toInt()+ prof1.toInt();
}else if (List[5] == "con+") {
    diceResult1 = diceResult1 + mods1[2].toInt()+ prof1.toInt();
}else if (List[5] == "int+") {
    diceResult1 = diceResult1 + mods1[3].toInt()+ prof1.toInt();
}else if (List[5] == "wis+") {
    diceResult1 = diceResult1 + mods1[4].toInt()+ prof1.toInt();
}else if (List[5] == "cha+") {
    diceResult1 = diceResult1 + mods1[5].toInt()+ prof1.toInt();
}else{
    diceResult1 = 0;
}
std::cout<< "Half done" << std::endl;

if (List[6] == "str") {
    diceResult2 = diceResult2 + mods1[0].toInt();
}else if (List[6] == "dex") {
    diceResult2 = diceResult2 + mods1[1].toInt();
}else if (List[6] == "con") {
    diceResult2 = diceResult2 + mods1[2].toInt();
}else if (List[6] == "int") {
    diceResult2 = diceResult2 + mods1[3].toInt();
}else if (List[6] == "wis") {
    diceResult2 = diceResult2 + mods1[4].toInt();
}else if (List[6] == "cha") {
    diceResult2 = diceResult2 + mods1[5].toInt();
}else if (List[6] == "str+") {
    diceResult2 = diceResult2 +  mods1[0].toInt() + prof2.toInt();
}else if (List[6] == "dex+") {
    diceResult2 = diceResult2 + mods1[1].toInt()+ prof2.toInt();
}else if (List[6] == "con+") {
    diceResult2 = diceResult2 + mods1[2].toInt()+ prof2.toInt();
}else if (List[6] == "int+") {
    diceResult2 = diceResult2 + mods1[3].toInt()+ prof2.toInt();
}else if (List[6] == "wis+") {
    diceResult2 = diceResult2 + mods1[4].toInt()+ prof2.toInt();
}else if (List[6] == "cha+") {
    diceResult2 = diceResult2 + mods1[5].toInt()+ prof2.toInt();
}else{
    diceResult2 = 0;
}
std::string str0 = "!IndyPenders>DND>";
std::cout<< "Making msg" << std::endl;
std::string str1 = "Player 1 Rolled: ";
std::string str2 = std::to_string(diceResult1);
std::string str3 = " and Player 2 Rolled: ";
std::string str4 = std::to_string(diceResult2);
std::string str5 = str0 + str1 + str2 + str3 + str4;

return str5;

}
