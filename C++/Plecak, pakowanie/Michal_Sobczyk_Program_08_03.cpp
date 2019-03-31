#include <iostream>
#include "functions.h"
#include "class.h"

using namespace std;

int main() {
	ifstream plik;
    string file = "ritems.txt";
	plik.open(file.c_str());
	if (!plik.good())
		exit(0);
    recursionLoadBag(plik);
    return 0;
}
