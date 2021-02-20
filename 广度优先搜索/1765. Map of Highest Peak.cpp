class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        const int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        typedef pair<int, int> PII;
        deque<PII> q;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (isWater[i][j]) {
                q.emplace_back(i, j);
                ans[i][j] = 0;
            }
        }
        
        int t = 0;
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        
        auto point_valid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };

        while (!q.empty()) {
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                auto [i, j] = q.front();
                q.pop_front();
                ans[i][j] = t;
                // cout << i << ", " << j << ", " << t << endl;
                
                for (int k = 0; k < 4; k++) {
                    const int nx = i + dx[k], ny = j + dy[k];
                    if (!point_valid(nx, ny) || ans[nx][ny] != -1) continue;
                    q.emplace_back(nx, ny);
                    ans[nx][ny] = t + 1;
                }
            }
            t++;
        }
        return ans;
    }
};
