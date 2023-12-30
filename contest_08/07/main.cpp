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

class GreaterAdapter : public IComparator { //����� GreaterAdapter �������� ��������� ��� ������� cmp, ������� ����� ��������� void (*)(int a, int b, bool& verdict). �� ����������� �� �������� ������ IComparator
    using func = void (*)(int a, int b, bool& verdict);	// ���������� ����������
    func cmp; // ��������� ���� ������, ������� ������ ��������� �� ������� ���� func.
public:
    GreaterAdapter(func cmp) : cmp(cmp) { //  ����������� ������, ������� ��������� ��������� �� ������� cmp � ��������� ��� � ���� cmp.
    }

    bool compare(int a, int b) const override { // ���������������� ����� compare �� �������� ������ IComparator
        bool verdict; // ��������� ���������� verdict ���� bool, ������� ����� ��������� ��������� ���������.
        cmp(a, b, verdict); // ���������� ������� cmp � ����������� a, b � ���������� verdict
        return verdict;
    }
};

class KeyFuncLessAdapter : public IComparator { // KeyFuncLessAdapter ����� �������� ���������, �� ��� ������� keyFunc, ������� ����� ��������� double (*)(int value)
    using func = double (*)(int value); // ���������� ���������� ���� func ��� ��������� �� ������� � ��������� ����������.
    func keyFunc; // ��������� ���� ������, ������� ������ ��������� �� ������� ���� func.
public:
    KeyFuncLessAdapter(func keyFunc) : keyFunc(keyFunc) { // ����������� ������, ������� ��������� ��������� �� ������� keyFunc � ��������� ��� � ���� keyFunc.
    }

    bool compare(int a, int b) const override {	// ���������������� ����� compare �� �������� ������ IComparator.
        return keyFunc(a) < keyFunc(b); // ���������� ������� keyFunc � ���������� a � ������������ � ������� ������� keyFunc � ���������� b.
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