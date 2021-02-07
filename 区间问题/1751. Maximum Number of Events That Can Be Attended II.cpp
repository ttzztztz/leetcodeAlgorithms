class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](const auto& $1, const auto& $2) -> bool {
            return $1[0] < $2[0];
        });

        n = events.size();
        for (int i = 0; i < n; i++) {
            const int e = events[i][1];
            
            nxt.push_back(lower_bound(events.begin(), events.end(), vector<int>{e + 1, 0, 0}) - events.begin());
            value.push_back(events[i][2]);
        }
        f = vector<vector<int>>(n + 1, vector<int>(k + 1, -1));
        return dfs(0, k);
    }
private:
    int n;
    vector<int> nxt, value;
    vector<vector<int>> f;
    
    int dfs(int i, int k) {
        if (i == n) return 0;
        int& val = f[i][k];
        if (val != -1) return val;
        int ans = 0;
        // not select
        ans = max(ans, dfs(i + 1, k));
        // select
        if (k >= 1) ans = max(ans, value[i] + dfs(nxt[i], k - 1));
        return val = ans;
    }
};
