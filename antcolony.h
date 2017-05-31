#ifndef ANTCOLONY_H
#define ANTCOLONY_H

#include <iostream>

#include <cstdlib>
#include <climits>
#include <vector>

#include "ant.h"
#include "probleminstance.h"

class Ant;

using namespace std;
class AntColony {
private:
	int ant_amount;
	vector<Ant*> ants;
	double rho;
	
    vector<int> current_solution;
	long int currentHam = LONG_MAX;
	
public:
	AntColony(ProblemInstance* instnace, int ants, double rho);
	~AntColony();
	
	//Public to avoid overhead of a getter
	ProblemInstance* instance;
    vector<vector<double>> pheromone_matrix;
	
    int chooseByChance(int position);
	void initializePheromone();
	void evaporatePheromone();
	
	string searchForSolution(int iterations);
	
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
