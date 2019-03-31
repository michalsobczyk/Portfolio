#include "complexShape.h"

ComplexShape::ComplexShape(Display* w) : Shape(w) {}

bool ComplexShape::add(Shape* o) {
	if (shapes.size() == 5) {
		return false;
	}
	shapes.push_back(o);
	return true;
}

void ComplexShape::draw() {
	for (unsigned int i = 0; i < shapes.size(); ++i) {
		shapes[i]->draw();
	}
}
