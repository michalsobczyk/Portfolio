#include "desktop.h"

int **f_createNxMtab(int n, int m) {
	int **T = nullptr;
	try {
		T = new int*[n];
	}
	catch (bad_alloc) {

		cout << "blad";
		exit(0);
	}
	for (int i = 0; i < n; i++) {
		try {
			T[i] = new int[m];
		}
		catch (bad_alloc) {
			exit(0);
		}
	}
	return T;
}

void desktop(string filename) {

	int wybor;
	cout << "1. Sand box " << endl;
	cout << "2. Tryb demonstracyjny" << endl;
	cin >> wybor;
	system("cls");
	switch (wybor) {
	case 1: {

		int Size, wybor1, wybor2, a, b;
		cout << "1. Wprowadz wielkosc tablicy : ";
		cin >> Size;
		CsortTable SandBox(Size);
		system("cls");
		cout << "1. Wprowadz liczby do tablicy recznie " << endl;
		cout << "2. Wygeneruj losowe liczby z zakresu od a do b " << endl;
		cin >> wybor1;
		system("cls");

		if (wybor1 == 1) {
			SandBox.fillingTableFormKeyBoard();
			system("cls");
		}
		else if (wybor1 == 2) {

			cout << "Podaj a i b ";
			cin >> a >> b;
			SandBox.fillingTableRandomly(a, b);
			system("cls");
		}

		SandBox.show();
		cout << "nacisnij enter, aby kontunuowac...";
		getchar();
		getchar();
		system("cls");
		char sign = 'Y';
		while (sign == 'Y' || sign == 'y') {
			cout << "1. bubble sort " << endl;
			cout << "2. coctail sort " << endl;
			cout << "3. lomuto quick sort" << endl;
			cout << "4. hoare quick sort" << endl;
			cout << "5. heap sort" << endl;
			cin >> wybor2;
			int numberOfComparisons = 0, numberOfChanges = 0;
			switch (wybor2) {

			case 1:
				numberOfComparisons = 0, numberOfChanges = 0;
				SandBox.bubbleSort(numberOfComparisons, numberOfChanges);
				SandBox.show();
				cout << numberOfComparisons << " " << numberOfChanges;

				break;
			case 2:
				numberOfComparisons = 0, numberOfChanges = 0;
				SandBox.cocktailSort(numberOfComparisons, numberOfChanges);
				SandBox.show();
				cout << numberOfComparisons << " " << numberOfChanges;

				break;
			case 3:
				numberOfComparisons = 0, numberOfChanges = 0;
				SandBox.lomutoQuickSort(0, Size, numberOfComparisons, numberOfChanges);
				SandBox.show();
				cout << numberOfComparisons << " " << numberOfChanges;

				break;
			case 4:
				numberOfComparisons = 0, numberOfChanges = 0;
				SandBox.hoareQuickSort(0, Size, numberOfComparisons, numberOfChanges);
				SandBox.show();
				cout << numberOfComparisons << " " << numberOfChanges;

				break;
			case 5:
				numberOfComparisons = 0, numberOfChanges = 0;
				SandBox.heapSort(numberOfComparisons, numberOfChanges);
				SandBox.show();
				cout << numberOfComparisons << " " << numberOfChanges;

				break;
			default:
				cout << "ERROR";
				cin >> wybor2;
				break;

			}

			cout << "nacisnij enter, aby kontunuowac...";
			getchar();
			getchar();
			system("cls");
			cout << "chcesz kontunuowac zabawe Y or N? ";
			cin >> sign;
			SandBox.fillingTableRandomly(a, b);
			cout << "nacisnij enter, aby kontunuowac...";
			getchar();
			getchar();


		}
		break;
	}
	case 2: {

		int a = 0, n = 0;;
		cout << "1. N = 100 " << endl;
		cout << "2. N = 1000 " << endl;
		cout << "3. N = 1000 000 " << endl;

		int **changesTable = nullptr;
		changesTable = f_createNxMtab(20, 2);
		for (int i = 0; i < 20; i++) {
			changesTable[i][0] = 0;
			changesTable[i][1] = 0;
		}
		cin >> a;
		switch (a) {
		case 1:
			n = 100;
			break;
		case 2:
			n = 1000;
			break;
		case 3:
			n = 1000000;
			break;
		default:
			cout << " Blad podaj liczbe od 1 do 3 ";
			cin >> a;
			break;
		}


		CsortTable test(n);


		int i = 0;


		// randomly filled array
		test.fillingTableRandomlyNoShow(1, 99);
		test.bubbleSort(changesTable[i][0], changesTable[i][1]);
		i++;

		test.fillingTableRandomlyNoShow(1, 99);
		test.cocktailSort(changesTable[i][0], changesTable[i][1]);
		i++;

		test.fillingTableRandomlyNoShow(1, 99);
		test.lomutoQuickSort(0, 99, changesTable[i][0], changesTable[i][1]);
		i++;

		test.fillingTableRandomlyNoShow(1, 99);
		test.hoareQuickSort(0, 99, changesTable[i][0], changesTable[i][1]);
		i++;

		test.fillingTableRandomlyNoShow(1, 99);
		test.heapSort(changesTable[i][0], changesTable[i][1]);
		i++;

		//sorted array
		test.bubbleSort(changesTable[i][0], changesTable[i][1]);
		i++;

		test.cocktailSort(changesTable[i][0], changesTable[i][1]);
		i++;

		test.lomutoQuickSort(0, 99, changesTable[i][0], changesTable[i][1]);
		i++;

		test.hoareQuickSort(0, 99, changesTable[i][0], changesTable[i][1]);
		i++;

		test.heapSort(changesTable[i][0], changesTable[i][1]);
		i++;

		//reverse sorted array

		test.bubbleSortReverse();
		test.bubbleSort(changesTable[i][0], changesTable[i][1]);
		i++;

		test.bubbleSortReverse();
		test.cocktailSort(changesTable[i][0], changesTable[i][1]);
		i++;

		test.bubbleSortReverse();
		test.lomutoQuickSort(0, 99, changesTable[i][0], changesTable[i][1]);
		i++;

		test.bubbleSortReverse();
		test.hoareQuickSort(0, 99, changesTable[i][0], changesTable[i][1]);
		i++;

		test.bubbleSortReverse();
		test.heapSort(changesTable[i][0], changesTable[i][1]);
		i++;

		//10% fake sorted

		test.bubbleSort10FakeSorting();
		test.bubbleSort(changesTable[i][0], changesTable[i][1]);
		i++;

		test.bubbleSort10FakeSorting();
		test.cocktailSort(changesTable[i][0], changesTable[i][1]);
		i++;

		test.bubbleSort10FakeSorting();
		test.lomutoQuickSort(0, 99, changesTable[i][0], changesTable[i][1]);
		i++;

		test.bubbleSort10FakeSorting();
		test.hoareQuickSort(0, 99, changesTable[i][0], changesTable[i][1]);
		i++;

		test.bubbleSort10FakeSorting();
		test.heapSort(changesTable[i][0], changesTable[i][1]);
		i++;

		for (int i = 0; i < 20; i++) {
			cout << changesTable[i][0] << " " << changesTable[i][1] << endl;
			if ((i + 1) % 5 == 0)
				cout << "------------------" << endl;
		}
		ofstream out;
		out.open(filename.c_str());
		if (!out.good()) {
			throw EXCEPTION_CODE::saveError;
		}
		string sortingMetod[] = { "BubbleSort","CoctailSort","LomutoQuickSort","HoareQuickSort","HeapSort" };
		string name[] = { "random","sorted","sorted descending","10%fakeInformations" };
		for (int i = 0; i < 20; i++)
				out << setw(20) << sortingMetod[i%5] << " " << n << " "<< setw(20) << name[i/5]<<" "<< changesTable[i][0] << " " << changesTable[i][1] << endl;


		break;
	}

	}
}
