#ifndef DICE_H
#define DICE_H

#include <cstdlib>
#include <iostream>
#include <zmq.hpp>

class Dice
{
public:
    Dice();
    int D4();
    int D6();
    int D8();
    int D12();
    int D20();
};

#endif // DICE_H
