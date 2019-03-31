//#pragma once
#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "shape.h"

class Parallelogram : public Shape {
	int a1, a2, b1, b2;
public:

	Parallelogram(Display* w, int x1, int y1, int x2, int y2);

	void draw();
};

#endif
