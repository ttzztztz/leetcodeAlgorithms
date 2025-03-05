class Solution {
public:
    int maxPower(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int cur = 1;
            while (i + 1 < s.size() && s[i] == s[i + 1]) cur++, i++;
            ans = max(ans, cur);
        }
        return ans;
    }
};