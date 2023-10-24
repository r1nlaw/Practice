#include <iostream> 
using namespace std;

int main() {
	int input;
	cin >> input;
	string f;

	while (input != 0) {
		input -= 1;
		f = char(input % 26 + 'A') + f;
		input /= 26;




	}
	cout << f;

}