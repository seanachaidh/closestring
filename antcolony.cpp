#include "antcolony.h"

AntColony::AntColony(ProblemInstance* instance, int ants, double rho, int local, int elite, int special){
	this->ant_amount = ants;
	this->instance = instance;
	this->rho = rho;

    this->local = local;
    this->elite = elite;
    this->special = special;

	for(int i = 0; i < ants; i++){
		this->ants.push_back(new Ant(this));
	}
    pheromone_matrix.assign(this->instance->getAlphabetSize(),vector<double>(instance->getStringLength()));


#ifdef DEBUG
	cout << "String length:" << this->instance->getStringLength() << endl;
	cout << "Alphabet size:" << this->instance->getAlphabetSize()  << endl;
#endif
}

AntColony::~AntColony(){
	for(int i = 0; i < this->ant_amount; i++) {
		delete this->ants[i];
	}
}

void AntColony::initializePheromone() {
	int number = this->instance->getAlphabetSize();
	int length = this->instance->getStringLength();
	
	for(int i = 0; i < number; i++){
		for(int j = 0; j < length; j++){
            this->pheromone_matrix[i][j] = 1.0/number;
		}
	}


}

int AntColony::chooseByChance(int position){
    double r = ((double) rand())/ RAND_MAX;
	double sum = 0; 
	for(int i = 0; i < instance->getAlphabetSize(); i++) 
		sum += pheromone_matrix[i][position];
	
	double tmp = 0;
	int found = -1; //TODO: Nakijken of dit niet -1 blijft
	
    for(int i = 0; i < this->instance->getAlphabetSize(); i++){
		tmp += pheromone_matrix[i][position]/sum;
		if(tmp >= r) {
			found = i;
			break;
		}
	}
    return found;
}

void AntColony::evaporatePheromone(){
	for(int i = 0; i < instance->getAlphabetSize(); i++){
		for(int j = 0; j < instance->getStringLength(); j++){
			double old = pheromone_matrix[i][j];
			pheromone_matrix[i][j] = rho * old;
		}
	}
}

string AntColony::searchForSolution(int iterations){
	this->initializePheromone(); //To support the ability to search again.
	for(int i = 0; i < iterations; i++){
#ifdef DEBUG
		cout << "Iteration: " << i << endl;
#endif
		for(Ant* a: ants){
			a->constructSolution();
            if(!this->elite) a->updatePheromone(); //In case we are not perfoming an elitst ant
			
			//Check if better
            long int antham = this->instance->maxHammingDistance(a->getSolution());
			if(antham < currentHam){
				current_solution = a->getSolution();
                best_ant = a;
				currentHam = antham;
			}
		}

        if(elite) best_ant->updatePheromone(); //in case of elite, only the best ant updates the pheromone

		evaporatePheromone();

	}
    if(local){
        cout << "Performing local search"  << endl;
        current_solution = performLocalSearch(current_solution);
    }
    return instance->solutionToString(current_solution);
}

vector<int> AntColony::performLocalSearch(vector<int> current)
{
    HammingNeighbourHood *n = new HammingNeighbourHood(this->instance);
    InitialSolution* sol = new ConstantInitialSolution(this->instance,current);
    PivotRule* rule = new FirstImprovement(this->instance,n,sol);

    vector<int> improved = rule->searchForSolution(this->instance->getStringLength()); //Nog veranderen naar een variable

    delete n;delete sol;delete rule;

    return improved;
}

string AntColony::getSolutionString()
{
    return this->instance->solutionToString(this->current_solution);
}
