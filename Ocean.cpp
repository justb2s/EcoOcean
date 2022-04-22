#include"Ocean.h"
#include"Prey.h"
#include"Predator.h"
#include"Obstacle.h"

Coordinate Ocean::GetEmptyCellCoord(void) 
{
    int x, y;
    Coordinate empty;

    do {
        x = _Random.NextBetween(0, _NumCols - 1);
        y = _Random.NextBetween(0, _NumRows - 1);
        empty.setX(x);
        empty.setY(y);
    } while (nullptr != GetCellAt(empty));

    return empty;
}

Cell* Ocean::GetCellAt(Coordinate aCoord) 
{
    auto SearchCell = _Cells.find(aCoord);
    if (_Cells.end() == SearchCell)
    {
        return nullptr;
    }
    return SearchCell->second;
}

void Ocean::AssignCellAt(Coordinate aCoord, Cell* aCell) 
{
    auto SearchCell = _Cells.find(aCoord);
    if (_Cells.end() == SearchCell)
    {
        return;
    }
    if (nullptr != SearchCell->second) {
        delete SearchCell->second;
    }
    SearchCell->second = aCell;
}

void Ocean::MoveCell(Coordinate From, Coordinate To) {
    auto FromCell = _Cells.find(From);
    auto ToCell = _Cells.find(To);
    if (_Cells.end() == FromCell || _Cells.end() == ToCell)
    {
        return;
    }
    
    std::swap(FromCell->second, ToCell->second);
    if (nullptr != FromCell->second) {
        delete FromCell->second;
        FromCell->second = nullptr;
    }
}

Coordinate Ocean::GetNeighborWithImage(Coordinate aCoord, char anImage) 
{
    Coordinate neighbors[4];
    int count = 0;

    Coordinate NorthCoordinate = aCoord.North();
    Coordinate SouthCoordinate = aCoord.South(this->_NumRows);
    Coordinate EastCoordinate = aCoord.East(this->_NumCols);
    Coordinate WestCoordinate = aCoord.West();

    Cell* CellNorth = GetCellAt(NorthCoordinate);
    Cell* CellSouth = GetCellAt(SouthCoordinate);
    Cell* CellEast = GetCellAt(EastCoordinate);
    Cell* CellWest = GetCellAt(WestCoordinate);

    if (anImage == GetCharOfCell(NorthCoordinate))
        neighbors[count++] = NorthCoordinate;
    if (anImage == GetCharOfCell(SouthCoordinate))
        neighbors[count++] = SouthCoordinate;
    if (anImage == GetCharOfCell(EastCoordinate))
        neighbors[count++] = EastCoordinate;
    if (anImage == GetCharOfCell(WestCoordinate))
        neighbors[count++] = WestCoordinate;

    if (0 == count)
    {
        return aCoord;
    }
    else 
    {
        return neighbors[_Random.NextBetween(0, count - 1)];
    }
}

Coordinate Ocean::GetEmptyNeighborCoord(Coordinate aCoord) 
{
    return GetNeighborWithImage(aCoord, DEFAULT_IMAGE);
}

Coordinate Ocean::GetPreyNeighborCoord(Coordinate aCoord) 
{
    return GetNeighborWithImage(aCoord, DEFAULT_PREY_IMAGE);
}

void Ocean::AddEmptyCells(void) 
{
    for (int x = 0; x < _NumCols; x++)
    {
        for (int y = 0; y < _NumRows; y++) 
        {
            _Cells.insert(std::pair<Coordinate, Cell *>(Coordinate(x, y),nullptr));
        }
    }
}

void Ocean::Process(Coordinate aCell) 
{
    Cell* SearchCell = GetCellAt(aCell);
    if (nullptr == SearchCell ||
        DEFAULT_OBSTACLE_IMAGE == SearchCell->getImage() || 
        !SearchCell->IsMoving())
    {
        return;
    }

    auto ClosestEmptyCell = GetEmptyNeighborCoord(aCell);
    auto ClosestPreyCell = GetPreyNeighborCoord(aCell);

    if (SearchCell->IsHunger())
    {
        if (aCell == ClosestPreyCell)
        {
            AssignCellAt(aCell, nullptr);
            return;
        }
    }

    Cell* AppointmentCell = nullptr;

    if (aCell != ClosestPreyCell && SearchCell->IsHunting())
    {
        MoveCell(aCell, ClosestPreyCell);
        AppointmentCell = GetCellAt(ClosestPreyCell);
        AppointmentCell->Eaten();
    }
    else {
        if (aCell == ClosestEmptyCell)
        {
            return;
        }
        MoveCell(aCell, ClosestEmptyCell);
        AppointmentCell = GetCellAt(ClosestEmptyCell);
    }

    AppointmentCell->Moved();

    if (AppointmentCell->IsReproducible())
    {
        AppointmentCell->Reproduct();
        AssignCellAt(aCell, AppointmentCell->Copy());
    }
}

void Ocean::ResetMoves(void)
{
    std::map<Coordinate, Cell*>::iterator it = _Cells.begin();

    while (_Cells.end() != it)
    {
        if (nullptr != it->second)
        {
            it->second->ResetMoves();
        }
        it ++;
    }
}

char Ocean::GetCharOfCell(Coordinate aCell) 
{
    Cell* SearchCell = GetCellAt(aCell);
    if (SearchCell == nullptr) 
    {
        return DEFAULT_IMAGE;
    }
    else 
    {
        return SearchCell->getImage();
    }
}

void Ocean::ClearOcean(void)
{
    std::map<Coordinate, Cell*>::iterator it = _Cells.begin();

    while (it != _Cells.end()) 
    {
        if (it->second != nullptr) 
        {
            delete it->second;
            it->second = nullptr;
        }
        it++;
    }
    _Cells.clear();
}