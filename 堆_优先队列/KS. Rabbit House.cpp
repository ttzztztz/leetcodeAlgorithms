#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

typedef tuple<int, int, int> State;

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> arr[i][j];
        priority_queue<State, vector<State>, less<>> heap;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                heap.emplace(arr[i][j], i, j);
            }
        ll ans = 0;
        auto point_valid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        while (!heap.empty()) {
            auto[height, i, j] = heap.top();
            heap.pop();
            if (height != arr[i][j]) continue;

            for (int k = 0; k < 4; k++) {
                const int nx = i + dx[k], ny = j + dy[k];
                if (!point_valid(nx, ny)) continue;
                if (abs(arr[i][j] - arr[nx][ny]) <= 1) continue;

                const int t = (arr[i][j] - 1) - arr[nx][ny];
                arr[nx][ny] = arr[i][j] - 1;
                ans += t;
                heap.emplace(arr[nx][ny], nx, ny);
            }
        }
        printf("Case #%d: %lld\n", _, ans);
    }
    return 0;
}

