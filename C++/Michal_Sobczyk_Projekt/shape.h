
#ifndef SHAPE_H
#define SHAPE_H

#include "display.h"


class Shape {
protected:
	Display * display;
public:

	Shape(Display* w);
	virtual void draw() {}
	void changeDisplay(Display* newDisplay);
};
#endif#pragma once
