class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        const int n = stones.size();
        
        int f[n + 1][n + 1][2];
        int pref[n + 1];
        memset(f, 0, sizeof f);
        memset(pref, 0, sizeof pref);
        
        for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + stones[i - 1];
        auto sum = [&](int i, int j) -> int {
            if (i > j) return 0;
            return pref[j + 1] - pref[i];
        };
        
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                const int j = i + len - 1;
                
                f[i][j][0] = numeric_limits<int>::min();
                f[i][j][1] = numeric_limits<int>::max();
                
                if (j - 1 >= 0) {
                    f[i][j][0] = max(f[i][j][0], f[i][j - 1][1] + sum(i, j - 1));
                    f[i][j][1] = min(f[i][j][1], f[i][j - 1][0] - sum(i, j - 1));
                }
                
                if (i + 1 < n) {
                    f[i][j][0] = max(f[i][j][0], f[i + 1][j][1] + sum(i + 1, j));
                    f[i][j][1] = min(f[i][j][1], f[i + 1][j][0] - sum(i + 1, j));
                }
            }
        }
        
        return f[0][n - 1][0];
    }
};