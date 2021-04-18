class Solution {
public:
    int makeStringSorted(string s) {
        const int n = s.size();
        vector<ll> frac(n + 1, 1);
        
        for (int i = 1; i <= n; i++) {
            frac[i] = (frac[i - 1] * i) % mod;
        }
        vector<int> appear(26, 0);
        for (int i = 0; i < n; i++) appear[s[i] - 'a']++;
        
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll smaller = 0;
            for (int j = 0; j < s[i] - 'a'; j++) smaller += appear[j];
            
            ll all = 1;
            for (int i : appear) all = (all * frac[i]) % mod;
            
            ll cur = (smaller * frac[n - i - 1]) % mod;
            cur = (cur * inv(all)) % mod;
            ans = (ans + cur) % mod;
            
            appear[s[i] - 'a']--;
        }
        return ans;
    }
private:
    typedef long long ll;
    const int mod = 1e9+7;
    
    ll fast_pow(ll a, ll b) {
        ll ans = 1, base = a;
        while (b) {
            if (b & 1) {
                ans = (ans * base) % mod;
            }
            base = (base * base) % mod;
            b >>= 1;
        }
        return ans;
    }
    
    ll inv(ll a) {
        return fast_pow(a, mod - 2);
    }
};