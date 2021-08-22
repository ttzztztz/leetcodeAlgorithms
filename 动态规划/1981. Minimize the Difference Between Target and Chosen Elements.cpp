int f[71][801];

class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        data = mat, t = target;
        n = mat.size(), m = mat[0].size();
        mi = vector<int>(n + 1, 0);
        
        mi[n - 1] = *min_element(data[n - 1].begin(), data[n - 1].end());
        for (int i = n - 2; i >= 0; i--) mi[i] = mi[i + 1] + *min_element(data[i].begin(), data[i].end());
        
        memset(f, 0xff, sizeof f);
        return dfs(0, target);
    }
private:
    vector<vector<int>> data;
    vector<int> mi;
    int t, n, m;
    
    int dfs(int i, int rest) {
        if (i == n) return abs(rest);
        if (rest < 0) return abs(rest) + mi[i];
        
        int& val = f[i][rest];
        if (val != -1) return val;
        
        int ans = 0x3f3f3f3f;
        for (int j = 0; j < m; j++) {
            ans = min(ans, dfs(i + 1, rest - data[i][j]));
        }
        return val = ans;
    }
};