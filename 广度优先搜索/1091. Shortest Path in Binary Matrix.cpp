#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    vector<int> v = {1,1,1,1,1,2,2,2,2,2,2,3,4,5,6};
    int left = 0, right = v.size() - 1;

    const int val = 2;
    while (left < right) {
        const int middle = (left + right) >> 1;
        if (val < v[middle]) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }

    cout << left << endl << right;
}