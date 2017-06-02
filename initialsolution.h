#ifndef INITIALSOLUITION_H
#define INITIALSOLUITION_H

#include <vector>
#include "probleminstance.h"

/**
 * @brief The InitialSolution class
 * A class that can generate initial solutions for an instance
 *
 */
class InitialSolution
{
protected:
    ProblemInstance* instance;
public:
    InitialSolution(ProblemInstance *instance);

    //Virtuele functies die geïmplementeerd moeten worden
    /**
     * @brief generateInitialSolution
     * @return An initial solution
     * This function returns an initial solution. See implementation classes for more details.
     */
    virtual vector<int> generateInitialSolution() = 0;
    virtual string toString() {return "InitialSolution";}
    virtual ~InitialSolution();
};

#endif // INITIALSOLUITION_H
