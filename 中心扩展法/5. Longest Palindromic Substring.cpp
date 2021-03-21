class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        for (int i = 0; i < s.size(); i++) {
            int r = 0;
            while (i - r >= 0 && i + r < s.size()) {
                if (s[i - r] == s[i + r]) r++;
                else break;
            }
            
            r--;
            if (r >= 0 && 2 * r + 1 > ans.size()) {
                ans = s.substr(i - r, 2 * r + 1);
            }
        }
        
        for (int i = 0; i + 1 < s.size(); i++) {
            if (s[i] != s[i + 1]) continue;
            int r = 0;
            while (i - r >= 0 && i + 1 + r < s.size()) {
                if (s[i - r] == s[i + 1 + r]) r++;
                else break;
            }
            
            r--;
            if (r >= 0 && 2 * r + 2 > ans.size()) {
                ans = s.substr(i - r, 2 * r + 2);
            }
        }
        return ans;
    }
};