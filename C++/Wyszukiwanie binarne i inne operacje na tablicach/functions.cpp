#include "functions.h"

using namespace std;

int* f_createtable(int x) {
	int *T = nullptr;
	try {
		T = new int[x];
	}
	catch (bad_alloc) {
		cout << "!alloc" << endl;
		return 0;
	}
	return T;
}

void f_deleteTable(int *T) {
	delete[] T;
}

// Wyszukiwanie binarne pierwszego elementu
int searchFirst(int searchingNumber, int* tabOfNumber, int leng) {
	int left = 0, right = leng - 1, middle = 0;
	while (left <= right) {
		middle = (left + right) / 2;
		if (tabOfNumber[middle] == searchingNumber) {
			if (middle == 0)
				return 0;
			if (tabOfNumber[middle - 1] == searchingNumber)
				right = middle - 1;
			else
				return middle;
		}
		else if (tabOfNumber[middle] < searchingNumber)
			left = middle + 1;
		else if (tabOfNumber[middle] > searchingNumber)
			right = middle - 1;
	}
	return -1;
}

// Wyszukiwanie binarne ostatniego elementu
int searchLast(int searchingNumber, int* tabOfNumber, int leng) {
	int left = 0, right = leng - 1, middle = 0;
	while (left <= right) {
		middle = (left + right) / 2;
		if (tabOfNumber[middle] == searchingNumber) {
			if (middle == leng - 1)
				return middle;
			if (tabOfNumber[middle + 1] == searchingNumber)
				left = middle + 1;
			else
				return middle;
		}
		else if (tabOfNumber[middle] < searchingNumber)
			left = middle + 1;
		else if (tabOfNumber[middle] > searchingNumber)
			right = middle - 1;
	}
	return -1;
}

// Usuwanie duplikatów
int* removingDuplicates(int* tabOfNumber, int tabLength) {
	int *tempTab = nullptr;
	int j = 1;
	tempTab = f_createtable(tabLength + 1);
	for (int i = 0; i < tabLength; i++) {
		if (tabOfNumber[i] != tabOfNumber[i + 1]) {
			tempTab[j] = tabOfNumber[i];
			j++;
		}
	}
	tempTab[0] = j;
	return tempTab;
}

// Wyszukiwanie indexu za pomoc¹ wzoru
int f_indexsearching (int searchingNumber, int* tabOfNumber, int leng){
    int left = 0, right = leng - 1, middle = 0, number = 0;
    middle = (left + right) / 2;
    if (tabOfNumber[left] == tabOfNumber[right])
        return 0;
    while ((tabOfNumber[left] <= searchingNumber) && (searchingNumber <= tabOfNumber[right]))
	{
		middle = left + (searchingNumber - tabOfNumber[left])*(right - left) / (tabOfNumber[right] - tabOfNumber[left]);
		if (tabOfNumber[middle] == searchingNumber)
		{
			return middle;
		}
		else if (searchingNumber < tabOfNumber[middle])
			right = middle - 1;
		else
			left = middle + 1;
	}
}


bool loadFile(string fileName) {
	fstream file;

	int *T1 = nullptr;
	int *T2 = nullptr;
	int *T3 = nullptr;
	int *T4 = nullptr;
	int a, num1, num2, tempFirst, tempLast, l = 0, x2num2 = 0;
	string out;
    cout << "Podaj nazwe pliku wyjsciowego, bez rozszerzenia .txt, program sam dolozy" << endl;
	cin >> out;
	out = out + ".txt";
    file.open(fileName.c_str());
	if (!file.good())
		return false;
	else {
		file >> a;
        ofstream data;
		data.open(out.c_str());
			for (int k = 0; k < a; k++) {
				file >> num1;
				T1 = f_createtable(num1);
				for (int i = 0; i < num1; i++) {
					if (file.good())
						file >> T1[i];
					else break;
				}
				file >> num2;
                x2num2 = 2 * num2;
				T2 = f_createtable(num2);
				for (int j = 0; j < num2; j++) {
					if (file.good())
						file >> T2[j];
					else break;
				}
				T3 = f_createtable(x2num2);
				for (int i = 0; i < num2; i++) {
					tempFirst = searchFirst(T2[i], T1, num1);
					if (tempFirst != -1) {
						tempLast = searchLast(T2[i], T1, num1);
						T3[l] = (tempLast - tempFirst) + 1;
						l++;
						T3[l] = f_indexsearching(T2[i], T1, num1);
						l++;
					}
					else {
						T3[l] = 0;
						l++;
						T3[l] = -1;
						l++;
					}
				}
				T4 = f_createtable(num1);
				T4 = removingDuplicates(T1, num1);
				for (int i = 0; i < x2num2; i++){
                    data << '(' << T3[i];
                    i++;
                    data << ' ' << T3[i] << ')' << ' ';
                }
                l = 0;
				data << endl;
				for (int i = 1; i < T4[0]; i++)
					data << T4[i] << " ";
                data << endl;
			}
        data.close();
	}
	file.close();
}
