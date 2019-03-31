#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
    int value;
    cout << "1. Liniowa metoda kongruencyjna" << endl << "2. Addytywna metoda kongruencyjna" << endl << "3. Metoda tasowania z 1 sekwencja losowa" << endl;
    cout << "Wybieram: ";
    cin >> value;
    if (value != 1 && value !=2 && value !=3){
        cout << "Podana wartosc nie wynosi ani 1, ani 2, ani 3" << endl;
        return 0;
    }
    int n, seed, Xmax;
    f_getParameters(n, seed, Xmax);
    int* table = new int [n];
    switch (value) {
    case 1:
        liniowaMetodaKongruencyjna(n, seed, Xmax, table);
        break;
    case 2:
        addytywnaMetodaKongruencyjna(n, seed, Xmax, table);
        break;
    case 3:
        metodaTasowaniaZJednaSekwencjaLosowa(n, seed, Xmax, table);
        break;
    default:
        cout << "Podana wartosc nie wynosi ani 1, ani 2, ani 3" << endl;
        break;
    }
    return 0;
}
