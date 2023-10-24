#include <iostream>
#include <vector>

using namespace std;

bool ifTrue(int count1, int count2, int count3) {

	if (count1 > 0 || count2 > 0 || count3 > 0) {
		return false;
	}
	if (count1 < 0 || count2 < 0 || count3 < 0) {
		return false;
	}
	/* ������� �������, ��� ������� ������� ifTrue
	����� ���������� true ������ � ��� ������,
	���� ��� �������� �� ����� ����� ����� 0.
	*/


	if (count1 == 0 && count2 == 0 && count3 == 0) {
		return true;
	}

}


int main() {


	char a;

	int count1 = 0, count2 = 0, count3 = 0;

	string ftg = "";							// ������� ���������� ��� �������� �� �������� ������.


	vector<char> mn(1);

	for (int i = 0; mn.back() != '!'; i++) {
		// ������ ������ �� ! �����
		cin >> a;
		mn.push_back(a);

	}

	for (int j = 0; j < mn.size(); j++) {

		if (mn[j] == '(') {
			count1 += 1;
			ftg.push_back(')');					// ��������� �������� �� �������� ������
		}

		if (mn[j] == ')') {
			if (ftg.back() != ')') {
				count1 = -1;
				break;
			}
			else {
				ftg.pop_back();
				count1 -= 1;
			}
		}
		/* ���� ��������� ���� �� ��������� ')',
		�� ������������� ����������� ���������� ��������,
		������� � ���������� 100 % ���� false */
		if (mn[j] == '{') {
			count2 += 1;
			ftg.push_back('}');

		}
		if (mn[j] == '}') {
			if (ftg.back() != '}') {
				count2 = -1;
				break;
			}
			else {
				ftg.pop_back();
				count2 -= 1;
			}
		}
		if (mn[j] == '[') {
			count3 += 1;
			ftg.push_back(']');


		}
		if (mn[j] == ']') {
			if (ftg.back() != ']') {
				count3 = -1;
				break;
			}
			else {
				ftg.pop_back();
				count3 -= 1;
			}
		}

	}

	cout << (ifTrue(count1, count2, count3) ? "YES" : "NO");

}