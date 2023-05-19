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
    std::string DMSavingthrow(std::string sav,int Die);

    int Savingthrow;
    QMap<QString, QString> playerData;
};

#endif // DATA_H
