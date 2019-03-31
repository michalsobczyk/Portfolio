#include "Table.h"
#include <iostream>

using namespace std;

int *f_createNtab(int n) {

	int *T = nullptr;
	try {
		T = new int[n];
	}
	catch (bad_alloc) {

		cout << "blad";
		exit(0);
	}
	return T;
}

