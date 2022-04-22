#include "OceanLogic.h"

void OceanLogic::InitOcean(void) 
{
    _OMap.AddEmptyCells();

    _OMap.AddDistinctCell<Obstacle>(_NumObstacles);
    _OMap.AddDistinctCell<Predator>(_NumPredators);
    _OMap.AddDistinctCell<Prey>(_NumPrey);
}

void OceanLogic::UpdateOcean(void) 
{
    for (int x = 0; x < _OMap.GetNumCols(); x++) 
    {
        for (int y = 0; y < _OMap.GetNumRows(); y++)
        {
            _OMap.Process(Coordinate(x, y));
        }
    }
    _OMap.ResetMoves();
    FindNumPredators();
    FindNumPrey();
}

void OceanLogic::ResetOcean(void) 
{
    _OMap.ClearOcean();
}

std::vector<std::string> OceanLogic::GetCurrentOceanMap(void)
{
    std::vector<std::string> Map;
    std::string Column;

    for (int x = 0; x < _OMap.GetNumCols(); x++) {
        Column = "";
        for(int y = 0; y < _OMap.GetNumRows(); y++) {
            Column += _OMap.GetCharOfCell(Coordinate(x, y));
        }
        Map.push_back(Column);
    }
    return Map;
}

void OceanLogic::FindNumPrey(void) 
{
    int count = 0;

    for (int x = 0; x < _OMap.GetNumCols(); x++) 
    {
        for (int y = 0; y < _OMap.GetNumRows(); y++) 
        {
            if (_OMap.GetCharOfCell(Coordinate(x, y)) == DEFAULT_PREY_IMAGE) 
            {
                count++;
            }
        }
    }

    this->_NumPrey = count;
}

void OceanLogic::FindNumPredators(void) 
{
    int count = 0;

    for (int x = 0; x < _OMap.GetNumCols(); x++) 
    {
        for (int y = 0; y < _OMap.GetNumRows(); y++) 
        {
            if (_OMap.GetCharOfCell(Coordinate(x, y)) == DEFAULT_PRDATOR_IMAGE) 
            {
                count++;
            }
        }
    }

    this->_NumPredators = count;
}