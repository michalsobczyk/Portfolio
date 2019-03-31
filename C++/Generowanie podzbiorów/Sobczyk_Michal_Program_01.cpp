#include <iostream>
#include <fstream>
#include <cstdlib>
#include "functions.h"

using namespace std;

int main() {
    int n;
    cin >> n;
	string out = "out1.txt";
    ofstream file;
    file.open (out.c_str());
    if (!file.good())
        exit (0)
    else
        generateSubsets1(n, file)
    file.close();
    getchar();
	cin.ignore();
	return 0;
}

