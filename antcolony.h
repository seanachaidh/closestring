#ifndef ANTCOLONY_H
#define ANTCOLONY_H

#include <iostream>

#include <cstdlib>
#include <climits>
#include <vector>

#include "ant.h"
#include "probleminstance.h"

#include "hammingneighbourhood.h"
#include "constantinitialsolution.h"
#include "bestimprovement.h"
#include "firstimprovement.h"

class Ant;

using namespace std;
class AntColony {
private:
	int ant_amount;
	vector<Ant*> ants;

    Ant* best_ant = NULL;
	double rho;

    //flags
    int local;
    int elite;
    int special;
	
    vector<int> current_solution;
	long int currentHam = LONG_MAX;
	
public:
    AntColony(ProblemInstance* instnace, int ants, double rho, int local, int elite, int special);
	~AntColony();
	
	//Public to avoid overhead of a getter
	ProblemInstance* instance;
    vector<vector<double> > pheromone_matrix;
	
    int chooseByChance(int position);
	void initializePheromone();
	void evaporatePheromone();

    bool isSpecial(){
        return this->special;
    }
	
	string searchForSolution(int iterations);
    vector<int> performLocalSearch(vector<int> current);


	//Getters
    vector<int> getSolution() {
        return this->current_solution;
    }
    string getSolutionString();

    long int getHammingDistance() {
        return this->currentHam;
    }
	
};

#endif
