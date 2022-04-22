#ifndef DISOCEAN_H
#define DISOCEAN_H

#include"Constants.h"

#include<iostream>
#include<vector>
#include<array>
#include<string>

class DisplayOcean{
private:
    void DisplayBorder(int numCols);

public:
    void DisplayStats(int iteration, int numObstacles, int numPredators, int numPrey);
    void DisplayMaps(std::vector<std::string> Map);

    int InputNumOfIterations(void);
    int InputNumOfRows(void);
    int InputNumOfCols(void);
    int InputNumOfPrey(void);
    int InputNumOfPredator(void);
    int InputNumOfObstacle(void);

    void ShowEntered(int EnteredNum);
   };

#endif