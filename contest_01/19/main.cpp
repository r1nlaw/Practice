#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int n = 1;

    string vvod;

    map<string, int> strokint;

    vector<string> dub;

    while (n > 0) {

        cin >> vvod;

        if (vvod == "end") {
            break;
        }
        strokint[vvod] += 1;
        if (strokint[vvod] == 2) {
            dub.push_back(vvod);
        }
    }
    sort(dub.begin(), dub.end());
    for (const auto& v : dub) {
        cout << v << " ";
    }
    return 0;
}