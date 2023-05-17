#include "data.h"
#include <string>
#include <iostream>
#include <sstream>
#include <string>
#include <Qstring>
#include <QMap>
#include <QList>
data::data()
{

}

std::string data::names(std::string msg)
{
    int i = 0;
    QMap<QString, int> playerData;

    std::string delimiter = ">";

    size_t pos = 0;
    std::string token;
    QList<QString> List;
    while ((pos = msg.find(delimiter)) != std::string::npos) {
        i++;
        token = msg.substr(0, pos);
        std::cout << token << std::endl;
        msg.erase(0, pos + delimiter.length());
        List.append( QString::fromStdString(msg));
    }
    QString
     //QString::fromStdString
//    if(i == 3){
//         std::cout << msg << std::endl;
//         QMap<QString, int> playerData;
//         playerData.insert(msg,)
//         playerData.value()
//          return msg;
//    }
    std::cout << msg << std::endl;
    return "";
}
