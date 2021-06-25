class Solution {
public:
    int numOfWays(vector<int>& nums) {
        init_frac();
        return (dfs(nums) - 1 + mod) % mod;
    }
private:
    typedef long long ll;
    const int mod = 1e9+7;
    ll frac[2001];
    
    ll dfs(const vector<int>& arr) {
        if (arr.empty()) return 1;
        
        const int t = arr[0];
        vector<int> l, r;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < t) l.push_back(arr[i]);
            else r.push_back(arr[i]); // arr[i] > t
        }
        const int n = l.size(), m = r.size();
        ll ans = (dfs(l) * dfs(r)) % mod;
        ans = (ans * C(n + m, m)) % mod;
        return ans;
    }
    
    ll C(int a, int b) {
        ll ans = (frac[a] * inverse(frac[b])) % mod;
        return (ans * inverse(frac[a - b])) % mod;
    }
    
    ll inverse(ll a) {
        return fast_pow(a, mod - 2);
    }
    
    ll fast_pow(ll a, int b) {
        ll ans = 1, cur = a;
        while (b) {
            if (b & 1) ans = (ans * cur) % mod;
            cur = (cur * cur) % mod;
            b >>= 1;
        }
        return ans;
    }
    
    void init_frac() {
        memset(frac, 0, sizeof frac);
        frac[0] = frac[1] = 1;
        for (int i = 2; i <= 2000; i++) {
            frac[i] = (1ll * frac[i - 1] * i) % mod;
        }
    }
};