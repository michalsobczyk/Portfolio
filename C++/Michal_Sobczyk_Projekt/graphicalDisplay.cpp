#include "graphicalDisplay.h"

using namespace std;

void GraphicalDisplay::drawTriangle(int a1, int a2, int b1, int b2) {


		int top;

		if (a2 > b2)
			top = a2;
		else
			top = b2;

		int width, height;

		width = a1 + 1;
			if (b1 > a1)
				width = b1 + 1;

		height = abs(a2) + 1;

		if (b2 > a2)
			height = b2 + 2;
		else if (b2 < 0)
			height += abs(b2);


		char** tab = f_createTableNxM<char>(height, width);


		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				if (isPointInTriangle(j, -i + top, 0, 0, a1, b1, a2, b2)) {
					tab[i][j] = 't';
				}
				else {
					tab[i][j] = ' ';
				}
			}
		}

		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				cout << tab[i][j];
			}
			cout << endl;
		}

		for (int i = 0; i < height; ++i) {
			delete[] tab[i];
		}
		delete[] tab;
	}


void GraphicalDisplay::drawCircle(int r) {
	int	diameter = 2 * r + 1;
	char** tab = f_createTableNxM<char>(diameter, diameter);

	for (int i = 0; i < diameter; ++i) {
		for (int j = 0; j < diameter; ++j) {
			if (isPointInCircle(j - r, -i + r, r)) {
				tab[i][j] = 'o';
			}
			else {
				tab[i][j] = ' ';
			}
		}
	}


	for (int i = 0; i < diameter; ++i) {
		for (int j = 0; j < diameter; ++j) {
			cout << tab[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < diameter; ++i) {
		delete[] tab[i];
	}
	delete[] tab;

}

void GraphicalDisplay::drawParallelogram(int a1, int a2, int b1, int b2) {
	using std::cout;
	using std::endl;

	double A1 = static_cast<double>(a2) / static_cast<double>(a1);
	double B1 = 0;

	double B2 = a2 + b2 - (A1 * (a1 + b1));

	double A3 = static_cast<double>(b2) / static_cast<double>(b1);
	double B3 = 0;

	double B4 = a2 + b2 - (A3 * (a1 + b1));

	int width = a1 + b1;

	for (int i = a2; i >= b2; --i) {
		for (int j = 0; j <= width; ++j) {
			if (isPointInParallelogram(j, i, A1, B1, B2, A3, B3, B4)) {
				cout << "p";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
}
