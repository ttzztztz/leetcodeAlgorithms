class Solution {
public:
    int countHomogenous(string s) {
        typedef long long ll;
        ll ans = 0;
        const int mod = 1e9+7;
        vector<int> t;
        
        int last = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                last++;
            } else {
                t.push_back(last);
                last = 1;
            }
        }
        if (last > 0) t.push_back(last);
        
        for (int i : t) {
            ll tmp = 1ll * (i + 1) * i / 2;
            ans = (ans + tmp) % mod;
        }
        return ans;
    }
};
