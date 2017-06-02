#ifndef HAMMINGNEIGHBOURHOOD_H
#define HAMMINGNEIGHBOURHOOD_H

#include "neighbourhood.h"

class HammingNeighbourHood : public NeighbourHood
{
public:
    HammingNeighbourHood(ProblemInstance*  instance);
    vector<vector<int>> generateNeighbourHood(vector<int> state);
    vector<vector<int>> generateNeighbourHoodFromPoint(vector<int> state,int point);
};

#endif // HAMMINGNEIGHBOURHOOD_H
