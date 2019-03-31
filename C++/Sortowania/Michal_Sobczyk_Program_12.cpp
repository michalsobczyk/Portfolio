#include <iostream>
#include <random>
#include "sortingAlgorithms.h"
#include "desktop.h"


using namespace std;

int main() {

	int returnCode = 0;

	try {
		desktop("out.txt");
	}
	catch (EXCEPTION_CODE error) {
		seeExceptions(error);
		returnCode = 1;
	}


	cin.ignore();
	getchar();

	return 0;
}
