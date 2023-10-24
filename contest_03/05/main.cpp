#include <iostream>
#include <map>





int main() {

	std::map<std::string, int> counts;   // создаем map из строк и чисел.

	int n;

	std::cin >> n;				//вводим количество строк

	std::string s;

	int max_count = 0;

	for (int i = 0; i < n; i++) {
		std::cin >> s;				/* вводим строки и изначально  прибавляем 1 ко всем значениям строки,
									если слово встречается более 1 раза, то его count уже будет 2 */
		counts[s]++;

		if (counts[s] > max_count)
			max_count = counts[s];		// находим максимум	


	}
	for (auto& vvod : counts) {
		if (vvod.second == max_count)	// если счетчик равен максимальному count, то выводим эти значения.
			std::cout << vvod.first << " ";
	}
	return 0;

}