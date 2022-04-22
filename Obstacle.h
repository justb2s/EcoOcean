#ifndef OBSTACLE_H
#define OBSTACLE_H

#include"Cell.h"

class Obstacle : public Cell 
{
public:
    Obstacle()
    {
        _Image = DEFAULT_OBSTACLE_IMAGE;
    }

    Cell* reproduce(Coordinate anOffset) 
    {
        return this; 
    }

    Cell* Copy(void)
    {
        return new Obstacle();
    }

    bool IsHunger(void)
    { 
        return 0; 
    }

    bool IsMoving(void) 
    {
        return 0;
    }

    void Moved(void) {}

    void ResetMoves(void) {}

    bool IsHunting(void) 
    { 
        return 0; 
    }

    virtual void Eaten(void) {}

    bool IsReproducible(void) 
    {
        return 0;
    }

    void Reproduct(void) { }

    ~Obstacle(void) {}
};

#endif