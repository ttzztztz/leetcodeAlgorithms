class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        memset(data, 0, sizeof data);
        ll ans = 0;
        for (int i : nums) inc(i, 1);
        
        unordered_map<int, ll> memo;
        for (int i : nums) {
            if (memo.count(i)) {
                ans = (ans + memo[i]) % mod;
            } else {
                ll cur = 0;
                for (ll x = 2; i * (x - 1) <= mx; x++) {
                    ll t = (mod + query(x * i - 1) - query(i * (x - 1) - 1)) % mod;
                    t = ((x - 1) * t) % mod;
                    cur = (cur + t) % mod;
                }
                
                memo[i] = cur;
                ans = (ans + cur) % mod;
            }
        }
        return ans;
    }
private:
    typedef long long ll;
    const int mod = 1e9+7, mx = 1e5+1;
    ll data[100005];
    
    int lowbit(int x) {
        return x&(-x);
    }
    ll query(int x) {
        x = min(x, mx);
        ll ans = 0;
        if (x <= 0) return ans;
        while (x) {
            ans += data[x];
            x -= lowbit(x);
        }
        return ans;
    }
    void inc(int x, int y) {
        while (x && x <= mx) {
            data[x] += y;
            x += lowbit(x);
        }
    }
};