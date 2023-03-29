#include "dice.h"

Dice::Dice()
{

}

int Dice::D4()
{
    srand(time(NULL));
   return rand() % 4 + 1;
}

int Dice::D6()
{
    srand(time(NULL));
    return rand() % 6 + 1;
}

int Dice::D8()
{
    srand(time(NULL));
   return rand() % 8 + 1;
}

int Dice::D12()
{
    srand(time(NULL));
    return rand() % 12 + 1;

}

int Dice::D20()
{
    srand(time(NULL));
    return rand() % 20 + 1;
}

