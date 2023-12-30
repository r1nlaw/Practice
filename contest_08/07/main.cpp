#include <iostream>
#include <vector>

class IComparator {
public:
    virtual bool compare(int a, int b) const = 0;
};

bool less(int a, int b) {
    return a < b;
}

void greater(int a, int b, bool& verdict) {
    verdict = a > b;
}

double key_func(int value) {
    return abs(value);
}

class LessAdapter : public IComparator {
    using func = bool (*)(int a, int b);
    func cmp;
public:
    LessAdapter(func cmp) : cmp(cmp) {
    }

    bool compare(int a, int b) const override {
        return cmp(a, b);
    }
};

class GreaterAdapter : public IComparator { //Класс GreaterAdapter является адаптером для функции cmp, которая имеет сигнатуру void (*)(int a, int b, bool& verdict). Он наследуется от базового класса IComparator
    using func = void (*)(int a, int b, bool& verdict);	// объявление псевдонима
    func cmp; // приватное поле класса, которое хранит указатель на функцию типа func.
public:
    GreaterAdapter(func cmp) : cmp(cmp) { //  конструктор класса, который принимает указатель на функцию cmp и сохраняет его в поле cmp.
    }

    bool compare(int a, int b) const override { // переопределенный метод compare из базового класса IComparator
        bool verdict; // Создается переменная verdict типа bool, которая будет содержать результат сравнения.
        cmp(a, b, verdict); // Вызывается функция cmp с аргументами a, b и переменной verdict
        return verdict;
    }
};

class KeyFuncLessAdapter : public IComparator { // KeyFuncLessAdapter также является адаптером, но для функции keyFunc, которая имеет сигнатуру double (*)(int value)
    using func = double (*)(int value); // объявление псевдонима типа func для указателя на функцию с требуемой сигнатурой.
    func keyFunc; // приватное поле класса, которое хранит указатель на функцию типа func.
public:
    KeyFuncLessAdapter(func keyFunc) : keyFunc(keyFunc) { // конструктор класса, который принимает указатель на функцию keyFunc и сохраняет его в поле keyFunc.
    }

    bool compare(int a, int b) const override {	// переопределенный метод compare из базового класса IComparator.
        return keyFunc(a) < keyFunc(b); // Вызывается функция keyFunc с аргументом a и сравнивается с вызовом функции keyFunc с аргументом b.
    }
};
void bubbleSort(std::vector<int>& arr, const IComparator& comp) {
    for (int i = 0; i < arr.size() - 1; i++)
        for (int j = 0; j < arr.size() - i - 1; j++)
            if (comp.compare(arr[j], arr[j + 1]))
                std::swap(arr[j], arr[j + 1]);
}

int main() {
    int size;
    std::cin >> size;

    std::vector<int> arr(size);
    for (auto& i : arr) std::cin >> i;

    bubbleSort(arr, LessAdapter(less));
    for (auto i : arr) std::cout << i << ' ';

    std::cout << std::endl;

    bubbleSort(arr, GreaterAdapter(greater));
    for (auto i : arr) std::cout << i << ' ';

    std::cout << std::endl;

    bubbleSort(arr, KeyFuncLessAdapter(key_func));
    for (auto i : arr) std::cout << i << ' ';

    std::cout << std::endl;

    bubbleSort(arr, KeyFuncLessAdapter([](int value)->double {
        return abs(value) % 2;
        }));


    for (auto i : arr) std::cout << i << ' ';
}