#include "functions.h"
#include <stack>
#include <iostream>
#include <fstream>

using namespace std;

void f_getParameters(int &n, int &seed, int &Xmax) {
	cout << "Ilosc liczb do wygenerowania: " << endl;
	cin >> n;
	cout << "Ziarno: " << endl;
	cin >> seed;
	cout << "Maksymalna wartosc do wygenerowania: " << endl;
	cin >> Xmax;
}

int f_NWD(int a, int b) {
    do{
        if(a>b) a=a-b;
        else b=b-a;
    }
    while(a!=b);
    return a;
}

int findC (int m){
    int c = 3;
    do {
        c++;
    }
    while (f_NWD (c, m) != 1 && c < m);
    if (c == m) return -1;
    return c;
}

int f_potega (int a, int b){
    for (int i = 0; i < b-1; i++)
        a = a*a;
    return a;
}

bool isOk (int liczba, int m){
    int b = liczba - 1;
    if (b%m == 0)
        if (m%4 == 0)
            if (b%4 == 0) return true;
            else return false;
        else return true;
    else return false;


}


int findA (int m, int* tab){
    stack <int> stosLiczb;
    int lambdaMax = 0;
    int goodA = 0;
    int stosSize = 0;
    for (int a = 2; a < m; a++)
        for (int lambda = 1; lambda < m; lambda++)
            if ((f_potega(a, lambda))%m == 1){
                tab[a-2] = lambda;
                if (lambdaMax < lambda) lambdaMax = lambda;
                a++;
                lambda = 0;
            }

    for (int i = 0; i < m; i++)
        if (lambdaMax == tab[i])
            stosLiczb.push(i+1);
    goodA = stosLiczb.top();
    stosSize = stosLiczb.size();
    for (int i = 0; i < stosSize; i++)
        if (!isOk (stosLiczb.top(), m))
            stosLiczb.pop();
        else return stosLiczb.top();
    if (stosLiczb.empty()) return goodA;
}

void liniowaMetodaKongruencyjna(int n, int seed, int Xmax, int* &table){
    if (n < 0) return;
    if (seed < 0 || seed > Xmax) return;
    int m = Xmax + 1;
    if (m <= 0) return;
    int *tab = new int [m-2];
    int c = findC (m);
    int a = findA (m, tab);
    if (a >= m || c >= m || a < 0 || c < 0) return;
    for (int i = 0; i < n; i++){
        seed = (a*seed+c)%m;
        table[i] = seed;
    }
}





void addytywnaMetodaKongruencyjna(int n,int seed,int Xmax, int* &table){
    if(n < 0 || Xmax < 0) return;
    if (seed < 0 || seed > Xmax) return;
    int m = Xmax + 1;
    ifstream pairs;
    pairs.open ("pairs.txt");
    int pair1, pair2;
    numberPairs(pairs, n, pair1, pair2);
    fillTable (n, seed, Xmax, table, pair1, pair2);
    livingTable (n, table, pair1, pair2, m);
    pairs.close();
}

void numberPairs (ifstream &pairs, int n, int &pair1, int &pair2){
    int number1, number2;
    bool trueFalse = 1;
    pairs >> number1;
    pairs >> number2;
    pair1 = number1;
    pair2 = number2;
    while (!pairs.eof()){
        pairs >> number1;
        pairs >> number2;
        if (number1 < n){
            pair1 = number1;
            pair2 = number2;
        }
        else break;
    }
}

void fillTable (int n, int seed, int Xmax, int* &table, int pair1, int pair2){          // Wype³nia tablicê pseudolosowymi liczbami
    liniowaMetodaKongruencyjna (n, seed, Xmax, table);
    table[0] = pair1;
    table[1] = pair2;
}

void reverseTable (int* &table, int* &tempTab, int length){                             // Odwraca tablicê
    for (int i = 0; i < length; i++)
        tempTab [length - 1 - i] = table[i];
}

void livingTable (int n, int* &table, int pair1, int pair2, int m){
    int* tempTab = new int [n];
    reverseTable (table, tempTab, n);
    for (int i = 0; i < n; i++){                                                         // Algorytm Y[k] = Y[j] + Y[k])%m <- uzupe³nia tablicê nowymi losowymi liczbami
        if (pair1 == -1) pair1 = n - 1;
        else if (pair2 == -1) pair2 = n - 1;
        tempTab[pair2] = ((tempTab[pair1] + tempTab[pair2]) % m);
        pair1--;
        pair2--;
    }
    for(int i = 0; i < n; i++)
        table[i] = tempTab[i];
    delete [] tempTab;
}

void metodaTasowaniaZJednaSekwencjaLosowa(int n, int seed, int Xmax, int* &table) {
	int* tab = new int[n + Xmax];
	int k = Xmax;
	int m = Xmax + 1;
	addytywnaMetodaKongruencyjna(n+k, seed, Xmax, tab);

	int* tempTab = new int [k];
	for (int i = 0; i < k; i++)
		tempTab[i] = tab[i];

	int y = tab[k];
	int j = (k * y) / m;

	int i = 0;
	table[i] = tempTab[j];
	tempTab[j] = y;

	for (i = 1; i < n; ++i){
		y = tab[k+i];
		j = (k * y) / m;
		table[i] = tempTab[j];
		tempTab[j] = y;
	}
	delete[] tab;
	for (int i = 0; i < n; i++)
        cout << table[i] << " ";
    cout << endl;
}
