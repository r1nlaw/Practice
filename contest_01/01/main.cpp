#include <iostream>
#include <math.h>

using namespace std;

int main() {
	float a;
	a = (sqrt(12) * (1 - 1. / (3 * 3) + 1. / (5 * 3 * 3) - 1. / (7 * 3 * 3 * 3) + 1. / (9 * 3 * 3 * 3 * 3) - 1. / (11 * 3 * 3 * 3 * 3 * 3)));
	cout << a;
}