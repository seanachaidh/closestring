#include "pivotrule.h"

PivotRule::PivotRule(ProblemInstance *instance, NeighbourHood *hood, InitialSolution *initsol)
{
    this->hood = hood;
    this->initsol = initsol;
    this->instance = instance;
}

PivotRule::~PivotRule()
{

}
