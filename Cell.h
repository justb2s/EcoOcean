#ifndef CELL_H
#define CELL_H

#include"Coordinate.h"
#include"Constants.h"

class Cell {
protected:
    char _Image = DEFAULT_IMAGE;
public:
    virtual char getImage(void) 
    { 
        return _Image;
    }

    virtual Cell* Copy ( void ) = 0;

    virtual Cell* reproduce(Coordinate anOffset) = 0;

    virtual bool IsHunger ( void ) = 0;

    virtual bool IsMoving ( void ) = 0;

    virtual void Moved(void) = 0;

    virtual void ResetMoves(void) = 0;

    virtual bool IsHunting ( void ) = 0;

    virtual void Eaten(void) = 0;

    virtual bool IsReproducible( void ) = 0;

    virtual void Reproduct(void) = 0;

    virtual ~Cell(void) {}
};

#endif