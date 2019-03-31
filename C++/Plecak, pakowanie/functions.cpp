#include "functions.h"

void loadprzedmioty (ifstream &plik, vector <przedmioty> &przedmioty, int &pojemnosc){                          // wczytywanie przedmiotow do vectora
    char load;
    string name;
    int weight, prize;
    plik >> pojemnosc;
    while (!plik.eof()){
        plik >> name;
        plik >> load;
        plik >> weight;
        plik >> load;
        plik >> prize;
        plik >> load;
        przedmioty przedmiot (name, weight, prize);
        przedmioty.push_back (przedmiot);
    }
    plik.close();
}


void packing(vector <spakowanePrzedmioty> &packedbag, vector <przedmioty> przedmioty, int pojemnosc){           // algorytm zach³anny
	int numberOfprzedmioty = przedmioty.size();
	for (int i = 0; i < numberOfprzedmioty; i++) {
		int ileZabrano = 0;
		while (pojemnosc >= przedmioty[i].getWeight()) {
			pojemnosc -= przedmioty[i].getWeight();
			ileZabrano++;
		}
		if (ileZabrano > 0) {
			spakowanePrzedmioty przedmiot (przedmioty[i], ileZabrano);
			packedbag.push_back(przedmiot);
		}
	}
}


void packingDynamic(ifstream &plik, vector <przedmioty> przedmiotyvector, int pojemnosc) {                      // programowanie dynamiczne

	int wielkosc = przedmiotyvector.size();
	vector <int> value;
	vector <int> weight;
	vector <int> cost;
	vector <int> best;

	for (int i = 0; i < wielkosc; i++) {
		value.push_back(przedmiotyvector[i].get_value());
		weight.push_back(przedmiotyvector[i].get_weight());
	}
	for (int i = 0; i < pojemnosc + 1; i++) {
		cost.push_back(0);
		best.push_back(0);
	}

	for (int i = 1; i < wielkosc+1; i++) {
		for (int j = 1; j < pojemnosc+1; j++) {
			if (j >= weight[i-1]) {
				if (cost[j] < cost[j - weight[i-1]] + value[i-1]) {
					cost[j] = cost[j - weight[i-1]] + value[i-1];
					best[j] = i;
				}
			}
		}
	}
	for (int i = 0; i < pojemnosc+1; i++) {
		cout << cost[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < pojemnosc + 1; i++) {
		cout << best[i] << " ";
	}
}

void recursionLoadBag(ifstream &plik) {                                                     // rekurencja, wypelniamy plecak do max, brak cen przedmiotow

	int numberOfSets = 0, pojemnosc = 0, volume = 0, numbers = 0, poczatek = 0;
	plik >> numberOfSets;

	while (!plik.eof()) {
		plik >> pojemnosc;
		plik >> volume;
		vector <int> przedmioty;
		for (int i = 0; i < volume; i++) {
			plik >> numbers;
			przedmioty.push_back(numbers);
		}
		vector <int> spakowanePrzedmioty;
		int a = recursionPackingBag(spakowanePrzedmioty, przedmioty, 0, pojemnosc);

		if (a == 1) {
			cout << pojemnosc << " = ";
			int wielkosc = spakowanePrzedmioty.size();
			for (int i = 0; i < wielkosc; i++) {
				cout << spakowanePrzedmioty[i] << " ";
			}
			cout << endl;
		}
		else
			cout << "Brak"<<endl;
		przedmioty.clear();
		spakowanePrzedmioty.clear();
	}
	plik.close();
}

bool recursionPackingBag(vector <int> &spakowanePrzedmioty, vector <int> &przedmioty, int poczatek, int pojemnosc) {    //rekurencja
    bool takNie;
	if (pojemnosc == 0) {
        return true;
	}
	else if (poczatek+1 > przedmioty.size() || pojemnosc < 0) {
        return false;
	}
	spakowanePrzedmioty.push_back(przedmioty[poczatek]);
    takNie = recursionPackingBag(spakowanePrzedmioty, przedmioty, poczatek + 1, pojemnosc - przedmioty[poczatek]);      //pakujemy kolejny przedmiot (poczatek + 1), pojemnosc zmniejszamy o ten przedmiot zapakowany

	if (takNie == 1) {
        return takNie;
	}
    else{
	spakowanePrzedmioty.pop_back();
	takNie = recursionPackingBag(spakowanePrzedmioty, przedmioty, poczatek + 1, pojemnosc);
	return takNie;
    }
}
