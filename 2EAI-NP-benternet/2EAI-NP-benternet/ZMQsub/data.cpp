#include "data.h"
#include "calculate.h"
#include <QList>
#include <QMap>
#include <Qstring>
#include <iostream>
#include <sstream>
#include <string>

data::data(Calculate *calc) : calc(calc) {}

std::string data::names(std::string msg) {

  QList<QString> List = QString::fromStdString(msg).split('>');

  if (List[1] == "Pl" || List[1] == "PL") {
    if (playerData.contains(List[3])) {
      return playerData[List[3]].toStdString();
    } else {
      playerData.insert(List.at(3), List.at(4));
    }
  }

  // std::cout << msg << std::endl;
  return "0";
}

std::string data::DMSavingthrow(std::string msg) {
  // Calculate DieValue;
  int Die = calc->DieValue;
  QList<QString> List = QString::fromStdString(msg).split('>');
  if (List[1].toStdString() == "Dm" || List[1].toStdString() == "DM") {
    Savingthrow = std::to_string(Die);
  } else if (Savingthrow == "0") {
    Savingthrow = "15";
  }
  std::cout << "List[1]" << List[1].toStdString() /*.substr(0,2)*/ << std::endl;
  return Savingthrow;
}

std::string data::modifier(std::string msg) {

  QList<QString> List = QString::fromStdString(msg).split('>');
  QString data = playerData[List[3]].toStdString().c_str();
    QList<QString> mods = data.split(',');
    std::cout << "dit is de data: " << mods[0].toStdString()/*data.toStdString()*/ << std::endl;
  if (List.last() == "str") {
    return mods[0].toStdString();
  } else if (List.last() == "dex") {
    return mods[1].toStdString();
  } else if (List.last() == "con") {
    return mods[2].toStdString();
  } else if (List.last() == "int") {
    return mods[3].toStdString();
  } else if (List.last() == "wis") {
    return mods[4].toStdString();
  } else if (List.last() == "cha") {
    return mods[5].toStdString();
  } else {
    return "0";


  }
  return "0";
}
