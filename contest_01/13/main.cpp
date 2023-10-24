#include <iostream>

using namespace std;

int main() {
	int razmerelk;
	cin >> razmerelk;

	int zhifri = 1;

	int tekDlin = 1;

	int maxDlin = 2;

	int napraw = 1;

	int stopProgramm = 0;

	for (int i = 0; i < razmerelk; i++) {
		for (int k = 0; k < tekDlin; k++) {
			cout << zhifri << " ";
			zhifri++;
			stopProgramm++;
			if (stopProgramm == razmerelk) {
				break;
			}
		}
		cout << "\n";
		tekDlin += napraw;
		if (stopProgramm == razmerelk) {
			break;
		}

		if (tekDlin == maxDlin) {
			napraw = -1;
			maxDlin++;

		}
		if (tekDlin == 1) {
			napraw = +1;
		}

	}
	return 0;
}