class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int ans = 0;
        const int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> h(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') continue;
                if (i == 0) h[i][j] = 1;
                else h[i][j] = 1 + h[i - 1][j];
            }
        }
        
        for (int i = 0; i < n; i++) {
            vector<int> stk;
            vector<int> l(m, 0), r(m, 0);
            for (int j = 0; j < m; j++) {
                while (!stk.empty() && h[i][stk.back()] >= h[i][j]) stk.pop_back();
                
                if (stk.empty()) l[j] = -1;
                else l[j] = stk.back();
                
                stk.push_back(j);
            }
            
            stk.clear();
            for (int j = m - 1; j >= 0; j--) {
                while (!stk.empty() && h[i][stk.back()] >= h[i][j]) stk.pop_back();
                
                if (stk.empty()) r[j] = m;
                else r[j] = stk.back();
                
                stk.push_back(j);
            }
            
            for (int j = 0; j < m; j++) {
                ans = max(ans, h[i][j] * (r[j] - l[j] - 1));
            }
        }
        
        return ans;
    }
};
