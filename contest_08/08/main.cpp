#include <iostream>
#include <string>

class Document {
    std::string data;
public:
    Document(std::string data) :data(data) {
    }

    const std::string& get() const {
        return data;
    }
};

class PrintStrategy {
public:
    virtual void print(const Document& document) = 0;
};


class Printer {
    PrintStrategy* strategy;

public:
    Printer(PrintStrategy* strategy) :strategy(strategy) {
    }

    void setStrategy(PrintStrategy* strategy) {
        delete this->strategy;
        this->strategy = strategy;
    }

    void print(const Document& doc) {
        if (strategy == nullptr) exit(1);

        strategy->print(doc);
    }

    ~Printer() {
        delete strategy;
    }
};

class ScreenPrintStrategy : public PrintStrategy {
public:
    void print(const Document& document) override {
        std::cout << document.get() << std::endl;
    }
};
class StringPrintStrategy : public PrintStrategy {
public:
    std::string text;
    int n = 0;
    StringPrintStrategy() {}
    void print(const Document& document) override {
        n += 1;
        text += "--- doc " + std::to_string(n) + " ---\n"
            + document.get() + "\n";
    }
    std::string getPrintedDocuments() { return text; }
};
class MockPrintStrategy : public PrintStrategy {
public:
    int n = 0;
    MockPrintStrategy() {}
    void print(const Document& document) override { n += 1; }
    int getPrintedDocumentsCount() { return n; }
};
int main() {
    Printer printer(new ScreenPrintStrategy());

    int count;
    std::cin >> count; std::cin.ignore(1);
    while (count--) {
        std::string data;
        std::getline(std::cin, data);
        printer.print(Document(data)); // ������ ��������� �� �����
    }

    StringPrintStrategy* stringStrategy = new StringPrintStrategy();
    printer.setStrategy(stringStrategy);
    std::cin >> count; std::cin.ignore(1);
    while (count--) {
        std::string data;
        std::getline(std::cin, data);
        printer.print(Document(data)); // ������ ��������� � ������
    }
    std::cout << stringStrategy->getPrintedDocuments() << std::endl;


    MockPrintStrategy* mockStrategy = new MockPrintStrategy();
    printer.setStrategy(mockStrategy);
    std::cin >> count; std::cin.ignore(1);
    while (count--) {
        std::string data;
        std::getline(std::cin, data);
        printer.print(Document(data)); // �������� ������, �� ����� ���� ������ �������
    }
    std::cout << mockStrategy->getPrintedDocumentsCount() << std::endl;
}