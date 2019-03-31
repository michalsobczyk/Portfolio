
#ifndef COMPLEXSHAPE_H
#define COMPLEXSHAPE_H

#include "shape.h"
#include <vector>

class ComplexShape : public Shape {
	std::vector<Shape*> shapes;

public:
	ComplexShape(Display* w);

	bool add(Shape* o);

	void draw();
};


#endif
