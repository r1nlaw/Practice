#include <iostream>
#include <math.h>

using namespace std;

bool is_prime(unsigned int number) {
    int i = 2;
    while (pow(i, 2) < number) {
        if (number % i == 0) {
            return false;
        }
        i++;
    }
    if (number % i == 0) {
        return false;
    }
    return true;
}