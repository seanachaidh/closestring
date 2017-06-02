#ifndef PIVOTRULE_H
#define PIVOTRULE_H

#include <ctime>
#include <cmath>

#include "probleminstance.h"
#include "neighbourhood.h"
#include "initialsolution.h"

/**
 * @brief The PivotRule class
 * This is the baseclass for all PivotRule subclasses. Look at one of the subclasses for more details.
 */
class PivotRule
{
private:
    ProblemInstance* instance;
    NeighbourHood* hood;
    InitialSolution* initsol;


public:
    PivotRule(ProblemInstance* instance, NeighbourHood* hood, InitialSolution* initsol);
    /*
     * Opelet. Abstracte klasse
     */

    /**
     * @brief searchForSolution
     * @param timelimit Imposed timelimit in minutes. The algorithm will stop and return its current solution if the computation time exceeds this limit
     * @return A solution for an instance
     */
    virtual vector<int> searchForSolution(int timelimit = -1) = 0;

    ProblemInstance* getInstance(){
        return instance;
    }
    NeighbourHood* getNeighbourHood(){
        return hood;
    }
    InitialSolution* getInitialSolution(){
        return initsol;
    }

    virtual ~PivotRule();

    virtual string toString() {return "PivotRule";}

};

#endif // PIVOTRULE_H
