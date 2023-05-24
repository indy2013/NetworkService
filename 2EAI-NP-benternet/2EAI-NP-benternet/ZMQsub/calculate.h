#ifndef CALCULATE_H
#define CALCULATE_H

#include <string>
#include <QString>

class Calculate
{
public:
    Calculate();
    int Die(std::string dice);

    int DieValue;
};

#endif // CALCULATE_H
