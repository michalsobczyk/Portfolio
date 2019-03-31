#include <iostream>
#include "functions.h"
#include "class.h"

using namespace std;

int main() {
	vector <przedmioty> bag;
	vector <spakowanePrzedmioty> packedbag;
	int capacity = 0;
	int numberOfItems = 0;
	int value = 0;
	int weight = 0;
	ifstream plik;
	string plikiPrzedmioty = "items.txt";
	plik.open (plikiPrzedmioty.c_str());
	if (!plik.good()){
        cout << "Blad otwarcia pliku" << endl;
        return 0;
	}
	loadprzedmioty(plik, bag, capacity);
	packing(packedbag, bag, capacity);

	numberOfItems = spakowanePrzedmioty.numberOfItems();

	for (int i = 0; i < numberOfItems; i++) {
		cout << "Ile: " << packedbag[i].getK() << " Co: " << packedbag[i].getPrzedmiot().getName() << " Ile wazy: " << packedbag[i].getPrzedmiot().getWeight()<<" Jaka cena: "<<packedbag[i].getPrzedmiot().getValue()<< endl;
		value += packedbag[i].getK()*packedbag[i].getPrzedmiot().getValue();
		weight += packedbag[i].getK()*packedbag[i].getPrzedmiot().getWeight();
	}
	cout << "Wartosc plecaka: " << value << endl;
	cout << "Waga plecaka: " << weight << endl;

	return 0;
}
