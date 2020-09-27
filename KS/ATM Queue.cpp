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
        int n, k;
        cin >> n >> k;

        vector<int> ans(n, 0);
        typedef pair<int, int> PII;
        set<PII> s;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            int a = t % k != 0;
            s.emplace(t / k + a, i);
        }

        int ord = 0;
        for (auto& p : s) {
            ans[ord] = p.second + 1;
            ord++;
        }

        printf("Case #%d:", _);
        for (int i = 0; i < n; i++) {
            printf(" %d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
