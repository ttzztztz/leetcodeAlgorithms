class Solution {
public:
    int minimumLength(string s) {
        const int n = s.size();
        int l = 0, r = n - 1;
        
        while (l < r && s[l] == s[r]) {
            const char ch = s[l];
            while (l <= r && s[l] == ch) l++;
            while (l <= r && s[r] == ch) r--;
        }
        
        return r - l + 1;
    }
};
