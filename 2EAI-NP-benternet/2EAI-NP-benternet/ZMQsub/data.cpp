#include "data.h"
#include "calculate.h"
#include <QList>
#include <QMap>
#include <Qstring>
#include <iostream>
#include <sstream>
#include <string>

data::data() {}

std::string data::names(std::string msg) {

  std::string delimiter = ">";
  size_t pos = 0;
  std::string token;
  QList<QString> List;
  while ((pos = msg.find(delimiter)) != std::string::npos) {
    token = msg.substr(0, pos);
    std::cout << token << std::endl;
    msg.erase(0, pos + delimiter.length());
    List.append(QString::fromStdString(msg));
  }
  if (List.size() > 4) {
    if (List[2] == "Pl" || List[2] == "PL") { // dubbel safety
      if (playerData.contains(List[3])) {

      } else {
        playerData.insert(List.at(3), List.at(4));
      }
    }
  } else {
  }
  // std::cout << msg << std::endl;
  return "";
}

std::string data::DMSavingthrow(std::string msg) {
    Calculate DieValue;
    int Die = DieValue.DieValue;
    std::string delimiter = ">";
    size_t pos = 0;
    std::string token;
    QList<QString> List;
    while ((pos = msg.find(delimiter)) != std::string::npos) {
      token = msg.substr(0, pos);
      std::cout << token << std::endl;
      msg.erase(0, pos + delimiter.length());
      List.append(QString::fromStdString(msg));
    }
    if (List[2] == "Dm" || List[2] == "DM") {
        Savingthrow = std::to_string(Die);
    }else{
        Savingthrow = "15";
    }
    return Savingthrow;
}
