#ifndef CLASS_H
#define CLASS_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class przedmioty{
    string nazwa;
    int wartosc;
    int waga;
public:
    przedmioty(){
        this->nazwa = "brak";
        this->wartosc = 0;
        this->waga = 0;
    }
    przedmioty (string nazwa, int wartosc, int waga){
    this->nazwa = nazwa;
    this->wartosc = wartosc;
    this->waga = waga;
    }

    string getName(){
        return nazwa;
    }

    int getValue(){
        return wartosc;
    }

    int getWeight(){
        return waga;
    }
};


class spakowanePrzedmioty {
	przedmioty przedmiot;
	int numberOfItems;
public:
	spakowanePrzedmioty(przedmioty przedmiot, int numberOfItems) {
		this->przedmiot = przedmiot;
		this->numberOfItems = numberOfItems;
	}

	przedmioty getPrzedmiot(){
		return przedmiot;
	}

	int getnumberOfItems() {
		return numberOfItems;
	}
};



#endif // CLASS_H
