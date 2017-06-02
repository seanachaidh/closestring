#ifndef CONSTANTINITIALSOLUTION_H
#define CONSTANTINITIALSOLUTION_H

#include "initialsolution.h"

class ConstantInitialSolution : public InitialSolution
{
    vector<int> solution;
public:
    ConstantInitialSolution(ProblemInstance* instance, vector<int> sol);
    vector<int> generateInitialSolution();
};

#endif // CONSTANTINITIALSOLUTION_H
