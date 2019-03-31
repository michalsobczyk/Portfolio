#ifndef GRAPHICALDISPLAY_H
#define GRAPHICALDISPLAY_H

#include <iostream>
#include "math.h"
#include "table.h"
#include "display.h"

using namespace std;


class GraphicalDisplay : public Display {
public:

	void drawTriangle(int a1, int a2, int b1, int b2);

	void drawCircle(int r);

	void drawParallelogram(int a1, int a2, int b1, int b2);
};

#endif
