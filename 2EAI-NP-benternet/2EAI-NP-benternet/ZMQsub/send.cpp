#include "send.h"
#include <QList>
#include <QString>

Send::Send() {}

std::string Send::MsgContruct(std::string msg, int DieCalc,
                              std::string SavingthrowValue) {
  QList<QString> List = QString::fromStdString(msg).split('>');
  if (List[1].toStdString() == "Dm" || List[1].toStdString() == "DM") {

    std::string str1 = "!IndyPenders>DND>";
    std::string str2 = "Dm changed savingthrow succeed to: ";
    std::string str3 = std::to_string(DieCalc).c_str();
    std::string message = str1 + str2 + str3;

    return message;
  } else {
    if (DieCalc != 0) {
      if (DieCalc < std::stoi(SavingthrowValue)) {
        std::string str1 = "!IndyPenders>DND>";
        std::string str2 = "You Failed the saving throw, you needed: ";
        int Total = std::stoi(SavingthrowValue);
        std::string TotalSend = std::to_string(Total);
        std::string str3 = TotalSend.c_str();
        std::string str4 = "\n You rolled a: ";
        std::string str5 = std::to_string(DieCalc).c_str();
        std::string message = str1 + str2 + str3 + str4 + str5;
        return message;

      } else {
        std::string str1 = "!IndyPenders>DND>";
        std::string str2 = "You succeeded the saving throw, you needed: ";
        int Total = std::stoi(SavingthrowValue);
        std::string TotalSend = std::to_string(Total);
        std::string str3 = TotalSend.c_str();
        std::string str4 = "\n You rolled a: ";
        std::string str5 = std::to_string(DieCalc).c_str();

        std::string message = str1 + str2 + str3 + str4 + str5;
        return message;
      }
    }
    return "something went wrong";
  }

}
