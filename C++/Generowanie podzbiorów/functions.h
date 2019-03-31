#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


void generateSubsets1 (int n, ofstream &file);
void generateSubsets2 (int n, int k, ofstream &file);
void generateSubsets3 (int n, ofstream &file);
void writeDivision (int* tab1, int* tab2, int n, ofstream &file);

#endif // FUNCTIONS_H
