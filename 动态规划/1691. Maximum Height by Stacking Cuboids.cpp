class Solution {
public:
    int maxHeight(vector<vector<int>>& cub) {
        for (auto& v: cub) sort(v.begin(), v.end());
        sort(cub.begin(), cub.end());
        this->c = cub;
        
        const int n = cub.size();
        int ans = 0;
        memset(f, 0xff, sizeof f);
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i + 1, i) + cub[i][2]);
        }
        return ans;
    }
private:
    vector<vector<int>> c;
    int f[105][105];
    
    int dfs(int i, int last) {
        if (i >= c.size()) return 0;
        int& val = f[i][last];
        if (val != -1) return val;

        int ans = dfs(i + 1, last);
        if (c[last][1] <= c[i][1] && c[last][2] <= c[i][2]) {
            ans = max(ans, c[i][2] + dfs(i + 1, i));
        }
        return val = ans;
    }
};
