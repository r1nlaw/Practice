#include <iostream>

class IntSharedPointer {
private:
    int* ptr;   // Указатель на целое число
    int* reference_count;   // Указатель на счетчик ссылок

public:
    // Конструктор класса
    IntSharedPointer(int* p) : ptr(p), reference_count(new int(1)) {}
    // Деструктор класса
    ~IntSharedPointer() {
        (*reference_count)--;   // Уменьшаем счетчик ссылок на 1
        if (*reference_count == 0) {    // Если счетчик ссылок стал равен 0
            delete ptr; // Освобождаем память, на которую указывает ptr
            delete reference_count; // Освобождаем память, на которую указывает reference_count
        }
    }
    // Перегруженный оператор разыменования *
    int& operator*() {
        return *ptr;    // Возвращаем ссылку на значение, на которое указывает ptr
    }
    // Конструктор копирования
    IntSharedPointer(const IntSharedPointer& other) : ptr(other.ptr), reference_count(other.reference_count) {
        (*reference_count)++;   // Увеличиваем счетчик ссылок на 1
    }
    // Перегруженный оператор присваивания =
    IntSharedPointer& operator=(IntSharedPointer other) {
        swap(other);    // Обмениваем значения с другим объектом IntSharedPointer
        return *this;   // Возвращаем ссылку на текущий объект
    }
    // Метод для обмена значениями с другим объектом IntSharedPointer
    void swap(IntSharedPointer& other) {
        std::swap(ptr, other.ptr);  // Обмениваем значения указателей ptr
        std::swap(reference_count, other.reference_count);  // Обмениваем значения указателей reference_count
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