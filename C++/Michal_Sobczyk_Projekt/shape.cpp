#include "shape.h"

Shape::Shape(Display* w): display(w) {}

void Shape::changeDisplay(Display* newDisplay) {
	display = newDisplay;
}
