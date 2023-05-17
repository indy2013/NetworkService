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
    if(List.size() > 4){
    playerData.insert(List.at(3),List.at(4));
    }
    std::cout << msg << std::endl;
    return "";
}
