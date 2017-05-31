#ifndef PROBLEM_INSTANCE_H
#define PROBLEM_INSTANCE_H

#include <iostream>

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include <cstdlib>

#include <vector>

using namespace std;
class ProblemInstance {
private:
	string filename;
	int string_length;
	int string_number;
	int alphabet_size;
	
	//Not going to make this a vector because it is not going to change
	char* alphabet;
    vector<string> strings;
	
public:
	ProblemInstance(string filename);
	virtual ~ProblemInstance();
	
	
	//Getters
	string getFileName();
	
	int getStringLength();
	int getStringNumber();
	int getAlphabetSize();
	char getAlphabet(int pos);
	
	
	//Goal function
    long int hammingDistance(vector<int> solution, int j);
    long int maxHammingDistance(vector<int> solution);

    string solutionToString(vector<int> solution);
	
	string toString();
	
};

#endif
