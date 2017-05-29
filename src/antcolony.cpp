#include "antcolony.h"

AntColony::AntColony(ProblemInstance* instance, int ants){
	this->ant_amount = ants;
	this->instance = instance;
	
	for(int i = 0; i < ants; i++){
		this->ants.push_back(new Ant(this));
	}
	
	this->pheromone_matrix = (double**) malloc(instance->getStringNumber()*sizeof(double*));
	for(int i = 0; i < instance->getAlphabetSize(); i++){
		this->pheromone_matrix[i] = (double*) malloc(instance->getStringLength() * sizeof(double));
	}
}

AntColony::~AntColony(){
	for(int i = 0; i < this->ant_amount; i++) {
		delete this->ants[i];
	}
	
	for(int i = 0; i < instance->getAlphabetSize(); i++){
		delete[]this->pheromone_matrix[i];
	} 
	delete[] this->pheromone_matrix;

}

void AntColony::initializePheromone() {
	int number = this->instance->getAlphabetSize();
	int length = this->instance->getStringLength();
	
	for(int i = 0; i < number; i++){
		for(int j = 0; j < length; j++){
			this->pheromone_matrix[i][j] = 1/number;
		}
	}
}

char AntColony::chooseByChance(int position){
	double r = rand() / RAND_MAX;
	double* probvec = (double*) malloc(this->instance->getAlphabetSize()*sizeof(double));
	double sum = 0; for(int i = 0; i < instance->getAlphabetSize(); i++) sum += pheromone_matrix[i][position];
	
	double tmp = 0;
	int found = -1; //TODO: Nakijken of dit niet -1 blijft
	
	for(int i = 1; i < this->instance->getAlphabetSize(); i++){
		tmp += pheromone_matrix[i][position]/sum;
		if(tmp >= r) {
			found = i;
			break;
		}
	}
	return instance->getAlphabet(found);	
}
