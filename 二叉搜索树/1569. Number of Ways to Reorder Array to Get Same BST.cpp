class Solution {
public:
    int numOfWays(vector<int>& nums) {
        memset(frac, 0, sizeof frac);
        frac[0] = inv[0] = 1;
        for (int i = 1; i <= 2000; i++) {
            frac[i] = (frac[i - 1] * i) % mod;
            inv[i] = fastPow(frac[i], mod - 2);
        }
        
        ll ans = dfs(nums);
        ans--;
        ans %= mod;
        return ans;
    }
private:
    typedef long long ll;
    const int mod = 1e9 + 7;

    ll dfs(const vector<int>& v) {
        ll ans = 1;
        if (v.empty()) return 1;
        vector<int> l, r;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] < v[0]) l.push_back(v[i]);
            else r.push_back(v[i]);
        }
        
        ans *= dfs(l);
        ans %= mod;
        ans *= dfs(r);
        ans %= mod;
        
        ans *= C(l.size() + r.size(), l.size());
        ans %= mod;
    
        return ans;
    }
    ll C(int a, int b) {
        ll ans = frac[a] * inv[b];
        ans %= mod;
        ans *= inv[a - b];
        ans %= mod;
        return ans;
    }
    ll frac[2005], inv[2005];
    ll fastPow(ll a, int b) {
        ll ans = 1, base = a;
        while (b) {
            if (b & 1) {
                ans *= base;
                ans %= mod;
            }
            
            base *= base;
            base %= mod;
            b >>= 1;
        }
        return ans;
    }
};