#include <iostream>

class Keeper {
    int trash;
    int secret;

public:
    Keeper() {
        std::cin >> secret;
    }
};

int hack_it(Keeper& keeper) {
    return *(reinterpret_cast<int*>(&keeper) + 1);
}

int main() {
    Keeper keeper;
    int secret = hack_it(keeper);
    std::cout << secret;
}