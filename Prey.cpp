#include "Prey.h"

bool Prey::IsReproducible(void) 
{
    if (--TimeToReproduce <= 0) 
    {
        return 1;
    }
    return 0;
}