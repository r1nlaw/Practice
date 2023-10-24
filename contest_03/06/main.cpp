#include <iostream>
#include <map>





int main() {

	std::map<std::string, int> counts;   // ������� map �� ����� � �����.

	int n;

	std::cin >> n;				//������ ���������� �����

	std::string s;

	int max_count = 0;

	for (int i = 0; i < n; i++) {
		std::cin >> s;				/* ������ ������ � ����������  ���������� 1 �� ���� ��������� ������,
									���� ����� ����������� ����� 1 ����, �� ��� count ��� ����� 2 */
		counts[s]++;

		if (counts[s] > max_count)
			max_count = counts[s];		// ������� ��������	


	}
	for (auto& vvod : counts) {
		if (vvod.second == max_count)	// ���� ������� ����� ������������� count, �� ������� ��� ��������.
			std::cout << vvod.first << " ";
	}
	return 0;

}