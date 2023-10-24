#include <iostream>
#include <vector>
#include <algorithm>


int main() {

    int n, n1;
    std::cin >> n;

    std::vector<int> array(n);

    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    std::cin >> n1;

    std::vector<int> array1(n1);

    for (int j = 0; j < n1; j++) {
        std::cin >> array1[j];
    }


    array.insert(array.end(), array1.begin(), array1.end()); // добавляем 1 массив в другой

    sort(array.begin(), array.end());
    // сортируем массив по возрастанию 
    sort(array1.begin(), array1.end());

    for (auto q : array) {
        // выводим все элементы отсортированного массива
        std::cout << q << " ";
    }

    return 0;
}
