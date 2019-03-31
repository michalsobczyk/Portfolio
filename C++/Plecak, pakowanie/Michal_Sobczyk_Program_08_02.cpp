#include "functions.h"
#include "class.h"

int main(){
	vector <przedmioty> bag;
	vector <przedmioty> dynamicBag;
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
	loadItems(plik, bag, capacity);
	packingDynamic(bag, capacity);
	return 0;
}
