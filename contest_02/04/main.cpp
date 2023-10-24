#include <iostream>
#include <tuple>
#include <math.h>


std::tuple<long long, long long> reduce(long long a, long long b) {

    long long a1 = a;

    long long b1 = b;

    a = abs(a);

    b = abs(b);

    while (a && b) {

        if (a > b) a %= b;

        else b %= a;
    }
    a = a + b;

    return std::make_tuple(a1 / a, b1 / a);

}
std::tuple<long long, long long, long long> find_lcm(long long a, long long b) {
    long long m;

    long long n;

    std::tie(m, n) = reduce(a, b);

    long long result = (a * b) / (a / m);


    return std::make_tuple(result, result / a, result / b);

}