#include <probleminstance.h>

ProblemInstance::ProblemInstance(string filename) {
	ifstream input;
	
	input.open(filename);
	if(input.good()){
		string tmpsize,tmpn,tmpl,tmpline;
		
		input >> tmpsize;
		input >> tmpn;
		input >> tmpl;
		
		this->string_number = atoi(tmpn.c_str());
		this->string_length = atoi(tmpl.c_str());
		
		this->alphabet_size = atoi(tmpsize.c_str());
		this->alphabet = new char[alphabet_size];
		
		for(int i = 0; i < alphabet_size; i++){
			string letter;
			getline(input,letter);
			this->alphabet[i] = letter.c_str()[0];
		}
		
		this->strings = (char**) malloc(string_number*sizeof(char*));
		for(int i = 0; i < this->string_number; i++) {
			char* tmpstring = (char*) malloc(string_length*sizeof(char));
			input.getline(tmpstring,string_length);
			strings[i] = tmpstring;
		}
		
	} else {
		cerr << "Error reading instancefile " << filename << endl;
	}
}

string ProblemInstance::toString() {
	stringstream stream;
	
	stream << "Instance file " << endl;
	stream << "Alphabet ";
	for(int i = 0; i < this->alphabet_size; i++) {
		stream << alphabet[i] << " ";
	}
	
	stream << endl;
	
	stream << "Alphabet size " << this->alphabet_size  << endl;
	stream << "String number " << this->string_number << endl;
	stream << "String length " << this->string_length << endl;
	
	return stream.str();
	
}

int ProblemInstance::getAlphabetSize(){
	return this->alphabet_size;
}

string ProblemInstance::getFileName(){
	return this->filename;
}

int ProblemInstance::getStringLength() {
	return this->string_length;
}

int ProblemInstance::getStringNumber() {
	return this->string_number;
}

ProblemInstance::~ProblemInstance() {
	delete[] this->alphabet;
	for(int i = 0; i < string_number; i++){
		delete[] this->strings[i];
	}
	
	delete[] this->strings;
}

int ProblemInstance::hammingDistance(const char* str, int j) {
	int retval = 0;
	int len = this->string_length;
	char* second = this->strings[j];
	
	for(int x = 0; x < len; x++){
		if(str[x] == second[x])
			retval++;
	}
	
	return retval;
}

int ProblemInstance::maxHammingDistance(const char* str){
	int retval = 0;
	int currentHD = hammingDistance(str, 0);
	for(int i = 1; i < string_number; i++){
		int newHD = hammingDistance(str,i);
		if(newHD > currentHD) {
			currentHD = newHD;
			retval = i;
		}
	}
	return retval;
}

char ProblemInstance::getAlphabet(int pos) {
	return this->alphabet[pos];
}

