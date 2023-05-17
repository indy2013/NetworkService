#ifndef DATA_H
#define DATA_H

#include <string>
#include <QString>

class data
{
public:
    data();
    std::string names(std::string msg);

private:
     QMap<QString, QString> playerData;
};

#endif // DATA_H
