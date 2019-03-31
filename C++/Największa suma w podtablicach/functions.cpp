#include "functions.h"

int ** f_createtable(int n, int m) {
	int **T = nullptr;
	try {
		T = new int *[n];
	}
	catch (bad_alloc) {
		cout << "!(alloc)";
		exit(0);
	}
	for (int i = 0; i < n; i++) {
		try {
			T[i] = new int[m];
		}
		catch (bad_alloc) {
			cout << "!(alloc)";
			exit(0);
		}
	}
	return T;
}

/* Podajemy tablicę jednowymiarową, która jest sumą kolumn tablicy dwuwymiarowej i wybieramy największą podtablicę w tym przypadku */
int kadane(int* tab, short size) {
	int biggest = 0, current = 0;
	for (int i = 0; i < size; ++i) {
		current = (tab[i]>tab[i] + current) ? tab[i] : tab[i] + current;
		if (current > biggest)
			biggest = current;
	}
	return biggest;
}

/* Sumujemy kolumny tablicy dwuwymarowej i zwracamy je w postaci tablicy jednowymiarowej */
int sum_table2(int** tab, int n, int m) {           // O(max(n,m))^3
	int sum = 0;
	for (int i = 0; i < n; ++i) {					// Górny wiersz
		int* temp_tab = new int[m];
        for (int k = 0; k < m; k++)
            temp_tab[k] = 0;
		for (int j = i; j < n; ++j) {				// Dolny wiersz
			for (int k = 0; k < m; ++k)
				temp_tab[k] += tab[j][k];			// Suma pomiêdzy górnym i dolnym wierszem
			int temp_sum = 0;
			temp_sum = kadane(temp_tab, m);		    // Algorytm Kadane do wyliczenia najwiêkszej sumy podtablicy
			if (temp_sum > sum)
				sum = temp_sum;						// Podmieñ sumê, je¿eli jest wiêksza
		}
		delete[] temp_tab;
	}
	return sum;
}
