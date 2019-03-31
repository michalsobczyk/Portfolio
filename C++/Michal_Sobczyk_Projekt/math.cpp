#include <cmath>

bool isPointInTriangle(int x, int y, int x1, int y1, int x2, int y2, int x3, int y3) {

	double A1 = (static_cast<double>(y2) - y1) / (static_cast<double>(x2) - x1);
	double B1 = y1 - (A1 * x1);

	double A2 = (static_cast<double>(y3) - y1) / (static_cast<double>(x3) - x1);
	double B2 = y1 - (A2 * x1);

	double A3 = (static_cast<double>(y3) - static_cast<double>(y2)) / (static_cast<double>(x3) - static_cast<double>(x2));
	double B3 = static_cast<double>(y2) - (A3 * static_cast<double>(x2));

	double w1 = (A1 * x3 - y3 + B1)*(A1 * x - y + B1);
	double w2 = (A2 * x2 - y2 + B2)*(A2 * x - y + B2);
	double w3 = (A3 * x1 - y1 + B3)*(A3 * x - y + B3);

	if (w1 >= 0 && w2 >= 0 && w3 >= 0) {
		return true;
	}
	if (w1 == 0 || w2 == 0 || w3 == 0) {
		return true;
	}
	if (w1 != 0 && w2 != 0 && w3 != 0 && (w1 < 0 || w2 < 0 || w3 < 0)) {
		return false;
	}
	return true;
}

bool isPointInCircle(int x, int y, int r) {
	if (sqrt(x * x + y * y) <= r) {
		return true;
	}
	return false;
}

bool isPointInParallelogram(int x, int y, double A1, double B1, double B2, double A3, double B3, double B4) {

	float w1 = (A1 * x - y + B1);
	float w2 = (A1 * x - y + B2);
	float w3 = (A3 * x - y + B3);
	float w4 = (A3 * x - y + B4);

	if (w1 * w2 <= 0 && w3 * w4 <= 0) {
		return true;
	}

	return false;
}
