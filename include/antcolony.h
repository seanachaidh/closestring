#ifndef ANTCOLONY_H
#define ANTCOLONY_H

#include <cstdlib>

#include <vector>
#include "ant.h"
#include "probleminstance.h"

class Ant;
class AntColony {
private:
	int ant_amount;
	vector<Ant*> ants;
	
public:
	AntColony(ProblemInstance* instnace, int ants);
	~AntColony();
	
	//Public to avoid overhead of a getter
	ProblemInstance* instance;
	double** pheromone_matrix;
	
	char chooseByChance(int position);
	void initializePheromone();
	
};

#endif
