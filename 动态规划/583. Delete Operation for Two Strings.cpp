class Solution {
public:
    int minDistance(string word1, string word2) {
        const int n = word1.size(), m = word2.size();
        vector<int> f(m + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            vector<int> g(m + 1, 0);
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    g[j] = f[j - 1] + 1;
                } else {
                    g[j] = max(f[j], g[j - 1]);
                }
            }
            f = g;
        }
        
        return n + m - 2 * f[m];
    }
};