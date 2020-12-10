class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        typedef pair<int, int> PII;
        
        const int n = mat.size(), m = mat[0].size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                if (mat[i][j] == 1) f[i][j] = f[i][j + 1] + 1;
                else f[i][j] = 0;
            }
        }
        
        int ans = 0;
        for (int j = 0; j < m; j++) {
            int cur = 0;
            
            vector<PII> stk;
            for (int i = 0; i < n; i++) {
                int width = 1;
                while (!stk.empty() && stk.back().first >= f[i][j]) {
                    auto [_len, _width] = stk.back();
                    stk.pop_back();
                    
                    width += _width;
                    cur -= _len * _width;
                }
                
                stk.emplace_back(f[i][j], width);
                cur += width * f[i][j];
                ans += cur;
            }
        }
        return ans;
    }
};