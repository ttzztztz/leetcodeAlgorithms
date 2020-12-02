class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int n = A.size(), m = B.size();
        vector<int> f(m + 1, 0);
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            vector<int> g(m + 1, 0);
            const char c1 = A[i - 1];
            for (int j = 1; j <= m; j++) {
                const char c2 = B[j - 1];
                
                if (c1 == c2) {
                    g[j] = f[j - 1] + 1;
                }
                
                ans = max(ans, g[j]);
            }
            f = g;
        }
        return ans;
    }
};
