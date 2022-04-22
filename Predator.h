#ifndef PREDATOR_H
#define PREDATOR_H

#include"Prey.h"

class Predator :public Prey 
{
private:
    virtual Cell* reproduce(Coordinate anOffset) 
    {
        return this; 
    }

protected:
    int TimeToFeed;

public:
    Predator(int TimeToFeed = TIME_TO_FEED, int TimeToReReproduce = TIME_TO_REPRODUCE) 
    {
        this->TimeToFeed = TimeToFeed;
        this->TimeToReproduce = TimeToReReproduce;
        _Image = DEFAULT_PRDATOR_IMAGE;
    }

    Cell* Copy(void) 
    { 
        return new Predator(TimeToFeed, TimeToReproduce); 
    }

    bool IsHunger(void);

    bool IsMoving(void) 
    {
        return Moves;
    }

    void Moved(void) 
    {
        Moves = 0;
    }

    void ResetMoves(void) 
    {
        Moves = 1;
    }

    bool IsHunting(void) 
    { 
        return 1;
    }

    void Eaten(void) 
    {
        TimeToFeed = TIME_TO_FEED;
    }

    bool IsReproducible(void);

    void Reproduct(void)
    {
        TimeToReproduce = TIME_TO_REPRODUCE;
    }

    virtual ~Predator(void) {}

};

#endif