//#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"

class Triangle : public Shape {
	int a1, a2, b1, b2;
public:
	
	Triangle(Display* w, int x1, int y1, int x2, int y2);
	void draw();
};


#endif