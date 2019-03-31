#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "classfile.h"

int biggestVertex (std::ifstream &vertex);
void addTab (std::ifstream &vertex, List** &tab);
void showIncidenceList(int maxVertex, List** &tab);
void showStopnieWierzcholkow (int maxVertex, List** &tab);

#endif // FUNCTIONS_H
