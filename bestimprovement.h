#ifndef BESTIMPROVEMENT_H
#define BESTIMPROVEMENT_H

#include "pivotrule.h"

/**
 * @brief The BestImprovement class
 *
 * This variant of the pivotrule implements a search by using best improvement.
 * When a the neighbourhood of a current solution is search, this algorithm will search the best amoung them.
 * That is, the neighbour for which the evaluation function is minimal and for which the evaluation is less than that of the
 * current solution. Once it found such a neighbour, it sets that neighbour as its current solution and repeats the process.
 * This algorithm continues until no improving neighbour can be found.
 *
 */
class BestImprovement : public PivotRule
{
private:
    vector<int> searchBest(vector<vector<int> > n, vector<int> current);
public:
    BestImprovement(ProblemInstance *instance, NeighbourHood *hood, InitialSolution *initsol);
    virtual vector <int> searchForSolution(int timelimit);
    virtual string toString() {return "BEST";}
};

#endif // BESTIMPROVEMENT_H
