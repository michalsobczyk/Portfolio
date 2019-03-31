#include <iostream>
#include <fstream>
#include <cstdlib>
#include "functions.h"

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string out = "out2.txt";
    ofstream file;
    file.open (out.c_str());
    if (!file.good())
        exit (0)
    else
        generateSubsets2(n, k, file)
    file.close();
    getchar();
	cin.ignore();
	return 0;
}

