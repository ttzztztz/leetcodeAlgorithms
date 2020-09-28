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

int n, m, k;
vector<int> target;
unordered_map<string, double> memo;

string h(const vector<int>& state) {
    string ans;
    for (int i : state) ans += to_string(i) + ",";
    return std::move(ans);
}

double dfs(vector<int>& state) {
    string h_state = h(state);
    if (memo.count(h_state)) return memo[h_state];
    double ans = 0.0;
    int sel = 0;

    for (int i = 0; i < m; i++) {
        int j = i;
        while (i + 1 < m && state[i + 1] == state[i]) i++;
        if (state[i] + 1 <= target[i]) {
            sel += i - j + 1;
            state[i]++;
            ans += (i - j + 1) * dfs(state);
            state[i]--;
        }
    }

    double e = 1.0 / sel * m;
    ans = ans / sel + e;
    return memo[h_state] = ans;
}

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        cin >> n >> m >> k;

        target = vector<int>(m, 0);
        memo.clear();
        for (int i = 0; i < k; i++) cin >> target[i];
        sort(target.begin(), target.end());
        memo[h(target)] = 0.0;

        vector<int> state(m, 0);
        double answer = dfs(state);

        printf("Case #%d: %lf\n", _, answer);
    }
    return 0;
}
