#include "constantinitialsolution.h"

ConstantInitialSolution::ConstantInitialSolution(ProblemInstance* instance, vector<int> sol)
    :InitialSolution(instance)
{
    this->solution = sol;
}

vector<int> ConstantInitialSolution::generateInitialSolution()
{
    return this->solution;
}
