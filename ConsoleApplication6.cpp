#include"OceanLogic.h"
#include"DisplayOcean.h"

int main(int argc, char* argv[]) 
{
    DisplayOcean CLIDisplay;
    OceanLogic* MyOcean = new OceanLogic();

    int NumIterations = DEFAULT_NUM_ITERATOINS;
    int NumOfRows = DEFAULT_ROWS;
    int NumOfCols = DEFAULT_COLS;
    int NumOfPrey = 0;
    int NumOfPredator = 0;
    int NumOfObstacle = 0;

    NumIterations = CLIDisplay.InputNumOfIterations();

    NumOfRows = CLIDisplay.InputNumOfRows();
    CLIDisplay.ShowEntered(MyOcean->SetNumRows(NumOfRows));

    NumOfCols = CLIDisplay.InputNumOfCols();
    CLIDisplay.ShowEntered(MyOcean->SetNumCols(NumOfCols));

    NumOfPrey = CLIDisplay.InputNumOfPrey();
    MyOcean->SetNumPrey(NumOfPrey);
    CLIDisplay.ShowEntered(MyOcean->GetNumPrey());

    NumOfPredator = CLIDisplay.InputNumOfPredator();
    MyOcean->SetNumPredators(NumOfPredator);
    CLIDisplay.ShowEntered(MyOcean->GetNumPredators());

    NumOfObstacle = CLIDisplay.InputNumOfObstacle();
    MyOcean->SetNumObstacles(NumOfObstacle);
    CLIDisplay.ShowEntered(MyOcean->GetNumObstacles());

    MyOcean->InitOcean();

    for (int i = 0; NumIterations > i &&
                    0 < MyOcean->GetNumPredators() &&
                    0 < MyOcean->GetNumPrey(); i++) 
    {
        CLIDisplay.DisplayStats(i, 
                                MyOcean->GetNumObstacles(), 
                                MyOcean->GetNumPredators(), 
                                MyOcean->GetNumPrey());
        CLIDisplay.DisplayMaps(MyOcean->GetCurrentOceanMap());
        MyOcean->UpdateOcean();
    }
    delete MyOcean;
    return 0;
}