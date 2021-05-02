class Solution {
public:
    string replaceDigits(string s) {
        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) {
                ans += s[i];
            } else {
                ans += s[i - 1] + (s[i] - '0');
            }
        }
        return ans;
    }
};