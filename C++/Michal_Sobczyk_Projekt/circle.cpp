#include "circle.h"

Circle::Circle(Display* w, int r) : Shape(w), radius(r) {}

void Circle::draw() {
	Shape::display->drawCircle(radius);
}
