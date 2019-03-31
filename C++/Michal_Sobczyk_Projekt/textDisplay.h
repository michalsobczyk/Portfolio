
#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "display.h"

using namespace std;

class TextDisplay : public Display {
public:

	void drawTriangle(int a1, int a2, int b1, int b2);

	void drawCircle(int r);

	void drawParallelogram(int a1, int a2, int b1, int b2);
};

#endif
