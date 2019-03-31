#include "sortingAlgorithms.h"

using namespace std;

void seeExceptions(EXCEPTION_CODE error)
{
	switch (error) {
	case EXCEPTION_CODE::openError:
		cerr << "Blad otwarcia pliku odczytu!";
		break;
	default:
		cerr << "Nieznany blad";
		break;
	}
}
Ctable::Ctable() {
	Size = 0;
	Table = nullptr;
}
Ctable::Ctable(int _Size) {
	Size = _Size;
	Table = nullptr;
	try {
		Table = new int[Size];
	}
	catch (bad_alloc) {

		cout << "blad";
		exit(0);
	}
}
CsortTable::CsortTable(int _Size) {

	Size = _Size;
	Table = nullptr;
	try {
		Table = new int[Size];
	}
	catch (bad_alloc) {

		cout << "blad";
		exit(0);
	}
}

void Ctable::show() {
	for (int i = 0; i < Size; i++) {
		cout << Table[i]<<" ";
	}
	cout << endl;
}
void Ctable::swap(int &iTable, int &jTable) {

	int i = iTable;
	iTable = jTable;
	jTable = i;

}

void Ctable::bubbleSort(int &numberOfComparisons, int &numberOfChanges) {

	int start = 0;
	int end = Size-1;

	bool flag = true;

	while (flag) {

		flag = false;
		for (int i = start; i < end; i++) {
			numberOfComparisons++;
			if (Table[i] > Table[i + 1]) {

				swap(Table[i], Table[i + 1]);
				numberOfChanges++;
				flag = true;
			}
		}
	}
}
void Ctable::bubbleSortReverse() {

	int start = 0;
	int end = Size-1;

	bool flag = true;

	while (flag) {

		flag = false;
		for (int i = start; i < end; i++) {

			if (Table[i] < Table[i + 1]) {

				swap(Table[i], Table[i + 1]);

				flag = true;
			}
		}
	}
}
void Ctable::bubbleSort10FakeSorting() {
	int start = 0;
	int end = Size-1;

	bool flag = true;

	while (flag) {

		flag = false;
		for (int i = start; i < end; i++) {

			if (Table[i] > Table[i + 1]) {

				swap(Table[i], Table[i + 1]);

				flag = true;
			}
		}
	}
	for (int i = 0; i < end+1; i++) {
		if ((i+1) % 10 == 0) {

				Table[i] = i;

		}
	}

}
void Ctable::cocktailSort(int &numberOfComparisons, int &numberOfChanges) {

	int start = 0;
	int end = Size-1;
	bool flag = true;

	while (flag) {

		flag = false;
		for (int i = start; i < end; i++) {
			numberOfComparisons++;
			if (Table[i] > Table[i + 1]) {

				numberOfChanges++;
				swap(Table[i], Table[i + 1]);
				flag = true;
			}
		}
		end--;

		for (int i = end; i > start; i--) {
			numberOfComparisons++;
			if (Table[i] < Table[i - 1]){

				numberOfChanges++;
				swap(Table[i], Table[i - 1]);
				flag = true;
			}
		}

		start++;
	}
}

void Ctable::lomutoQuickSort(int left, int right, int &numberOfComparisons, int &numberOfChanges) {
	{

		int pivot = Table[left];
		int q = left;

		for (int i = left + 1; i <= right; i++) {
			numberOfComparisons++;
			if (Table[i] <= pivot) {
				numberOfChanges++;
				q++;
				swap(Table[i], Table[q]);
			}
		}
		swap(Table[q], Table[left]);
		numberOfChanges++;

		if (left >= right)
			return;

		lomutoQuickSort(left, q - 1, numberOfComparisons, numberOfChanges);
		lomutoQuickSort(q + 1, right, numberOfComparisons,numberOfChanges);

	}
}
void Ctable::hoareQuickSort(int left, int right, int &numberOfComparisons, int &numberOfChanges)
{
	if (left >= right)
		return;

	int s = (left + right) / 2, pivot = Table[s], i = left, j = right;
	while (i <= j) {

		while (Table[i] < pivot) {
			numberOfComparisons++;
			i++;
		}

		while (Table[j] > pivot) {
			numberOfComparisons++;
			j--;
		}

		if (i <= j) {
			numberOfChanges++;
			swap(Table[i], Table[j]);
			i++; j--;
		}
	}

	if (j > left)
		hoareQuickSort(left, j, numberOfComparisons, numberOfChanges);

	if (i < right)
		hoareQuickSort(i, right, numberOfComparisons, numberOfChanges);
}
void Ctable::heapSort(int &numberOfComparisons, int &numberOfChanges) {

	int i, j, k, m, x;

	for (i = 2; i <= Size-1; i++)
	{
		j = i; k = j / 2;
		x = Table[i];
		while ((k > 0) && (Table[k] < x))
		{
			Table[j] = Table[k];
			j = k; k = j / 2;
		}
		Table[j] = x;
	}



	for (i = Size-1; i > 1; i--)
	{
		numberOfChanges++;
		swap(Table[1], Table[i]);
		j = 1; k = 2;
		while (k < i)
		{
			numberOfComparisons++;
			if ((k + 1 < i) && (Table[k + 1] > Table[k]))
				m = k + 1;
			else
				m = k;
			numberOfComparisons++;
			if (Table[m] <= Table[j]) break;
			numberOfChanges++;
			swap(Table[j], Table[m]);
			j = m; k = j + j;
		}
	}

}

void CsortTable::fillingTableRandomly(int left, int right) {
	random_device rd;
	mt19937 mt(rd());

	uniform_int_distribution<int>dist(left, right);

	for (int i = 0; i < Size; i++) {
		Table[i] = dist(mt);
		cout << Table[i] << " ";
	}
	cout << endl;
}
void CsortTable::fillingTableRandomlyNoShow(int left, int right) {
	random_device rd;
	mt19937 mt(rd());

	uniform_int_distribution<int>dist(left, right);

	for (int i = 0; i < Size; i++) {
		Table[i] = dist(mt);
	}
}


void CsortTable::fillingTableFormKeyBoard() {
	for (int i = 0; i < Size; i++) {
		cin >> Table[i];
	}
}

