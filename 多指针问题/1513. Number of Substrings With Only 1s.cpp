class Solution {
public:
    int numSub(string s) {
        typedef long long ll;
        const int n = s.size(), mod = 1e9+7;
        
        ll ans = 0;
        for (int i = 0, cur = 0; i < n; i++) {
            if (s[i] == '1') {
                cur++;
                ans = (ans + cur) % mod;
            } else {
                cur = 0;
            }
        }
        return ans;
    }
};