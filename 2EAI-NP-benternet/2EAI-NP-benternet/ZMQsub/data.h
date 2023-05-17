#ifndef DATA_H
#define DATA_H

#include <string>
#include <QString>
#include <QMap>

class data
{
public:
    data();
    std::string names(std::string msg);

     QMap<QString, QString> playerData;
};

#endif // DATA_H
