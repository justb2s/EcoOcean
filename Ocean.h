#ifndef OCEAN_H
#define OCEAN_H
#include"Cell.h"
#include"Coordinate.h"
#include"Random.h"
#include"Constants.h"

#include<iostream>
#include<map>

class Ocean {
private:
    int _NumRows;
    int _NumCols;
    std::map<Coordinate, Cell*> _Cells;

    Random _Random;
    Coordinate GetEmptyCellCoord(void);
    Coordinate GetNeighborWithImage(Coordinate aCoord, char anImage);
    Coordinate GetEmptyNeighborCoord(Coordinate aCoord);
    Coordinate GetPreyNeighborCoord(Coordinate aCoord);
    Cell* GetCellAt(Coordinate aCoord);
    void AssignCellAt(Coordinate aCoord, Cell* aCell);
    void MoveCell(Coordinate From, Coordinate To);

public:
    Ocean(int NumRows = DEFAULT_ROWS, int NumCols = DEFAULT_COLS) 
    {
        SetNumRows(NumRows);
        SetNumCols(NumCols);
    }

    void AddEmptyCells(void);
    template <typename T> void AddDistinctCell(int NumOfCells) 
    {
        Coordinate empty;
        for (int count = 0; NumOfCells > count; count++)
        {
            empty = GetEmptyCellCoord();
            AssignCellAt(Coordinate(empty), new T());
        }
    }

    void Process(Coordinate aCell);
    void ResetMoves( void );

    int GetNumRows(void) 
    {
        return _NumRows;
    }

    int GetNumCols(void) 
    {
        return _NumCols;
    }

    int GetSize(void) 
    {
        return _NumCols * _NumRows;
    }

    void SetNumRows(int NumRows) 
    {
        ClearOcean();
        if (0 >= NumRows || DEFAULT_ROWS < NumRows)
        {
            this->_NumRows = DEFAULT_ROWS;
        }
        else {
            this->_NumRows = NumRows;
        }
    }

    void SetNumCols(int NumCols) 
    {
        ClearOcean();
        if (0 >= NumCols || DEFAULT_COLS < NumCols)
        {
            this->_NumCols = DEFAULT_COLS;
        }
        else 
        {
            this->_NumCols = NumCols;
        }
    }

    void ClearOcean(void);

    char GetCharOfCell(Coordinate aCell);

    ~Ocean (void) 
    { 
        ClearOcean(); 
    }
};

#endif