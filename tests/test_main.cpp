#include <CUnit/Basic.h>
#include <CUnit/Console.h>

#include <probleminstance.h>
#include <cstdio>

#define FALSE 0
#define TRUE !FALSE

ProblemInstance* p;

//Maybe put these in some separate file
int init_file(){
	p = new ProblemInstance("instances/instances/2-30-10000-1-9.csp");
	return 0;
}

int clean_file(){
	printf("Desructor\n");
	delete p;//Just for checking if the destructor works
	return 0;
}

void load_file(){
	printf("First test \n");
	CU_ASSERT_EQUAL(p->getAlphabetSize(),2);
	CU_ASSERT_EQUAL(p->getStringNumber(),30);
	CU_ASSERT_EQUAL(p->getStringLength(), 10000);
}

int main(int argc, char** argv) {
	unsigned int fails;
	CU_pSuite pSuite;
	
	CU_initialize_registry();
	
	pSuite = CU_add_suite("Suite_filehandling",init_file,clean_file);
	
	CU_add_test(pSuite, "Load file test", load_file);
	CU_basic_run_tests();
	
	fails = CU_get_number_of_tests_failed();
	
	CU_cleanup_registry();
	return fails;
}
