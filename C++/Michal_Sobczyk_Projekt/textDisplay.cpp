#include <iostream>
#include "textDisplay.h"

using namespace std;

void TextDisplay::drawTriangle(int a1, int a2, int b1, int b2) {
	cout << "Drawing a triangle from vectors (" << a1 << ", " << a2 << "), (" << b1 << ", " << b2 << ")." << endl;
}

void TextDisplay::drawCircle(int r) {
	cout << "Drawing a circle from radius " << r << "." << endl;

}
void TextDisplay::drawParallelogram(int a1, int a2, int b1, int b2) {
	cout << "Drawing a parallelogram from vectors (" << a1 << ", " << a2 << "), (" << b1 << ", " << b2 << ")." << endl;

}
