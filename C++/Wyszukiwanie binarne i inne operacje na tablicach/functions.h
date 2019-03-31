#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <fstream>
#include <string>
//#include "stdafx.h"

using namespace std;

int* f_createtable(int x);
void f_deleteTable(int *T);
/**
* Wyszukiwanie pierwszego szukanego elementu
*
* @param searchingNumber wyszukiwany numer
* @param tabOfNumber tablica liczb
* @param leng d³ugoœæ tablicy
* @return index pierwszego elementu
*/
int searchFirst(int searchingNumber, int* tabOfNumber, int leng);
/**
* Wyszukiwanie ostatniego szukanego elementu
*
* @param searchingNumber wyszukiwany numer
* @param tabOfNumber tablica liczb
* @param leng d³ugoœæ tablicy
* @return index ostatniego elementu
*/
int searchLast(int searchingNumber, int* tabOfNumber, int leng);
/**
* Usuwanie duplikatów tablicy
*
* @param tabOfNumber tablica liczb
* @param tabLength d³ugoœæ tablicy
* @return tablica bez duplikatów
*/
int* removingDuplicates(int* tabOfNumber, int tabLength);
int f_indexsearching (int searchingNumber, int* tabOfNumber, int leng);
bool loadFile(std::string fileName);

#endif // F_FUNCTIONS_H

