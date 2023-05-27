#include "data.h"
#include "calculate.h"
#include <QList>
#include <QMap>
#include <Qstring>
#include <iostream>
#include <sstream>
#include <string>

data::data(){}


std::string data::names(std::string msg) {

  QList<QString> List = QString::fromStdString(msg).split('>');

//  std::cout << std::endl << " DEBUG TEST" << std:: endl;
//      for (int i = 0; i < List.size(); ++i) {
//          std::cout << List.value(i).toStdString() << std::endl;
//      }
//  std::cout << std::endl << " DEBUG TEST" << std:: endl;

  if (List.value(1) == "Pl" || List.value(1) == "PL") {

    if (playerData.contains(List.value(3))) {
std::cout << "die is er in gegaan"<< std::endl;
      return playerData[List.value(3)].toStdString();
    } else {
      playerData.insert(List.value(3), List.value(4));
      std::cout << "dit is de list3 name data: "
                    << playerData[List.value(3)].toStdString() /*data.toStdString()*/ << std::endl;

    }
  }

  // std::cout << msg << std::endl;
  return "0";
}

std::string data::DMSavingthrow(std::string msg,int DieCalc){
  // Calculate DieValue;
  int Die = DieCalc;//calc->DieValue;
  std::cout<< Die << std::endl;
  QList<QString> List = QString::fromStdString(msg).split('>');
  if (List[1].toStdString() == "Dm" || List[1].toStdString() == "DM") {
    Savingthrow = std::to_string(Die);
  } else if (Savingthrow == "0") {

    return Savingthrow;
  }
  std::cout << "List[1]" << List[1].toStdString() /*.substr(0,2)*/ << std::endl;
  return Savingthrow;
}

std::string data::modifier(std::string msg) {

  QList<QString> List = QString::fromStdString(msg).split('>');
  if (List[1].toStdString() == "Dm" || List[1].toStdString() == "DM") {
    return "0";
  } else {

//      std::cout << "dit is de list name data2: "
//                    << playerData[List[3]].toStdString() /*data.toStdString()*/ << std::endl;
    QList<QString> mods = playerData[List[3]].split(',');


    if (List.last() == "str") {
         std::cout << "dit is de data: "<< mods[0].toStdString() << std::endl;
      return mods[0].toStdString();
    } else if (List.last() == "dex") {
         std::cout << "dit is de data: "<< mods[1].toStdString() << std::endl;
      return mods[1].toStdString();
    } else if (List.last() == "con") {
         std::cout << "dit is de data: "<< mods[2].toStdString() << std::endl;
      return mods[2].toStdString();
    } else if (List.last() == "int") {
         std::cout << "dit is de data: "<< mods[3].toStdString() << std::endl;
      return mods[3].toStdString();
    } else if (List.last() == "wis") {
         std::cout << "dit is de data: "<< mods[4].toStdString() << std::endl;
      return mods[4].toStdString();
    } else if (List.last() == "cha") {
         std::cout << "dit is de data: "<< mods[5].toStdString() << std::endl;
      return mods[5].toStdString();
    } else {
      return "0";
    }
  }
  return "0";
}
