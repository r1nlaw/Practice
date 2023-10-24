#include <iostream>
#include <string>
#include <set>



int main() {

    int n;

    std::cin >> n;

    std::string text1;

    std::set<std::string> sett;

    for (int i = 0; i < n; i++) {

        std::cin >> text1;

        sett.insert(text1);
    }

    int h;

    std::cin >> h;



    std::set<std::string> sett2;

    std::string text2;


    for (int j = 0; j < h; j++) {

        std::cin >> text2;

        sett2.insert(text2);
    }

    int count = 0;
    for (auto& entry : sett) {
        bool boolinfo = sett2.count(entry);
        if (boolinfo == true) {
            count = 1;
            std::cout << entry << " ";

        }


    }
    if (count == 0) {
        std::cout << -1;

    }



}