#include "functions.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


void generateSubsets1 (int n, ofstream &file){
    int *T = new int [n];
    int i = 0;
    int p = 0;
    int j = 0;
    for(int k = 0; k < n; k++)
        T[k] = 0;
    do {
        for (int k = 0; k < n; k++)
            file << T[k];

        file << endl;

        i++;
        j = i;
        p = 0;

        while (j%2 == 0){
            j = j / 2;
            p++;
        }

        if(p <= n){
            T[p] = 1 - T[p];
        }

    } while (p < n);

    delete [] T;
}

void generateSubsets2 (int n, int k, ofstream &file){
    int *A = new int [k+1];
    for(int i = 0; i < k+1; i++)
        A[i] = i;
    int p = k;
    while (p>=1){
        for (int i = 1; i < k + 1; i++)
            file << A[i];
        file << endl;
        if (A[k] == n)
            p = p - 1;
        else
            p = k;
        if (p >= 1){
            for (int i = k; i >= p; i--)
                A[i] = A[p] + i - p + 1;
        }
    }
}

void generateSubsets3 (int n, ofstream &file) {
    int* tab1 = new int[n + 1];
    int* tab2 = new int[n + 1];
    int d;
    for (int i = 0; i < n + 1; i++)
    {
        tab1[i] = 0;
        tab2[i] = 0;
    }

    tab1[1] = n;
    tab2[1] = 1;
    d = 1;

    writeDivision(tab1, tab2, n + 1, file);

    while (tab1[1] > 1) {
        int sum = 0;
        if (tab1[d] == 1) {
            sum = sum + tab2[d];
            d--;
        }

        sum = sum + tab1[d];
        tab2[d] = tab2[d] - 1;
        int c = tab1[d] - 1;
        if (tab2[d] > 0) {
            d++;
        }

        tab1[d] = c;
        tab2[d] = sum / c;
        c = sum % c;

        if (c != 0) {
            d++;
            tab1[d] = c;
            tab2[d] = 1;
        }
        writeDivision(tab1, tab2, n + 1, file);
    }
}

void writeDivision (int* tab1, int* tab2, int n, ofstream &file) {   // zapisuje podzial do pliku
	for (int i = 1; i < n; i++) {
		if (tab1[i] == 0)   // zera zastepujemy spacjami
			file << "  ";
		else
			file << tab1[i] << " ";
	}

	file << "   ";

	for (int i = 1; i < n; i++) {
		if (tab2[i] == 0)   //zera zastepujemy spacjami
			file << "  ";
		else
			file << tab2[i] << " ";
	}
	file << endl;

	file.flush();
}


