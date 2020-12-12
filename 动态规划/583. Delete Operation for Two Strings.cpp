class Solution {
public:
    int minDistance(string word1, string word2) {
        const int n = word1.size(), m = word2.size();
        vector<int> f(m + 1, 0);

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            vector<int> g(m + 1, 0);
            const char ch1 = word1[i - 1];
            for (int j = 1; j <= m; j++) {
                const char ch2 = word2[j - 1];
                
                if (ch1 == ch2) g[j] = f[j - 1] + 1;
                else g[j] = max(g[j - 1], f[j]);
                
                ans = max(ans, g[j]);
            }
            f = g;
        }
        return n + m - ans * 2;
    }
};
