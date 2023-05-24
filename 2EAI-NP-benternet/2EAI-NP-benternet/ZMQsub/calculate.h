#ifndef CALCULATE_H
#define CALCULATE_H

#include <string>
#include <QString>

class Calculate
{
public:
    Calculate();
    int Die(std::string dice);
    int modifier(std::string msg);
    int DieValue;
};

#endif // CALCULATE_H
