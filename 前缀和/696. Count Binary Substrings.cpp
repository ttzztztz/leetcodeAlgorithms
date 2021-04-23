class Solution {
public:
    int countBinarySubstrings(string s) {
        const int n = s.size();
        
        int cnt = 0, last = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (i != 0 && s[i - 1] != s[i]) {
                ans += min(last, cnt);
                last = cnt;
                cnt = 1;
            } else {
                cnt++;
            }
        }
        ans += min(last, cnt);
        return ans;
    }
};