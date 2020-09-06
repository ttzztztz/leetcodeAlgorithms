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

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        long long answer = 0;
        int N;
        cin >> N;
        vector<int> all;
        for (int i = 0; i < N; i++) {
            int tmp;
            cin >> tmp;
            all.push_back(tmp);
        }

        for (int i = 1; i < N - 1; i++) {
            if (all[i] > all[i - 1] && all[i] > all[i + 1]) answer++;
        }

        printf("Case #%d: %lld\n", _, answer);
    }
    return 0;
}
