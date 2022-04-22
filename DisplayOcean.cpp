#include "DisplayOcean.h"

void DisplayOcean::DisplayMaps(std::vector<std::string> Map) 
{
    std::vector<std::string>::iterator cells = Map.begin(); 
    int BorderSize = cells->size(); 
    DisplayBorder(BorderSize);
    for (cells; cells != Map.end(); cells++) 
    {
        std::cout << "|";
        std::cout << *cells;
        std::cout << "|" << std::endl;
    }
    DisplayBorder(BorderSize);
}

void DisplayOcean::DisplayBorder(int numRows) 
{
    std::cout << "*";
    for (int x = 0; x < numRows; x++)
    {
        std::cout << char(196);
    }
    std::cout << "*";
    std::cout << "\n";
}

void DisplayOcean::DisplayStats(int iteration, int numObstacles, int numPredators, int numPrey) 
{
    std::cout << "\n\n";
    std::cout << "Iteration number: " << ++iteration << " ";
    std::cout << "Obstacles: " << numObstacles << " ";
    std::cout << "Predators: " << numPredators << " ";
    std::cout << "Prey: " << numPrey << "\n";
    std::cout.flush();
}

int DisplayOcean::InputNumOfIterations(void) 
{
    int Iteration;
    std::cout << "\n\nEnter number of iteraions (default max = 1000): ";
    std::cout.flush();
    std::cin >> Iteration;
    
    if (Iteration > 1000) Iteration = 1000;
    ShowEntered(Iteration);

    return Iteration;
}

int DisplayOcean::InputNumOfRows(void)
{
    int NumRows;
    std::cout << "\n\nEnter number of rows (default max = " << DEFAULT_ROWS << "): ";
    std::cout.flush();
    std::cin >> NumRows;
    return NumRows;
}

int DisplayOcean::InputNumOfCols(void)
{
    int NumCols;
    std::cout << "\n\nEnter number of cols (default max = " << DEFAULT_COLS << "): ";
    std::cout.flush();
    std::cin >> NumCols;
    return NumCols;
}

void DisplayOcean::ShowEntered(int EnteredNum) 
{
    std::cout << "\nNumber entered = " << EnteredNum << "\n";
    std::cout.flush();
}

int DisplayOcean::InputNumOfPrey(void)
{
    int NumPrey;
    std::cout << "\n\nEnter number of prey: ";
    std::cout.flush();
    std::cin >> NumPrey;
    return NumPrey;
}

int DisplayOcean::InputNumOfPredator(void)
{
    int NumPredator;
    std::cout << "\n\nEnter number of predators: ";
    std::cout.flush();
    std::cin >> NumPredator;
    return NumPredator;
}

int DisplayOcean::InputNumOfObstacle(void)
{
    int NumObstacle;
    std::cout << "\n\nEnter number of obstacles: ";
    std::cout.flush();
    std::cin >> NumObstacle;
    return NumObstacle;
}