class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;
        s = preprocess(s);
        vector<int> f(s.size() + 2, 0);
        
        int center = 0, right = 0;
        int ans_c = 0, ans_r = 0;
        for (int i = 1; i < s.size(); i++) {
            int& r = f[i];
            
            if (right > i) r = min(right - i, f[2 * center - i]);
            while (i - r >= 0 && i + r < s.size() && s[i - r] == s[i + r]) r++;
            
            if (i + r > right) {
                center = i;
                right = i + r;
            }
            
            if (r - 1 > ans_r) {
                ans_r = r - 1;
                ans_c = i;
            }
        }

        string ans;
        for (int i = ans_c - ans_r; i <= ans_c + ans_r; i++) {
            if (s[i] != '#' && s[i] != '$') ans += s[i];
        }
        return ans;
    }
private:
    string preprocess(const string& str) {
        string ans = "$";
        for (char ch : str) {
            ans += ch;
            ans += "#";
        }
        return ans;
    }
};