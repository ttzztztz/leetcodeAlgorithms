class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int ans = 0;
        
        if (mat.empty()) return 0;
        const int n = mat.size(), m = mat[0].size();
        
        vector<vector<int>> f(n, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++) for (int j = m - 1; j >= 0; j--) {
            if (mat[i][j] == 1) {
                f[i][j] = f[i][j + 1] + 1;
            } else {
                f[i][j] = 0;
            }
        }
        
        for (int j = 0; j < m; j++) {
            vector<pair<int, int>> stk;
            int cur = 0;
            for (int i = 0; i < n; i++) {
                int cnt = 1;
                while (!stk.empty() && stk.back().first >= f[i][j]) {
                    auto[_len, _cnt] = stk.back();
                    stk.pop_back();
                    
                    cur -= _len * _cnt;
                    cnt += _cnt;
                }
                
                stk.emplace_back(f[i][j], cnt);
                cur += cnt * f[i][j];
                ans += cur;
            }
        }
        return ans;
    }
};