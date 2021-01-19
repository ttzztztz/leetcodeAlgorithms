class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        const int n = s.size();
        vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));
        
        string ans = {s[0]};
        for (int i = 0; i < n; i++) f[i][i] = 1;
        for (int i = 0; i + 1 < n; i++) {
            if (s[i] == s[i + 1]) {
                f[i][i + 1] = 1;
                ans = s.substr(i, 2);
            }
        }
        
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                const int j = i + len - 1;
                
                if (s[i] == s[j]) {
                    f[i][j] = f[i + 1][j - 1];
                    
                    if (f[i][j] && len > ans.size()) {
                        ans = s.substr(i, len);
                    }
                }
            }
        }
        
        return ans;
    }
};
