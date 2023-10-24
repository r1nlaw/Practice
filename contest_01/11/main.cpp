#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;

	if (abs(b - a) > abs(c - a)) {
		cout << "C " << abs(c - a);
	}
	if (abs(b - a) < abs(c - a)) {
		cout << "B " << abs(b - a);
	}
}