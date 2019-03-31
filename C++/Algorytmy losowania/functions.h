#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <math.h>
#include <stack>
#include <fstream>

void f_getParameters(int &n, int &seed, int &Xmax);
int findC (int m);
int f_NWD(int a, int b);
int f_potega (int a, int b);
bool isOk (int liczba, int m);
int findA (int m, int* tab);
void liniowaMetodaKongruencyjna (int n, int seed, int Xmax, int* &table);
void addytywnaMetodaKongruencyjna(int n,int seed,int Xmax, int* &table);
void numberPairs (std::ifstream &pairs, int n, int &pair1, int &pair2);
void fillTable (int n, int seed, int Xmax, int* &table, int pair1, int pair2);
void reverseTable (int* &table, int* &tempTab, int length);
void livingTable (int n, int* &table, int pair1, int pair2, int m);
void metodaTasowaniaZJednaSekwencjaLosowa(int n, int seed, int Xmax, int* &table);

#endif
