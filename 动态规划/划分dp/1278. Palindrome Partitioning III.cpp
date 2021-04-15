class Solution {
public:
    int palindromePartition(string s, int k) {
        const int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, 0));
        vector<int> f(k + 1, n + 10);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int cur = 0;
                int l = i, r = j;
                while (l < r) {
                    if (s[l] == s[r]) l++, r--;
                    else cur++, l++, r--;
                }
                cost[i][j] = cur;
            }
        }
        
        f[0] = 0;
        for (int i = n - 1; i >= 0; i--) {
            vector<int> g(k + 1, n + 10);
            for (int j = 0; j <= k; j++) {
                for (int m = i; m <= n - 1; m++) {
                    if (j - 1 >= 0) g[j] = min(f[i][j], cost[i][m] + f[m + 1][j - 1]);
                }
            }
            f = g;
        }
        return f[k];
    }
};