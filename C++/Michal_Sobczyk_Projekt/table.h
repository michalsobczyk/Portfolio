//#pragma once
#ifndef TABLE_H
#define TABLE_H

/*
tworzy tablice dwuwymiarowa
*/
template <typename T>
T** f_createTableNxM(int n, int m) {
	T** Table = nullptr;

	try {
		Table = new T*[n];
	}
	catch (std::bad_alloc) {
		exit(0);
	}

	for (int i = 0; i < n; ++i) {
		try {
			Table[i] = new T[m];
		}
		catch (std::bad_alloc) {
			exit(0);
		}
	}

	return Table;
}

#endif
