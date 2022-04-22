#ifndef GLOGIC_H
#define GLOGIC_H
#include"Ocean.h"
#include"Prey.h"
#include"Predator.h"
#include"Obstacle.h"

#include<iostream>
#include<vector>
#include<array>
#include<string>

class OceanLogic
{
private:
    int _NumPrey;
    int _NumPredators;
    int _NumObstacles;
    Ocean _OMap;
        
    void FindNumPrey(void);
    void FindNumPredators(void);

public:
    OceanLogic(int NumPrey = 0, 
               int NumPredators = 0, 
               int NumObstacles = 0, 
               int NumCols = DEFAULT_COLS, 
               int NumRows = DEFAULT_ROWS) {
        _OMap.SetNumCols(NumCols);
        _OMap.SetNumRows(NumRows);

        this->_NumPrey = NumPrey;
        this->_NumObstacles = NumObstacles;
        this->_NumPredators = NumPredators;
    }

    void InitOcean(void);

    void UpdateOcean(void);

    void ResetOcean(void);
    
    std::vector<std::string> GetCurrentOceanMap(void);

    int SetNumRows(int NumOfRows) 
    {
        _OMap.SetNumRows(NumOfRows);
        return _OMap.GetNumRows();
    }

    int SetNumCols(int NumOfCols) 
    {
        _OMap.SetNumCols(NumOfCols);
        return _OMap.GetNumCols();
    }

    int GetNumPrey ( void ) 
    { 
        return _NumPrey; 
    }

    void SetNumPrey(int NumOfPrey) 
    {
        if (NumOfPrey <= 0 || NumOfPrey > (_OMap.GetSize() - _NumPredators - _NumObstacles)) 
        {
            this->_NumPrey = (_OMap.GetSize() - _NumPredators - _NumObstacles);
        }
        else 
        {
            this->_NumPrey = NumOfPrey;
        }
        _OMap.ClearOcean();
    }

    int GetNumPredators ( void ) 
    { 
        return _NumPredators; 
    }

    void SetNumPredators(int NumOfPredators) 
    {
        if (NumOfPredators <= 0 || NumOfPredators > (_OMap.GetSize() - _NumPrey - _NumObstacles)) 
        {
            this->_NumPredators = (_OMap.GetSize() - _NumPrey - _NumObstacles);
        }
        else 
        {
            this->_NumPredators = NumOfPredators;
        }
        _OMap.ClearOcean();
    }

    int GetNumObstacles(void)
    { 
        return _NumObstacles; 
    }

    void SetNumObstacles(int NumOfObstacles) 
    {
        if (NumOfObstacles <= 0 || NumOfObstacles > (_OMap.GetSize() - _NumPredators - _NumPrey)) 
        {
            this->_NumObstacles = (_OMap.GetSize() - _NumPredators - _NumPrey);
        }
        else 
        {
            this->_NumObstacles = NumOfObstacles;
        }
        _OMap.ClearOcean();
    }

    ~OceanLogic( void ) {};
};

#endif