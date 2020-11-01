class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans = 0;
        const int n = s.size(), m = t.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i] == t[j]) continue;
                
                int len1 = 0, len2 = 0;
                while (i - len1 - 1 >= 0 && j - len1 - 1 >= 0) {
                    if (s[i - len1 - 1] == t[j - len1 - 1]) {
                        len1++;
                    } else break;
                }
                
                while (i + len2 + 1 < n && j + len2 + 1 < m) {
                    if (s[i + len2 + 1] == t[j + len2 + 1]) {
                        len2++;
                    } else break;
                }
                
                ans += (len1 + 1) * (len2 + 1);
            }
        }
        
        return ans;
    }
};
