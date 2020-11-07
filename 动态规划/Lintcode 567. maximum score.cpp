class Solution {
public:
    /**
     * @param matrix: the matrix
     * @return: the maximum score you can get
     */
    int maximumScore(vector<vector<int>> &matrix) {
        memset(f, 0xff, sizeof f);
        this->m = matrix;
        
        ll ans = numeric_limits<ll>::min();
        for (int i = 0; i < matrix.size(); i++) {
            ans = max(ans, dfs(0, i));
        }
        return ans;
    }
private:
    typedef long long ll;
    ll f[105][105];
    vector<vector<int>> m;
    
    ll dfs(int i, int j) {
        if (i == m.size()) return 0;
        ll& val = f[i][j];
        if (val != -1) return val;
        
        ll ans = numeric_limits<ll>::min();
        for (int k = 0; k < m[0].size(); k++) {
            ans = max(ans, m[i][j] - abs(j - k) + dfs(i + 1, k));
        }
        return val = ans;
    }
};
