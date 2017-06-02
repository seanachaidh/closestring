#include "hammingneighbourhood.h"

HammingNeighbourHood::HammingNeighbourHood(ProblemInstance *instance)
    :NeighbourHood(instance)
{

}

vector<vector<int> > HammingNeighbourHood::generateNeighbourHood(vector<int> state)
{
    vector<vector<int>> retval(1);
    long state_distance = instance->maxHammingDistance(state);

    int maxlen = instance->getStringLength();
    if (maxlen > 100) maxlen = 100;

    for(int i = 0; i < maxlen; i++){
        int current = state[i];
        for(int j = 0; j < this->instance->getAlphabetSize(); j++){
            if(current != j){
                vector<int> copyvec = state; //deep copy
                copyvec[i] = j;

                //Here we check allready so that we can only send one neighbour back so that this will be optimised more
                long impdist = instance->maxHammingDistance(copyvec);
                if(impdist < state_distance) {
                    retval[0] = copyvec;
                    return retval;
                }
            }
        }
    }
    return {};
}

vector<vector<int> > HammingNeighbourHood::generateNeighbourHoodFromPoint(vector<int> state, int point)
{
    vector<vector<int>> retval(1);
    long state_distance = instance->maxHammingDistance(state);

    int maxlen = instance->getStringLength() - point;
    if (maxlen > 100) maxlen = 200;

    for(int i = point; i < maxlen; i++){
        int current = state[i];
        for(int j = 0; j < this->instance->getAlphabetSize(); j++){
            if(current != j){
                vector<int> copyvec = state; //deep copy
                copyvec[i] = j;

                //Here we check allready so that we can only send one neighbour back so that this will be optimised more
                long impdist = instance->maxHammingDistance(copyvec);
                if(impdist < state_distance) {
                    retval[0] = copyvec;
                    return retval;
                }
            }
        }
    }

    return {};
}
