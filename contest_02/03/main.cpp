#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool compare(string firstf, string secondf) {

    int first = stoi(firstf);

    int second = stoi(secondf);

    int first_r = first;

    int second_r = second;

    int count_first = 0;

    int count_second = 0;


    while (first > 0) {

        count_first += first % 10;

        first = first / 10;
    }
    while (second > 0) {

        count_second += second % 10;

        second = second / 10;
    }

    if (count_first == count_second) {

        return first_r < second_r;
    }


    return count_first > count_second;

}
