#ifndef PROBLEM_INSTANCE_H
#define PROBLEM_INSTANCE_H

#include <iostream>

#include <string>
#include <sstream>
#include <fstream>

#include <cstdlib>

using namespace std;
class ProblemInstance {
private:
	string filename;
	int string_length;
	int string_number;
	int alphabet_size;
	
	//Not going to make this a vector because it is not going to change
	char* alphabet;
	char** strings;
	
public:
	ProblemInstance(string filename);
	virtual ~ProblemInstance();
	
	
	//Getters
	string getFileName();
	
	int getStringLength();
	int getStringNumber();
	int getAlphabetSize();
	
	string toString();
	
};

#endif
