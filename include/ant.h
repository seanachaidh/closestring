#ifndef ANT_H
#define ANT_H

#include <string>
#include "antcolony.h"

using namespace std;

class AntColony;
class Ant {
private:
	string found_solution;
	AntColony* colony;
	
public:
	Ant(AntColony* colony);
	virtual ~Ant();
	
	void constructSolution();
	void updatePheromone();
};

#endif
