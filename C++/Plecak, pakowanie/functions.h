#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "class.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

void loadprzedmioty (ifstream &plik, vector <przedmioty> &przedmioty, int &pojemnosc);
void packing(vector <spakowanePrzedmioty> &packedbag, vector <przedmioty> przedmioty, int pojemnosc);
void packingDynamic(ifstream &plik, vector <przedmioty> przedmiotyvector, int pojemnosc);
void recursionLoadBag(ifstream &plik);
bool recursionPackingBag(vector <int> &spakowanePrzedmioty, vector <int> &przedmioty, int poczatek, int pojemnosc);



#endif // FUNCTIONS_H
