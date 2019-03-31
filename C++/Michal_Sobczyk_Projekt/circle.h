#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape {
	int radius;
public:

	Circle(Display* w, int r);
	void draw();
};


#endif
