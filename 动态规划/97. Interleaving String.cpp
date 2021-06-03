class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        s1 += "a", s2 += "a", s3 += "aa";
        const int n = s1.size(), m = s2.size();
        if (n + m != s3.size()) return false;
        
        vector<int> f(m + 1, 0);
        f[m - 1] = 1;
        for (int i = n - 1; i >= 0; i--) {
            vector<int> g(m + 1, 0);
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s3[i + j]) g[j] |= f[j];
                if (s2[j] == s3[i + j]) g[j] |= g[j + 1];
            }
            f = g;
        }
        return f[0];
    }
};