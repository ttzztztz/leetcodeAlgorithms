class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int ans = numeric_limits<int>::min();
        const int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> f(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (j == 0) f[i][j] = matrix[i][j];
            else f[i][j] = f[i][j - 1] + matrix[i][j];
        }
        
        for (int i = 0; i < m; i++) for (int j = i; j < m; j++) {
            set<int> t = {0};
            
            int sum = 0;
            for (int u = 0; u < n; u++) {
                sum += f[u][j] - (i - 1 >= 0 ? f[u][i - 1] : 0);
                auto it = t.lower_bound(sum - k);
                if (it != t.end()) {
                    ans = max(ans, sum - *it);
                }
                t.insert(sum);
            }
            
        }
        return ans;
    }
};