#include <iostream>

class IntSharedPointer {
private:
    int* ptr;   // ��������� �� ����� �����
    int* reference_count;   // ��������� �� ������� ������

public:
    // ����������� ������
    IntSharedPointer(int* p) : ptr(p), reference_count(new int(1)) {}
    // ���������� ������
    ~IntSharedPointer() {
        (*reference_count)--;   // ��������� ������� ������ �� 1
        if (*reference_count == 0) {    // ���� ������� ������ ���� ����� 0
            delete ptr; // ����������� ������, �� ������� ��������� ptr
            delete reference_count; // ����������� ������, �� ������� ��������� reference_count
        }
    }
    // ������������� �������� ������������� *
    int& operator*() {
        return *ptr;    // ���������� ������ �� ��������, �� ������� ��������� ptr
    }
    // ����������� �����������
    IntSharedPointer(const IntSharedPointer& other) : ptr(other.ptr), reference_count(other.reference_count) {
        (*reference_count)++;   // ����������� ������� ������ �� 1
    }
    // ������������� �������� ������������ =
    IntSharedPointer& operator=(IntSharedPointer other) {
        swap(other);    // ���������� �������� � ������ �������� IntSharedPointer
        return *this;   // ���������� ������ �� ������� ������
    }
    // ����� ��� ������ ���������� � ������ �������� IntSharedPointer
    void swap(IntSharedPointer& other) {
        std::swap(ptr, other.ptr);  // ���������� �������� ���������� ptr
        std::swap(reference_count, other.reference_count);  // ���������� �������� ���������� reference_count
    }
};

void print(IntSharedPointer p) {
    std::cout << *p << std::endl;
}

void print_with_exception(IntSharedPointer p) {
    std::cout << *p << std::endl;
    if (*p % 2) throw std::string("error");
}

int main() {
    IntSharedPointer p(new int);
    std::cin >> *p;
    p = p;
    print(p);

    IntSharedPointer p2(p);
    std::cin >> *p2;
    print(p);
    print(p2);

    {
        int value;
        std::cin >> value;
        IntSharedPointer p3(new int(value));
        p2 = p3;
    }
    print(p2);

    p = p2;
    try {
        print_with_exception(p);
    }
    catch (const std::string& e) {
        std::cout << e << std::endl;
    }
}