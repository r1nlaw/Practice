#include <iostream>

using namespace std;

int main() {
	string vvod;
	cin >> vvod;

	int kolichbukv = 1;
	char lastznak = vvod[0];
	vvod.append("*");

	for (int i = 1; i < vvod.length(); i++) {
		if (vvod[i] == lastznak) {
			kolichbukv++;
			continue;
		}
		if (vvod[i] != lastznak) {
			cout << lastznak;
			if (kolichbukv > 1) {
				cout << kolichbukv;
			}
			lastznak = vvod[i];
			kolichbukv = 1;
		}
	}
	return 0;
}