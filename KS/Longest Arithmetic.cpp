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
        int answer = 0;
        int n;
        cin >> n;
        vector<int> all(n, 0);
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> all[i];
        }

        if (n == 2) {
            answer = 2;
        } else {
            dp[1] = 2;
            for (int i = 2; i < n; i++) {
                if (all[i] - all[i - 1] == all[i - 1] - all[i - 2]) {
                    dp[i] = dp[i - 1] + 1;
                    answer = max(answer, dp[i]);
                } else {
                    dp[i - 1] = 1;
                    dp[i] = 2;

                    answer = max(answer, dp[i]);
                }
            }
        }

        printf("Case #%d: %d\n", _, answer);
    }
    return 0;
}
