#include "triangle.h"

Triangle::Triangle(Display* w, int x1, int y1, int x2, int y2) : Shape(w) {
	a1 = x1;
	a2 = y1;
	b1 = x2;
	b2 = y2;
}

void Triangle::draw() {
	Shape::display->drawTriangle(a1, a2, b1, b2);
}
