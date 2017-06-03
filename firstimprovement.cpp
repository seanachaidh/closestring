#include "firstimprovement.h"

vector<int> FirstImprovement::findFirstImprovement(vector<vector<int> > n, vector<int> current)
{
    long int currentWCT = this->getInstance()->maxHammingDistance(current);
    for(vector<int> v: n){
        long int newHAM = this->getInstance()->maxHammingDistance(v);
        if(newHAM < currentWCT)
            return v;
    }

    return {};
}

vector<vector<int> > FirstImprovement::generatePartialNeighbourhood(vector<int> current, int fromwhere)
{
    if(fromwhere == 0)
        return this->getNeighbourHood()->generateNeighbourHood(current);

    vector<int> part(current.begin(),current.begin()+fromwhere);
    vector<int> tocheck(current.begin()+fromwhere, current.end());
    vector<vector<int>> retval;
    vector<vector<int>> nbourtocheck = this->getNeighbourHood()->generateNeighbourHood(tocheck);

    for(vector<int> nbour: nbourtocheck){
        nbour.insert(nbour.begin(),part.begin(),part.end());
        retval.push_back(nbour);
    }

    return retval;

}

FirstImprovement::FirstImprovement(ProblemInstance* instance, HammingNeighbourHood* hood,InitialSolution *initsol)
    :PivotRule(instance,hood,initsol)
{

}

vector<int> FirstImprovement::searchForSolution(int timelimit)
{
    vector<int> pi = this->getInitialSolution()->generateInitialSolution();
    for(int i = 0; i < timelimit; i++) {
#ifdef DEBUG
        cout << "Iteration local search: " << i << endl;
#endif
        //We can safely assume this here
        vector<vector<int> > N_pi = ((HammingNeighbourHood*)this->getNeighbourHood())->generateNeighbourHoodFromPoint(pi,i);
        vector<int> tocheck = findFirstImprovement(N_pi,pi);
        if(tocheck.empty())
            break;
        else
            pi = tocheck;
    }
    return pi;
}
