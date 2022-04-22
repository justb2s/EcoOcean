#ifndef PREY_H
#define PREY_H

#include "Cell.h"

class Prey : public Cell {
protected:
    int TimeToReproduce;
    bool Moves = 1;

    virtual Cell* reproduce(Coordinate anOffset) 
    { 
        return this; 
    }

public:
    Prey(int TimeToPeproduce = TIME_TO_REPRODUCE)
    {
        this->TimeToReproduce = TimeToPeproduce;
        _Image = DEFAULT_PREY_IMAGE;
    }

    virtual Cell* Copy(void) 
    { 
        return new Prey(TimeToReproduce); 
    }

    virtual bool IsHunger(void) 
    { 
        return 0; 
    }

    virtual bool IsMoving(void) 
    { 
        return Moves;
    }

    virtual void Moved ( void ) 
    { 
        Moves = 0;
    }

    virtual void ResetMoves(void) 
    {
        Moves = 1;
    }

    virtual bool IsHunting(void)
    { 
        return 0; 
    }

    virtual void Eaten(void) {}

    virtual bool IsReproducible(void);

    virtual void Reproduct(void) 
    { 
        TimeToReproduce = TIME_TO_REPRODUCE; 
    }

    virtual ~Prey(void) {}
};

#endif