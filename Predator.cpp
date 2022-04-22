#include"Predator.h"
#include<iostream>

bool Predator::IsHunger(void) 
{
    if (--TimeToFeed <= 0) 
    {
        return 1;
    }
    return 0;
}

bool Predator::IsReproducible(void) 
{
    if (--TimeToReproduce <= 0) 
    {
        return 1;
    }
    return 0;
}



