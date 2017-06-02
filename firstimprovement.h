#ifndef FIRSTIMPROVEMENT_H
#define FIRSTIMPROVEMENT_H

#include "hammingneighbourhood.h"
#include "pivotrule.h"

/**
 * @brief The FirstImprovement class
 * Same as for best improvement, but instead of searching for the best improvement amoung the neighbours,
 * this algorithm sets the first improvement compared to the given solution as its current solution for each
 * iteration. Likewise, this algorithm continues until no improving solution amoung the neighbours can be found.
 */
class FirstImprovement : public PivotRule
{

private:
    vector<int> findFirstImprovement(vector<vector<int>> n, vector<int> current);
    vector<vector<int>> generatePartialNeighbourhood(vector<int> current,int fromwhere);

    vector<int> startpoint;

public:
    FirstImprovement(ProblemInstance *instance, HammingNeighbourHood *hood, InitialSolution *initsol);

    virtual vector<int> searchForSolution(int timelimit = -1);
    virtual string toString() {return "FIRST";}
};

#endif // FIRSTIMPROVEMENT_H
