#include "data.h"
#include "calculate.h"
#include <QList>
#include <QMap>
#include <Qstring>
#include <iostream>
#include <sstream>
#include <string>

data::data(Calculate*calc) : calc(calc) {}

std::string data::names(std::string msg) {

  std::string delimiter = ">";
  size_t pos = 0;
  std::string token;
  QList<QString> List = QString::fromStdString(msg).split('>');

  if (List.size() > 4) {
    if (List[1] == "Pl" || List[1] == "PL") { // dubbel safety
      if (playerData.contains(List[2])) {
        return playerData[List[2]].toStdString();
      } else {
        playerData.insert(List.at(2), List.at(3));
      }
    }
  }
  // std::cout << msg << std::endl;
  return "0";
}

std::string data::DMSavingthrow(std::string msg) {
    //Calculate DieValue;
    int Die = calc->DieValue;
    QList<QString> List = QString::fromStdString(msg).split('>');
    if (List[1].toStdString() == "Dm" || List[1].toStdString() == "DM") {
        Savingthrow = std::to_string(Die);
    }else{
        Savingthrow = "15";
    }
    std::cout << "List[1]" << List[1].toStdString()/*.substr(0,2)*/ << std::endl;
    return Savingthrow;
}
