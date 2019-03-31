#include "functions.h"

int scal(int T[], int l, int s, int p) {
    int inversions = 0;
	int *tab = new int [p+1];
	int i = l;
	int j = s + 1;
	int k = l;                                       //pokazuje ilosc liczb przepisanych do tab
    while (i <= s && j <= p) {
        if (T[i] <= T[j]) {
            tab[k++] = T[i++];
    }
        else {
			tab[k++] = T[j++];
			inversions += (s + 1 - i);
        }
    }
    for (; i <= s; ++i, ++k)                         //Dopisuje pozostale liczby w lewej czesci T do tab
		tab[k] = T[i];

	for (; j <= p; ++j, ++k)                         //w prawej czesci
		tab[k] = T[j];

	for (i = l; i <= p; ++i)                         //przepisuje tab posortowana do T
		T[i] = tab[i];


    return inversions;
}

int sortScal(int T[], int l, int p) {
    int inversions = 0;
	if (l < p) {                                      //1 element - posortowany
        int s = (l + p) / 2;
        inversions += sortScal(T, l, s);               //dzielimy tablice na 2 czêœci i powtarzamy algorytm
        inversions += sortScal(T, s + 1, p);
        inversions += scal(T, l, s, p);
	}
	return inversions;
}

