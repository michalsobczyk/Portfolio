#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void createIncidenceMatrix(int** &matrix, std::ifstream &vertex);
int biggestVertex (std::ifstream &vertex);
int **createMatrix (int n, int m);
void showMatrix (int** &matrix, int n, int m);
void zeroMatrix (int ** &matrix, int n, int m);
void createNeighbourMatrix(int ** &matrix, std::ifstream &vertex);
void createIncidenceVector(std::vector <int> &tab, std::ifstream &vertex);
void showIncidenceVector (std::vector <int> &tab, int edgeNumber, int maxVertex);
void createNeighbourVector(std::vector<std::vector <int>> &tab, std::ifstream &vertex);
void showNeighbourVector (std::vector<std::vector <int>> &tab, int maxVertex);

#endif // FUNCTIONS_H
