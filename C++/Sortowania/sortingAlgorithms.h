#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H
#include <random>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

enum EXCEPTION_CODE {
	openError,
	saveError,
};

class Ctable{
protected:
	int *Table;
	int Size;
public:
	Ctable();
	Ctable(int _Size);
	void cocktailSort(int &numberOfComparisons, int &numberOfChanges);
	void bubbleSort(int &numberOfComparisons, int &numberOfChanges);
	void lomutoQuickSort(int left, int right, int &numberOfComparisons, int &numberOfChanges);
	void hoareQuickSort(int left, int right, int &numberOfComparisons, int &numberOfChanges);
	void heapSort(int &numberOfComparisons, int &numberOfChanges);
	void bubbleSortReverse();
	void bubbleSort10FakeSorting();
	void show();
	void swap(int &iTable, int &jTable);

};
class CsortTable : public Ctable {
	public:
		CsortTable(int _Size);
		void fillingTableFormKeyBoard();
		void fillingTableRandomly(int left, int right);
		void fillingTableRandomlyNoShow(int left, int right);

};
void desktop();
void seeExceptions(EXCEPTION_CODE error);


#endif
