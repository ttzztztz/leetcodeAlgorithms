class Solution {
public:
    int minOperations(string s) {
        int cur = 0;
        for (int t = 0, i = 0; i < s.size(); i++, t ^= 1) {
            if (s[i] != '0' + t) cur++;
        }
        int ans = cur;
        cur = 0;
        
        for (int t = 1, i = 0; i < s.size(); i++, t ^= 1) {
            if (s[i] != '0' + t) cur++;
        }
        ans = min(ans, cur);
        return ans;
    }
};
