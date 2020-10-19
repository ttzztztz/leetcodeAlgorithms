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
        int n;
        cin >> n;
        vector<vector<long long>> all(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> all[i][j];
            }
        }

        for (int i = 0; i < n; i++) { // (x, 0)
            long long cur = 0;
            for (int k = 0; i + k < n; k++) {
                const int x = i + k, y = k;
                cur += all[x][y];
            }
            answer = max(answer, cur);
        }

        for (int i = 0; i < n; i++) { // (0, x)
            long long cur = 0;
            for (int k = 0; i + k < n; k++) {
                const int x = k, y = i + k;
                cur += all[x][y];
            }
            answer = max(answer, cur);
        }

        printf("Case #%d: %lld\n", _, answer);
    }
    return 0;
}
