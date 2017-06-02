#include <iostream>

#include <cstring>
#include <cstdlib>
#include <ctime>

#include <getopt.h>

#include "antcolony.h"
#include "probleminstance.h"

int test_flag = 0;

char* instance_file = NULL;
double rho = 0.2;
int ants = 5;
int seed = -1;
int iterations = 100;

int special = 0;
int elite = 0;
int local = 0;

AntColony* colony;

ProblemInstance* instance;

static struct option long_options[] = {
	{"test",no_argument,&test_flag,1},
	{"file",required_argument,0,'f'},
	{"rho",required_argument,0,'r'},
	{"ants",required_argument,0,'a'},
	{"iterations",required_argument,0,'i'},
	{"seed",required_argument,0,'s'},
    {"local",no_argument,&local,1},
    {"elite",no_argument,&elite,1},
    {"special",no_argument,&special,1},
	{0,0,0,0}
};

void printSolution(){
    cout << "solution:" << colony->getSolutionString() << endl;
    cout << "distance:" << instance->maxHammingDistance(colony->getSolution()) << endl;
}

void printSettings() {
	cout << "settings: " << endl;
	cout << "rho:" << rho << endl;
	cout << "ants:" << ants << endl;
	cout << "filename:" << instance_file << endl;
}

void checkArguments(){
	if(!instance_file){
		cerr << "Instance file is mandatory!" << endl;
		exit(1);
	}
	
	if(seed == -1) {
		srand(time(NULL));
	} else {
		srand(seed);
	}
}

void cleanup(){
	if(instance_file)
		delete[] instance_file;
	if(colony)
		delete colony;
}

using namespace std;
int main(int argc, char **argv)
{
	int option_index;
	int c;
	int arglen = 0;
	
	while((c = getopt_long(argc, argv, "", long_options, &option_index)) != -1){
		switch(c) {
		case 0:
			if(long_options[option_index].flag != 0){
				break;
			}
			cout << "Option " << long_options[option_index].name << endl;
			break;
		case 'f':
			arglen = strlen(optarg);
			instance_file = (char*) malloc((arglen+1) * sizeof(char));
			strcpy(instance_file,optarg);
			break;
		case 'r':
			rho = atof(optarg);
			break;
		case 'a':
			ants = atoi(optarg);
			break;
		case 'i':
			iterations = atoi(optarg);
			break;
		case 's':
			seed = atoi(optarg);
			break;
		}
	}
	
	checkArguments();
	
	printSettings();
	
    instance = new ProblemInstance(instance_file);
	
    colony = new AntColony(instance,ants,rho,local,elite,special);
	colony->searchForSolution(iterations);
	
	printSolution();
	cleanup();
	
	return 0;
}
