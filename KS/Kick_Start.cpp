#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        long long answer = 0;
        string str;
        cin >> str;

        int ptr = 0;
        vector<int> zero, one;
        while ((ptr = str.find("KICK", ptr)) != string::npos) {
            zero.push_back(ptr);
            ptr += 1;
        }

        ptr = 0;
        while ((ptr = str.find("START", ptr)) != string::npos) {
            one.push_back(ptr);
            ptr += 1;
        }

        for (int p1 = 0, p2 = 0; p1 < zero.size(); p1++) {
            while (p2 < one.size() && one[p2] < zero[p1]) p2++;
            if (p2 < one.size()) {
                answer += one.size() - p2;
            }
        }
        printf("Case #%d: %lld\n", _, answer);
    }
    return 0;
}
