#ifndef ANT_H
#define ANT_H

#include <string>
#include "antcolony.h"

using namespace std;

class AntColony;
class Ant {
private:
    vector<int> found_solution;
	AntColony* colony;
	
public:
	Ant(AntColony* colony);
	virtual ~Ant();
	
	void constructSolution();
	void updatePheromone();
	
	//Getters
    vector<int> getSolution(){return found_solution;};
	
};

#endif
