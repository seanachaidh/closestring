#include <ant.h>

Ant::Ant(AntColony* colony) {
	this->colony = colony;
}

Ant::~Ant() {
	
}

void Ant::updatePheromone() {

    double maxham = colony->instance->maxHammingDistance(found_solution);
    double stringlength = colony->instance->getStringLength();
    for(int i = 0; i < colony->instance->getStringLength(); i++) {
        int currentletter = found_solution[i];
        double old = colony->pheromone_matrix[currentletter][i];
        colony->pheromone_matrix[currentletter][i] = old + (1.0-(maxham/stringlength));
    }
}

void Ant::constructSolution() {
    vector<int> solution;
	for(int i = 0; i < colony->instance->getStringLength(); i++){
        int toadd = colony->chooseByChance(i);
        solution.push_back(toadd);
	}
	
    this->found_solution = solution;
}

void Ant::constructSolutionSpecial()
{
    vector<int> solution;
    for(int i = 0; i < colony->instance->getStringLength(); i++){
        double r = (double) rand() / RAND_MAX;
        int toadd;
        if(colony->isSpecial() && r < 0.4){
            toadd = this->colony->getSolution()[i];
        } else {
            toadd = colony->chooseByChance(i);
        }
        solution.push_back(toadd);
    }

    this->found_solution = solution;
}
