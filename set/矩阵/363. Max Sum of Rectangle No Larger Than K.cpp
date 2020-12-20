class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return 0;

        int ans = numeric_limits<int>::min();
        const int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                pref[i][j] = pref[i][j - 1] + matrix[i][j - 1];
            }
        }
        
        for (int i = 0; i <= m; i++) {
            for (int j = i + 1; j <= m; j++) {
                set<int> all = {0};
                
                int sum = 0;
                for (int l = 0, r = 0; r < n; r++) {
                    sum += pref[r][j] - pref[r][i];
                    
                    auto it = all.lower_bound(sum - k);
                    if (it != all.end()) {
                        if (sum - *it <= k) ans = max(ans, sum - *it);
                    }
                    if (it != all.begin()) {
                        it--;
                        if (sum - *it <= k) ans = max(ans, sum - *it);
                    }
                    
                    all.insert(sum);
                }
            }
        }
        
        
        return ans;
    }
};
