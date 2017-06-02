#ifndef NEIGHBOURHOOD_H
#define NEIGHBOURHOOD_H

#include "probleminstance.h"
/**
 * @brief The NeighbourHood class
 *
 * This is the main class for defining neighbourhoods. A neighbourhood is the set of
 * neigbouring solutions, that is the set of solutions created by making a single perturbation
 * in a current solution
 */
class NeighbourHood
{
protected:
    ProblemInstance* instance;
public:
    NeighbourHood(ProblemInstance *instance);

    /**
     * @brief generateNeighbourHood
     * @param state the current state.
     * @return The neighbourhood of the given state.
     *
     * Generates the neighbourhood of a given state
     *
     */
    virtual vector<vector<int>> generateNeighbourHood(vector<int> state) = 0;
    virtual string toString()
    {
        return "Neighbourhood";
    }
    virtual ~NeighbourHood();

};

#endif // NEIGHBOURHOOD_H
