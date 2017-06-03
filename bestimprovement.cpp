#include "bestimprovement.h"

vector<int> BestImprovement::searchBest(vector<vector<int> > n, vector<int> current)
{
    vector<int> retval;
    long currentHAM = this->getInstance()->maxHammingDistance(current);
    for(vector<int> v: n){
        long newHAM = this->getInstance()->maxHammingDistance(v);
        if(newHAM < currentHAM){
            currentHAM = newHAM;
            retval = v;
        }
    }

    return retval;
}

BestImprovement::BestImprovement(ProblemInstance* instance, NeighbourHood* hood, InitialSolution* initsol)
    :PivotRule(instance,hood,initsol)
{

}

vector<int> BestImprovement::searchForSolution(int timelimit = -1)
{
    long timenow = time(NULL);
    vector<int> pi = this->getInitialSolution()->generateInitialSolution();
    for(;;) {
        if(timelimit > 0) {
            long delta_time = time(NULL) - timenow;
            if(ceil(delta_time/60) > timelimit)
                break;
        }
        vector<vector<int> > N_pi = this->getNeighbourHood()->generateNeighbourHood(pi);
        vector<int> tocheck = searchBest(N_pi,pi);
        if(tocheck.empty())
            break;
        else
            pi = tocheck;
    }
    return pi;
}
