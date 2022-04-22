#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate 
{
private:
    int _x;
    int _y;

public:
    Coordinate(int aX, int aY) :_x(aX), _y(aY) {}
    Coordinate(void) 
    { 
        _x = 0; _y = 0; 
    }
    Coordinate(const Coordinate& aCoord) 
    {
        this->_x = aCoord._x;
        this->_y = aCoord._y;
    }

    ~Coordinate(void) {}

    int getX(void) 
    {
        return _x;
    }
    int getY(void) 
    { 
        return _y; 
    }
    void setX(int aX) 
    { 
        _x = aX; 
    }
    void setY(int aY) 
    {
        _y = aY;
    }

    Coordinate North()
    {
        int y;

        if (this->getY() == 0)
        {
            y = 0;
        }
        else 
        {
            y = this->getY() - 1;
        }
        return Coordinate(this->_x, y);
    }

    Coordinate South(int NumCols) 
    {
        int y;
        
        if (this->_y >= (NumCols - 1)) 
        {
            y = NumCols - 1;
        }
        else
        {
            y = this->_y + 1;
        }
        return Coordinate(this->_x, y);
    }

    Coordinate West()
    {
        int x;

        if (this->_x == 0) 
        {
            x = 0;
        }
        else 
        {
            x = this->_x - 1;
        }
        return Coordinate(x, this->_y);
    }

    Coordinate East(int NumRows)
    {
        int x;

        if (this->_x >= (NumRows - 1))
        {
            x = (NumRows - 1);
        }
        else 
        {
            x = this->_x + 1;
        }
        return Coordinate(x, this->_y);
    }

    void operator = (const Coordinate& aCoord)
    {
        _x = aCoord._x;
        _y = aCoord._y;
    }

    bool operator == (const Coordinate& aCoord) 
    {
        return _x == aCoord._x && _y == aCoord._y;
    }

    bool operator < (const Coordinate& aCoord) const noexcept 
    {
        if (_x < aCoord._x) return true;
        if (_x > aCoord._x) return false;
        
        if (_y < aCoord._y) return true;
        if (_y > aCoord._y) return false;
        
        return false;
    }

    bool operator != (const Coordinate& aCoord) 
    {
        return _x != aCoord._x || _y != aCoord._y;
    }
};

#endif