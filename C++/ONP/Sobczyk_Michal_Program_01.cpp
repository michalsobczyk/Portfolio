#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Lstack.h"
#include "Table.h"
#include "Tstack.h"
using namespace std;



Tstack CopenAndLoadFile();
Lstack *SopenAndLoadFile();


int main() {

	Lstack *l1 = SopenAndLoadFile();
	Tstack t1 = CopenAndLoadFile();
	cout << "STOS NA LISCIE "<<endl;
	cout <<"1. isempty 1 pusta 0 niepusta "<< lisempty(l1) << endl;
	cout <<"2. size "<< lsize(l1) << endl;
	cout <<"3. top "<< ltop(l1) << endl;
	lpop(l1);
	cout <<"4.pop usuwa top pokazuje wartosc aktualna "<< ltop(l1) << endl;
	cout << "STOS NA TABLICY "<<endl;
	cout <<"1. isempty 1 pusta 0 niepusta " << tisempty(t1) << endl;
	cout <<"2. size " << tsize(t1) << endl;
	cout <<"3. top "<< ttop(t1) << endl;
	tpop(t1);
	cout << "4.pop usuwa top pokazuje wartosc aktualna " << ttop(t1) << endl;


	getchar();
	getchar();

	return 0;
}


Tstack CopenAndLoadFile() {

	ifstream in;
	in.open("stack.txt", ios::binary);
	if (!in.good())
		exit(0);

	int n = 0;
	in >> n;
    int *S = f_createNtab(n);
	Tstack s {n, 0, S};

	for (int i = 0; i < n; i++) {
		int number = 0;
		if (in.eof())
			exit(0);

		else
			in >> number;
			tpush(s,number);
	}
	in.close();

	return s;
}
Lstack *SopenAndLoadFile() {

	ifstream in;
	in.open("stack.txt", ios::binary);
	if (!in.good())
		exit(0);

	int n = 0;
	in >> n;

	Lstack *l=nullptr;  //ustawianie glowu

	for (int i = 0; i < n; i++) {
		int number = 0;
		if (in.eof())
			exit(0);

		else
			in >> number;
			lpush(l,number);
	}
	in.close();

	return l;
}
